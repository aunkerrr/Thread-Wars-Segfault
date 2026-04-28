# Thread-Wars-Segfault
**Core Crashers** is a high-performance, multi-threaded combat simulation developed in C.  It features autonomous AI robots represented by 3x3 ASCII sprites, fighting in real-time within a shared memory battlefield.

## 🚀 Project Overview
This project explores advanced system programming concepts, moving beyond simple loops to a fully concurrent architecture. 
Each robot is an independent POSIX thread, making split-second decisions while synchronizing its actions through mutexes and semaphores.

## 🛠 Technical Specifications
- **Concurrency:** Multi-threaded (pthreads) — separate threads for Robots, Graphics (ncurses), and World Events.
- **Synchronization:** Mutex-protected shared matrix (`mappa[20][50]`) and robot data arrays.
- **Entity Physics:** 3x3 multi-cell ASCII sprites with AABB (Axis-Aligned Bounding Box) collision detection.
- **Rendering:** Non-blocking real-time UI using the `ncurses` library.
