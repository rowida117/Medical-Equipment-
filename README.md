# 🩺 Medical Equipment Tasks

This repository contains projects and tasks developed for the **Medical Equipment** course. Each task focuses on applying electronics, programming, biomedical modeling, and intelligent systems to simulate or process medical signals and data.

---

## ✅ Task 1: ECG Graph Simulation using Arduino & Python

### 📌 Overview
This project simulates a real-time ECG-like waveform using a **pulse sensor** connected to an **Arduino Uno**. Data is sent over a serial connection and visualized in Python using `matplotlib`. The script also estimates heart rate (BPM) and mimics specific heart rhythms like **Ventricular Tachycardia**.

### ⚙️ Hardware Components
- Arduino Uno  
- Pulse Sensor (e.g., PulseSensor Amped or KY-039)  
- USB Cable  
- Computer with Python installed

### 💻 Software Requirements
```bash
pip install pyserial matplotlib numpy
```

### ▶️ How to Run
Upload pulse-reading Arduino code, connect Arduino, then:
```bash
python ecg.py
```

### 📂 File
- `ecg.py` – ECG simulation and visualization code.

---

## ✅ Task 2: Smart Infant Incubator System

### 📌 Overview
A miniature smart incubator using Arduino that monitors and controls temperature and humidity for neonatal safety.

### ⚙️ Features
- Temp & humidity monitoring  
- Fan and heater automation  
- Real-time LCD display  
- Alarm system for unsafe conditions

### 🔌 Components
- DHT11/DHT22 Sensor  
- LCD 16x2 Display  
- Relay modules  
- Fan, Heater  
- Buzzer  
- Arduino Uno

### 📂 File
- `incubatorr.ino` – Arduino sketch with hardware logic and comments.

---

## ✅ Task 3: Infusion Pump System

### 📌 Overview
A simulated **volumetric infusion pump** that delivers fluid based on user settings, with safety checks and real-time display.

### ⚙️ Features
- Button-based control  
- Volume flow logic  
- Buzzer alerts & safety handling  
- LCD interface

### 📂 File
- `sketch_feb26a_copy_20250319194623.ino` – Infusion pump simulation sketch.

---

## ✅ Task 4: Hemodialysis Machine Simulation

### 📌 Overview
Simulates basic functions of a **hemodialysis machine**: managing fluid movement, pressure monitoring, and user interface alerts.

### ⚙️ Features
- Simulated flow and balance control  
- Safety alert system  
- LCD and button interface

### 📂 File
- `sketch_jun15a.ino` – Hemodialysis Arduino simulation code.

---

## ✅ Task 5: Endoscopy Project (3D + AI)

### 📌 Overview
This task includes two parts:
1. A **3D design of an endoscope** created using Blender to visualize the structure and functionality of the instrument.
2. An **AI classification model** built using Python for recognizing endoscopic images into diagnostic categories.

---

### 🧱 Part 1: 3D Endoscope Model (Blender)
- The 3D model represents a simplified version of an endoscope, including the flexible tube, control section, and insertion tip.
- Designed in **Blender**, the model is suitable for educational use, simulation, and animation.

📂 File:
- `Untitled.blend` – Blender file with full endoscope model.

---

### 🤖 Part 2: AI Image Classification (Jupyter Notebook)
- The model uses a **Convolutional Neural Network (CNN)** to classify endoscopic images (e.g., normal vs abnormal).
- Built using Keras/TensorFlow in a Jupyter Notebook.
- Includes dataset loading, preprocessing, model building, training, and evaluation.

📂 File:
- `Aimodel.ipynb` – Notebook for training and evaluating the image classifier.

---

## 📌 General Notes
- All systems are simplified, educational prototypes.
- Hardware tasks use Arduino Uno and basic sensors/modules.
- Software tasks use open-source tools (Python, Blender, Jupyter).

