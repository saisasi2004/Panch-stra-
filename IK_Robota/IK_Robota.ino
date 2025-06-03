#include <Servo.h>

// Robot arm dimensions (mm)
const float L1 = 200;   // Base to shoulder height
const float L2 = 100;   // Shoulder to elbow length
const float L3 = 50;    // Elbow to wrist length
const float L4 = 105;   // Wrist to gripper length

// Servo objects
Servo servo_base;       // Joint 1 (Base rotation)
Servo servo_shoulder;   // Joint 2 (Shoulder)
Servo servo_elbow;      // Joint 3 (Elbow)
Servo servo_wrist;      // Joint 4 (Wrist pitch)
Servo servo_wrist_rot;  // Joint 5 (Wrist rotation)
Servo servo_gripper;    // Gripper

// Servo pins (adjust to your wiring)
const int base_pin = 3;
const int shoulder_pin = 5;
const int elbow_pin = 6;
const int wrist_pin = 9;
const int wrist_rot_pin = 10;
const int gripper_pin = 11;

// Servo angle limits (degrees - adjust for your servos)
const int base_min = 0, base_max = 180;
const int shoulder_min = 15, shoulder_max = 165;
const int elbow_min = 0, elbow_max = 180;
const int wrist_min = 0, wrist_max = 180;
const int wrist_rot_min = 0, wrist_rot_max = 180;
const int gripper_min = 0, gripper_max = 90; // 0=open, 90=closed

void setup() {
  Serial.begin(9600);
  
  // Attach servos to pins
  servo_base.attach(base_pin);
  servo_shoulder.attach(shoulder_pin);
  servo_elbow.attach(elbow_pin);
  servo_wrist.attach(wrist_pin);
  servo_wrist_rot.attach(wrist_rot_pin);
  servo_gripper.attach(gripper_pin);
  
  // Move to initial position
  moveToPosition(150, 150, 150, 0); // x, y, z, gripper angle
  delay(1000);
}

void loop() {
  // Example movement sequence
  moveToPosition(200, 0, 150, 0);   // Move right
  delay(1000);
  moveToPosition(0, 200, 150, 30);   // Move left with tilted gripper
  delay(1000);
  moveToPosition(0, 0, 300, 0);     // Move up
  delay(1000);
  closeGripper();
  delay(1000);
  openGripper();
  delay(1000);
}

// Inverse kinematics solver
bool inverseKinematics(float x, float y, float z, float gripper_angle, float angles[5]) {
  // Calculate theta1 (base rotation)
  angles[0] = atan2(y, x);
  
  // Calculate wrist center position
  float wx = x - L4 * cos(gripper_angle) * cos(angles[0]);
  float wy = y - L4 * cos(gripper_angle) * sin(angles[0]);
  float wz = z - L4 * sin(gripper_angle);
  
  // Calculate theta2 and theta3 (shoulder and elbow)
  float r = sqrt(wx*wx + wy*wy);
  float h = wz - L1;
  float D = sqrt(r*r + h*h);
  
  // Check if position is reachable
  if (D > (L2 + L3) || D < abs(L2 - L3)) {
    return false; // Unreachable position
  }
  
  // Calculate angles using law of cosines
  float alpha = atan2(h, r);
  float beta = acos((L2*L2 + D*D - L3*L3) / (2 * L2 * D));
  float gamma = acos((L2*L2 + L3*L3 - D*D) / (2 * L2 * L3));
  
  angles[1] = alpha + beta;               // Shoulder
  angles[2] = gamma - PI;                 // Elbow
  angles[3] = gripper_angle - angles[1] - angles[2]; // Wrist
  angles[4] = 0;                          // Wrist rotation (fixed)
  
  return true;
}

// Move servos to position (x,y,z) with gripper angle
void moveToPosition(float x, float y, float z, float gripper_angle) {
  float angles[5];
  
  if (inverseKinematics(x, y, z, gripper_angle * DEG_TO_RAD, angles)) {
    // Convert radians to degrees and constrain to servo limits
    int base_angle = constrain(angles[0] * RAD_TO_DEG, base_min, base_max);
    int shoulder_angle = constrain(angles[1] * RAD_TO_DEG, shoulder_min, shoulder_max);
    int elbow_angle = constrain(angles[2] * RAD_TO_DEG, elbow_min, elbow_max);
    int wrist_angle = constrain(angles[3] * RAD_TO_DEG, wrist_min, wrist_max);
    int wrist_rot_angle = constrain(angles[4] * RAD_TO_DEG, wrist_rot_min, wrist_rot_max);
    
    // Move servos
    servo_base.write(base_angle);
    servo_shoulder.write(shoulder_angle);
    servo_elbow.write(elbow_angle);
    servo_wrist.write(wrist_angle);
    servo_wrist_rot.write(wrist_rot_angle);
    
    Serial.print("Moving to angles: ");
    Serial.print(base_angle); Serial.print(", ");
    Serial.print(shoulder_angle); Serial.print(", ");
    Serial.print(elbow_angle); Serial.print(", ");
    Serial.print(wrist_angle); Serial.print(", ");
    Serial.println(wrist_rot_angle);
  } else {
    Serial.println("Position unreachable!");
  }
}

void openGripper() {
  servo_gripper.write(gripper_max);
  Serial.println("Gripper opened");
}

void closeGripper() {
  servo_gripper.write(gripper_min);
  Serial.println("Gripper closed");
}