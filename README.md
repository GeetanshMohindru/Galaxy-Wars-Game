# 🎮 Galaxy Wars - A Computer Graphics Project

**Galaxy Wars** is an arcade-style shooting game developed using **C++ with OpenGL and GLUT**. Players control a futuristic ship, shoot bullets, and destroy incoming enemies — including special *Trojan* enemies that require multiple hits and offer bonus points.

## 📸 Gameplay Screenshot
![Screenshot 2025-05-06 152006](https://github.com/user-attachments/assets/75e12cba-6d7b-4904-9e6f-ca673e38c437)



---

## 🚀 Game Features

- **Player Control**: Move left and right, shoot upward bullets.
- **Enemy Types**:
  - 🔴 **Normal Enemies**: Red, die in one hit, +1 point.
  - 🟣 **Trojan Enemies**: Purple, need 2 hits, blink on damage, +3 points.
- 💥 **Explosions**: Colorful visual effects on enemy destruction.
- 📊 **Score Tracking**: Real-time kill count display.
- 🗂️ **In-game Legend**: Shows controls and contributors.

---

## 🎮 Controls

| Key          | Action              |
|--------------|---------------------|
| ⬅️ / ➡️       | Move Ship Left/Right|
| `SPACE`      | Shoot Bullet        |
| `ESC`        | Exit Game           |

---

## 👨‍💻 Contributors

- **Geetansh Mohindru** (102203718)
- **Shrey Dhar Dubey** (102383011)

---

## 🧠 Technical Highlights

- **OpenGL (GLUT)** based rendering
- **Modular code structure** with structs for Bullet, Enemy, and Explosion
- **Real-time animation** using `glutTimerFunc()`
- **Collision detection** between bullets and enemies
- **Random enemy generation**
- **Trojan enemy logic**: blinking and split-hit mechanism

---

## 🔧 Compilation & Execution

### 🔽 Dependencies:
- OpenGL Utility Toolkit (GLUT)

### 🧪 Build Instructions:

#### On Windows:

```bash
g++ BlockBuster.cpp -o BlockBuster -lfreeglut -lopengl32 -lglu32
BlockBuster.exe
