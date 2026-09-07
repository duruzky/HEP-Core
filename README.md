# HEP-Core (High-Energy Physics Core) 

Personal Note: I am developing this project to improve myself and prepare for my 3rd semester in Computer Engineering. My goal is to combine two fields I really love: physics and software.
# HEP-Core (High-Energy Physics Core)

A professional-grade 3D physics simulation engine built in modern C++ to model particle kinematics, magnetic field interactions, and dynamic event management.

## Version 2.0 - Core Architecture Updates

This project demonstrates advanced C++ paradigms and object-oriented design principles:

* **Polymorphism & Inheritance:** Implemented a base `Particle` class with derived `Electron` and `Proton` classes, overriding virtual methods for specific particle behaviors.
* **Advanced Memory Management:** Transitioned to dynamic pointer arrays (`Particle**`) within the `Event` class to prevent **object slicing**, ensure polymorphic behavior, and manage heap memory safely without leaks.
* **Linear Algebra & Physics Engine:** Built custom `Matrix` and `Vector` composition for 3D spatial transformations, successfully applying Z-axis rotation matrices to simulate magnetic field deflections.
* **Encapsulation:** Strict access control (`protected` and `private` members) to maintain data integrity across the simulation lifecycle.

## Technical Stack
* **Language:** C++
* **Concepts:** OOP, Pointers, Constructor Chaining, Dynamic Memory Allocation, File I/O.

## Next Steps (Roadmap)
* Implementation of advanced data structures for faster particle querying.
* Algorithmic optimization for energy-based particle sorting.

## 💻 How to Run (macOS)
Open your terminal in the project directory and run the following commands:

```bash
clang++ main.cpp -o HEP-Core
./HEP-Core
