#include <Servo.h>

Servo servos[6];

#define BASE_SERVO 0
#define SHOULDER_SERVO 1
#define ELBOW_SERVO 2
#define WRIST_PITCH_SERVO 3
#define WRIST_ROLL_SERVO 4
#define GRIPPER_SERVO 5

int servoPins[6] = {3, 5, 6, 10, 9, 11};
int currentAngles[6] = {90, 90, 90, 90, 90, 0};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(currentAngles[i]);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("M1:") && input.indexOf(',') != -1) {
      processCommand(input);
    }
  }
}

void processCommand(String command) {
  int startIndex = 0;
  int commaIndex;
  do {
    commaIndex = command.indexOf(',', startIndex);
    if (commaIndex == -1) commaIndex = command.length();
    String part = command.substring(startIndex, commaIndex);
    processServoCommand(part);
    startIndex = commaIndex + 1;
  } while (commaIndex < command.length());
}

void processServoCommand(String servoCommand) {
  int colonIndex = servoCommand.indexOf(':');
  if (colonIndex == -1) return;
  String servoStr = servoCommand.substring(0, colonIndex);
  String angleStr = servoCommand.substring(colonIndex + 1);
  int servoNum = -1;
  int angle = angleStr.toInt();

  if (servoStr == "M1") {
    servoNum = BASE_SERVO;
  } else if (servoStr == "M2") {
    servoNum = SHOULDER_SERVO;
  } else if (servoStr == "M3") {
    servoNum = ELBOW_SERVO;
  } else if (servoStr == "M4") {
    servoNum = WRIST_PITCH_SERVO;
  } else if (servoStr == "M5") {
    servoNum = WRIST_ROLL_SERVO;
  } else if (servoStr == "G") {
    servoNum = GRIPPER_SERVO;
  }

  if (servoNum != -1 && angle >= 0 && angle <= 180) {
    if (servoNum == GRIPPER_SERVO && angle > 90) angle = 90;
    servos[servoNum].write(angle);
    currentAngles[servoNum] = angle;
    Serial.print(servoStr);
    Serial.print(" set to ");
    Serial.print(angle);
    Serial.println("°");
  }
}
