# HEP-Core (High-Energy Physics Core) 

Personal Note: I am developing this project to improve myself and prepare for my 3rd semester in Computer Engineering. My goal is to combine two fields I really love: physics and software.
**HEP-Core** is a lightweight, high-performance C++ library built from scratch to simulate the fundamental data structures and algorithmic processing required in high-energy physics experiments (such as particle collisions).

This project is actively developed to demonstrate core computer engineering principles, focusing on raw memory management, object-oriented design, and algorithmic efficiency without relying on high-level external libraries.

## Current Features (v0.2 - Data Ingestion)
* **File I/O Integration:** Parsing external simulation datasets (`data.txt`) using the `fstream` library to dynamically populate the Event memory.
* **Particle & Event Modeling:** Custom classes to represent physical collision events and individual particle properties (3D spatial coordinates and energy levels).
* **Dynamic Memory Management:** Raw pointer manipulation and custom destructors (`new` / `delete`) to ensure zero memory leaks.
* **Algorithmic Sorting:** Custom in-place sorting algorithms to filter and rank particles based on their energy values.

## Technology Stack
* **Language:** C++ (C++17 standard)
* **Architecture:** Object-Oriented Programming (OOP)
* **Key Concepts:** Dynamic Memory Allocation, File I/O, Pointer Arithmetic, Asymptotic Analysis.

## Roadmap (Upcoming Features)
- [x] **Large-scale File I/O:** Parsing massive datasets simulating millions of particle hits.
- [x] **Linear Algebra Engine:** Custom `Matrix` and `Vector` classes for 3D kinematic transformations.
- [ ] **Track Reconstruction:** Implementing Graph algorithms (BFS/DFS) to trace and identify particle paths.
- [ ] **Optimization & Profiling:** Transitioning to advanced sorting algorithms and measuring RAM/CPU execution times.

## How to Compile and Run
This project is compiled using `clang++` and is compatible with macOS/Linux Unix environments.

```bash
clang++ main.cpp -o main
./main
