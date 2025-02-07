# Flappy Bird Clone in C++ and SFML


This repository contains a **Flappy Bird clone** implemented in **C++** using the **SFML (Simple and Fast Multimedia Library)**. The game replicates the core mechanics of the original Flappy Bird, including bird movement, pipe generation, collision detection, and scoring.

---

## **Table of Contents**
1. [Features](#features)
2. [How I Created This](#how-i-created-this)
3. [What I Learned](#what-i-learned)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Dependencies](#dependencies)
8. [Contributing](#contributing)
9. [License](#license)

---

## **Features**
- **Bird Mechanics**:
  - The bird falls due to gravity and can jump when the spacebar is pressed.
  - The bird cannot go above the top of the window and dies if it touches the bottom.

- **Pipe Mechanics**:
  - Pipes spawn at random heights and move towards the bird.
  - The player scores points by successfully navigating through the pipes.

- **Dynamic Difficulty**:
  - The game speed increases over time, making it more challenging.

- **Game States**:
  - **Start Screen**: Displays instructions to begin the game.
  - **Gameplay Screen**: The main game screen where the player controls the bird.
  - **Game Over Screen**: Displays the final score and allows the player to restart.

- **Text Rendering**:
  - The game uses SFML's text rendering to display the score, start screen, and game over screen.
  - Texts are centered and have a glowing effect.

---

## **How I Created This**
1. **Setup**:
   - Installed **SFML** and **CMake** on Arch Linux.
   - Created a basic project structure with `CMakeLists.txt` for building the project.

2. **Game Loop**:
   - Implemented the game loop to handle events, update game logic, and render the game.

3. **Bird Mechanics**:
   - Created a `Bird` class to handle the bird's movement, gravity, and jumping.

4. **Pipe Mechanics**:
   - Created a `Pipe` class to handle pipe generation, movement, and collision detection.

5. **Collision Detection**:
   - Used SFML's `intersects()` method to detect collisions between the bird and pipes.

6. **Scoring System**:
   - Implemented a scoring system that increases as the player successfully navigates through pipes.

7. **Dynamic Difficulty**:
   - Added a `speedMultiplier` that increases over time, making the game more challenging.

8. **Game States**:
   - Implemented start, gameplay, and game over screens using SFML's text rendering.

9. **Hot Code Reloading**:
   - Used `entr` to automatically rebuild and restart the game when source files change.

10. **GitHub Integration**:
    - Initialized a Git repository, created a `.gitignore` file, and pushed the code to GitHub.

---

## **What I Learned**
- **SFML Basics**:
  - Learned how to use SFML for window management, rendering, and event handling.

- **Game Development**:
  - Gained a deeper understanding of game loops, game states, and object-oriented programming in game development.

- **Collision Detection**:
  - Implemented collision detection using bounding boxes.

- **Dynamic Difficulty**:
  - Learned how to gradually increase game difficulty by adjusting game parameters over time.

- **CMake**:
  - Gained experience in using CMake to build and manage C++ projects.

- **Git and GitHub**:
  - Improved my skills in version control and repository management.

---

## **Installation**
### **Prerequisites**
- **SFML**: Install SFML on your system.
  ```bash
   sudo pacman -S sfml 

- **CMake**: Install CMake for building the project
```bash
   sudo pacman -S cmake
```

## Build Instructions

### Clone the repository:
```bash
git clone https://github.com/AmanDhurwe/FlappyBird_Clone-in-c-and-sfml.git
```

### Create a build directory and compile the project:
```bash
mkdir build
cd build
cmake ..
make
```

### Run the game:
```bash
./FlappyBird
```

## Usage

- **Start Screen:** Press the spacebar to start the game.
- **Gameplay:** Use the spacebar to make the bird jump.
- **Game Over:** When the bird collides with a pipe or the ground, the game over screen is displayed. Press the spacebar to restart.

## Project Structure
```
FlappyBird/
├── CMakeLists.txt
├── include/
│   ├── Game.h
│   ├── Bird.h
│   ├── Pipe.h
│   ├── GameState.h
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Bird.cpp
│   ├── Pipe.cpp
├── build/
├── .gitignore
├── README.md
```

## Dependencies

- **SFML**
- **CMake**

## Contributing

Contributions are welcome! If you find any bugs or want to add new features, feel free to open an issue or submit a pull request.


## Acknowledgments

- Inspired by the original Flappy Bird game.
- Special thanks to the SFML community for their excellent documentation and tutorials.

## Screenshots


- **Start Screen**
![start screen](https://github.com/AmanDhurwe/FlappyBird_Clone-in-c-and-sfml/blob/main/start.png?raw=true) 

- **Gameplay**
![Game Play ](https://github.com/AmanDhurwe/FlappyBird_Clone-in-c-and-sfml/blob/main/playing.png?raw=true) 

- **Game Over**
![Game Over](https://github.com/AmanDhurwe/FlappyBird_Clone-in-c-and-sfml/blob/main/gameover.png?raw=true)

Enjoy the game! 🚀

