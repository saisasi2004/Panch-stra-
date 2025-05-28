# 🤖 Panchāstra — 5-Axis Robotic Arm Controller

**Panchāstra** is a powerful and elegant web-based interface for controlling a 5-axis robotic arm. Designed for intuitive use and visually striking interaction, this controller allows users to manage each motor joint, perform inverse kinematics, visualize real-time arm motion, and orchestrate complex movement sequences with ease.

![Panchastra Interface Screenshot](preview.png)

---

## 🚀 Features

- 🎮 **Interactive UI** with sliders and buttons to control base, shoulder, elbow, wrist, and gripper
- 🧠 **Inverse Kinematics** to move the arm to 3D target positions via input or visualization picking
- 🔄 **360° Visualization** powered by `Three.js` with smooth camera rotation
- 📹 **Motion Sequences**: Record, play, save, and load arm motion sequences
- 🔌 **COM Port Integration**: Simulated and real serial port support (via Web Serial API)
- 🛑 **Emergency Stop** with a single key press (`E`)
- 🧭 **Real-Time Feedback** of the end effector's 3D coordinates
- 💡 **Built-in Help Dialog** for user guidance

---

## 🧰 Technologies Used

- **HTML5 / CSS3** – Modern responsive layout with Orbitron-styled futuristic theme
- **JavaScript (ES6+)** – Core logic and interactivity
- **Three.js** – 3D visualization of the robotic arm
- **dat.GUI** – Optional developer UI for debugging or controlling IK
- **Web Serial API** – Hardware-level communication (if available)

---

## 📦 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/panchastra.git
cd panchastra
