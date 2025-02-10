# Snake Game (C++)

A simple implementation of the classic Snake game using C++ and a console-based interface. The snake moves around the screen, eats fruit to grow, and avoids colliding with the walls or itself.
Window OS used.
## Table of Contents
- [Project Description](#project-description)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Project Description
This is a console-based Snake game written in C++ that simulates the well-known game where the player controls a snake that moves around the screen. The goal is to collect fruit (denoted by `F`), causing the snake to grow in size while avoiding collisions with the screen boundaries or its own tail.

### Key Features:
- Simple console-based interface.
- Snake can move in four directions: left, right, up, and down.
- Fruit randomly appears on the screen.
- The game ends when the snake collides with a wall or itself.

## Installation
1. **`<iostream>`** – Used for input and output operations (printing to the console).
2. **`<vector>`** – Used to store the tail of the snake and manage dynamic arrays.
3. **`<deque>`** – Used for managing the snake’s tail more efficiently, allowing elements to be added to both ends.
4. **`<cstdlib>`** – Provides functions like `rand()` for generating random numbers (used for generating the fruit's position).
5. **`<ctime>`** – Used for seeding the random number generator using the current time.
6. **`<conio.h>`** – Provides functions like `_kbhit()` and `_getch()` for detecting user input without waiting for Enter (used to control snake movement).
7. **`<windows.h>`** – Used to control the sleep interval (game speed) and clear the console screen between frames (via the `Sleep()` function). 

To run the Snake game on your local machine, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/Code-Conquorers/snakegame.git
    ```

2. Navigate to the project directory:
    ```bash
    cd snake-game
    ```

3. Compile the C++ code:
    ```bash
    g++ snake.cpp -o snake.exe
    .\snake.exe
    ```

4. Run the game:
    ```bash
    ./snake
    ```

## Usage

1. **Start the game:** When you run the program, the snake will appear at the center of the screen, and you’ll be prompted with the current score.
2. **Move the snake:** Use the following keys to control the snake:
    - `W` - Move up
    - `A` - Move left
    - `S` - Move down
    - `D` - Move right
    - `X` - Quit the game
3. **Objective:** Eat the fruit (denoted by `F`) to grow longer and increase your score. Avoid colliding with the walls or the snake’s tail.

## Contributing

We welcome contributions to the Snake game! To contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch:
    ```bash
    git checkout -b feature-name
    ```
3. Make your changes and test them.
4. Commit your changes:
    ```bash
    git commit -am "Add new feature or fix bug"
    ```
5. Push to the branch:
    ```bash
    git push origin feature-name
    ```
6. Create a pull request.
- Easy-to-play mechanics.
- Randomized fruit positions.
- Snake grows with each fruit consumed.
- Simple console-based display.

