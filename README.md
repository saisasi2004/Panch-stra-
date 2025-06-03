# 🤖 Panchāstra – 5-Axis Robotic Arm Controller

**Panchāstra** is an open-source, web-based interface for controlling a 5-axis robotic arm. It features intuitive controls, inverse kinematics, 3D visualization, and motion sequence handling — all from your browser!

![Robotic Arm Model](./robot.png)

---

## ✨ Features

- 🎮 **Manual Motor Control** – Control Base, Shoulder, Elbow, Wrist (Pitch & Roll), and Gripper with sliders
- 🧠 **Inverse Kinematics** – Move the arm to a specified XYZ coordinate
- 🎥 **Live 3D Visualization** – See the arm animate in real-time using [Three.js](https://threejs.org)
- 💾 **Motion Sequencing** – Record, play, save, and load custom movements
- 🔌 **Web Serial Communication** – Interface directly with Arduino through USB
- 🌍 **Cross-Platform UI** – Runs on any modern browser, desktop or mobile

---

## 🎯 Ideal For

This project is a perfect portfolio addition for:

- 🤖 **Robotics Engineers** – Showcases servo control, kinematics, and real-world interfacing
- 🌐 **Web Developers** – Demonstrates real-time 3D rendering, UI/UX design, Web Serial API
- 🐍 **Python Developers** – Can extend using Python scripts, ROS bridges, or computer vision pipelines

**💡 Use it to boost your resume, impress recruiters, or as a practical project for university, hackathons, or job applications.**

---

## 📊 Comparison with Other Robotic Arm Controllers

| Feature / Tool            | Panchāstra 🌟      | Niryo Studio        | uArm Studio         | MyCobot Web         | ROS + Web Interface    |
|---------------------------|-------------------|---------------------|---------------------|---------------------|------------------------|
| **Open Source**           | ✅ Yes             | ❌ No               | ❌ No               | ❌ Limited          | ✅ Yes (but complex)   |
| **Web-Based UI**          | ✅ Fully Browser   | ❌ Desktop App      | ❌ Desktop App      | ✅ Partial           | ⚠️ Needs setup         |
| **Hardware Agnostic**     | ✅ Arduino + Servos| ❌ Niryo Only       | ❌ uArm Only        | ❌ MyCobot Only      | ✅ Customizable         |
| **3D Visualization**      | ✅ Three.js        | ✅ Basic             | ✅ Limited          | ✅ Yes               | ✅ Possible with effort |
| **Inverse Kinematics**    | ✅ Built-in        | ✅ Yes              | ❌ No               | ✅ Yes               | ✅ Possible             |
| **Motion Sequencing**     | ✅ Full Support    | ✅ Yes              | ✅ Yes              | ✅ Yes               | ✅ With scripting       |
| **Ease of Use**           | 🌟 Very Easy       | Moderate            | Moderate            | Moderate            | 🛠️ Developer-level     |
| **License Cost**          | Free & Open       | Paid Hardware       | Paid Hardware       | Paid Hardware       | Free & Open            |

---

## 🧰 Hardware Setup

- ✅ Arduino Uno (or compatible)
- ✅ 6x Servo Motors (5 for joints + 1 for gripper)
- ✅ Breadboard + Jumper Wires
- ✅ External Power Supply (for servo stability)
- ✅ USB cable for Arduino

---

## 🖼️ Visual Aids

### Mechanical Layout

![Robotic Arm Labelled](./Model%20Diagram.jpg)

### Wiring Diagram

![Circuit](./Circuit%20Diagram.jpg)

| Arduino Pin | Function              |
|-------------|-----------------------|
| D3          | Base Rotation         |
| D5          | Shoulder Joint        |
| D6          | Elbow Joint           |
| D9          | Wrist Roll            |
| D10         | Wrist Pitch           |
| D11         | Gripper               |

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- Chrome or Web Serial API-compatible browser

---

## 🚀 Getting Started

### 1. Upload Firmware

- Use `Robota.ino` for basic control
- Use `IK_Robota.ino` for inverse kinematics control
- Upload using Arduino IDE

### 2. Open Web Interface

- Open `index.html` in a supported browser (Chrome preferred)
- Select the COM port and connect to begin controlling the arm

---

## 🕹️ Controls

### 🔧 Manual Mode
- Adjust each joint angle via sliders
- Open/Close gripper using slider or buttons
- ## 🔧 Manual Control Demo

### 📐 Inverse Kinematics
- Input `X`, `Y`, `Z` target coordinates
- Or click inside the 3D view to pick a target
- Click “Move to Position” to execute IK
- ## 📐 Inverse Kinematics Demo

### 🔁 Motion Sequences
- Record current pose with “Record Position”
- Playback with “Play Sequence”
- Save and load sequences (JSON format)
- Use `E` key anytime to reset to a safe position
- ## 🔁 Motion Sequence Demo

---

## ⌨️ Keyboard Shortcuts

| Key / Combo   | Function             |
|---------------|----------------------|
| `Space`       | Toggle record mode   |
| `Ctrl + S`    | Save sequence        |
| `Ctrl + L`    | Load sequence        |
| `E`           | Emergency stop       |

---

## 📦 Files

| File                | Description                           |
|---------------------|---------------------------------------|
| `index.html`        | Web interface for arm control         |
| `Robota.ino`        | Basic motor control sketch            |
| `IK_Robota.ino`     | Inverse kinematics control sketch     |
| `Model Diagram.jpg` | 3D model layout                       |
| `Circuit Diagram.jpg` | Servo wiring diagram               |

---

## 🧱 3D Printable STL Files

You can download the STL files for the robotic arm from the following link:

👉 **[Download STL from Cults3D](https://cults3d.com/en/3d-model/various/arduino-based-robot-arm-howtomechatronics)**

**Credits**: 3D model designed by [How to Mechatronics](https://howtomechatronics.com/) – all mechanical design credit goes to them.

---

## 🙌 Contributing

This project is completely **open-source**. Feel free to fork, modify, and contribute:

- 🔧 Add new features (Bluetooth, camera tracking, etc.)
- 🧠 Improve inverse kinematics or motion logic
- 🎨 Refine UI or 3D interaction

---

## 🛡 License

This project is open-source and free to use for learning, hobby, and educational purposes. No formal license is applied.

---

Built with 💙 for roboticists, tinkerers, and makers by **Gampa Sai Sasivardhan**
