# Thread-Wars-Segfault
**Thread-Wars: Segfault** is a high-performance, multi-threaded combat simulation developed in C. It features autonomous AI robots represented by 3x3 ASCII sprites, fighting in real-time within a shared memory battlefield.

## 🚀 Project Overview

This project explores advanced system programming concepts, moving beyond simple loops to a fully concurrent architecture. Each robot is an independent POSIX thread, making split-second decisions while synchronizing its actions through mutexes and semaphores.

## 🛠 Technical Specifications

- **Concurrency:** Multi-threaded (pthreads) — separate threads for Robots, Graphics (ncurses), and Menu (Doom Fire Algorithm).
- **Synchronization:** Mutex-protected shared matrix (`mappa[20][50]`) and robot data arrays to prevent Race Conditions and Segmentation Faults.
- **Entity Physics:** 3x3 multi-cell ASCII sprites with AABB (Axis-Aligned Bounding Box) collision detection.
- **Rendering:** Non-blocking real-time UI using the `ncurses` library.

---

## ⚔️ Combatant Profiles

In our multi-threaded arena, 5 unique robots participate. Each is controlled by its own independent thread, has its own decision-making speed (via `usleep`), and features a unique behavioral algorithm.

---

### 1. Tank "Vanguard" (Symbol: `T`)

The absolute close-quarters juggernaut.

- **Health (HP):** 150 (Highest in the arena)
- **Speed:** Slow (Maximum `usleep` delay)
- **Strategy (AI):** A straightforward aggressor. It calculates the Manhattan distance to the nearest living enemy and takes a step directly toward them. If an enemy is in an adjacent cell, it delivers a crushing melee blow.

**ASCII Model (3x3):**

```text
[O]
|||
/ \
```

---

### 2. Sniper "Phantom" (Symbol: `S`)

Tactical long-range fighter.

- **Health (HP):** 80 (Fragile)
- **Speed:** Medium
- **Strategy (AI):** Avoids direct contact. It constantly scans a 5-cell radius. If an enemy gets too close, the Phantom turns and flees. Its goal is to align with an enemy on a single axis (X or Y) to perform a ranged laser attack.

**ASCII Model (3x3):**

```text
 ^ 
>|<
/ \
```

---

### 3. Berserker "Butcher" (Symbol: `B`)

An unpredictable killing machine.

- **Health (HP):** 100
- **Speed:** Very Fast (Minimum thread delay)
- **Strategy (AI):** Rushes around the map, attacking any nearby target. Unique mechanic: if its health drops below 30 HP, it enters **"Kamikaze" mode**. It stops using melee attacks, hunts down the robot with the highest HP, and self-destructs, dealing massive damage to both.

**ASCII Model (3x3):**

```text
\ /
[X]
/ \
```

---

### 4. Scavenger "Hoarder" (Symbol: `P`)

Pacifist and survival master.

- **Health (HP):** 100
- **Speed:** Fast
- **Strategy (AI):** Completely ignores other robots (never attacks first). Its algorithm is strictly focused on finding power-ups (health `+`, shields `S`). It constantly heals, hoping the others will destroy each other so it can remain the last survivor.

**ASCII Model (3x3):**

```text
 o 
~|~
/ \
```

---

### 5. Trapper "Miner" (Symbol: `M`)

Territory control specialist.

- **Health (HP):** 90
- **Speed:** Medium
- **Strategy (AI):** Avoids close combat, preferring to move erratically through empty matrix zones. Every few steps, it leaves a landmine (`M`) at its previous coordinates. Perfectly counters the aggressive Tank and Berserker, who will blindly chase it into traps.

**ASCII Model (3x3):**

```text
_-_
|M|
/ \
```