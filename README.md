# O V E R T A L E 🌑

> "Deep beneath the surface... a dream never faded."

**Overtale** is a dark, narrative-driven text adventure game written in C. You play as a shapeless entity from the abyss who dreams of living among humans. To survive, you must maintain your disguise, manage your suspicion level, and make difficult moral choices. 

![Terminal Game](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)
![Language](https://img.shields.io/badge/Language-C-blue)

## 📖 About The Game

You have escaped the underground world by taking the form of a dog. You are adopted by a boy named **Dexter** and his father. However, the human world is not as peaceful as you imagined.

Your goal is simple: **Blend in.**
But every choice matters. The father is unstable, the boy is traumatized, and your true form is struggling to stay hidden.

### Game Mechanic
* **Suspicion Meter:** Every strange action increases your suspicion. If it gets too high, the humans will know you are not a dog.
* **Branching Storyline:** Your choices determine the fate of Dexter and his father.
* **Inventory System:** Choose the right items to gain trust.
* **Multiple Endings**

## 🎮 How to Play

1.  **Controls:** The game is played entirely with the keyboard.
    * Type numbers (e.g., `1`, `2`, `3`) to make choices.
    * Press `ENTER` to progress through dialogues.
2.  **Objective:** survive the days without filling up your **Suspicion Meter**.

## 🛠️ Installation & Build

### Prerequisites
You need a C Compiler (GCC) installed on your system (MinGW for Windows or build-essential for Linux).

### For Windows Users (Easy Way)
1.  Clone or download this repository.
2.  Double-click the **`build.bat`** file included in the folder.
3.  The game will compile and launch automatically.

### Manual Compilation (Command Line)
If you want to compile it manually via terminal:

```bash
gcc main.c util.c story.c -o overtale
./overtale
