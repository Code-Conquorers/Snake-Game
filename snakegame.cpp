#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 50;
const int height = 20;

struct Position {
    int x, y;
    
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

class SnakeGame {
public:
    SnakeGame();
    void setup();
    void draw();
    void input();
    void logic();
    void run();
    void restart();  

private:
    bool gameOver;
    int score;
    Position head;
    Position fruit;
    deque<Position> tail;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN } dir;

    void generateFruit();
    void gotoxy(int x, int y);  
    void clearScreen(); // Function to clear the screen
};

SnakeGame::SnakeGame() {
    setup();
}

void SnakeGame::setup() {
    gameOver = false;
    dir = RIGHT;
    head = Position(width / 2, height / 2);
    score = 0;
    tail.clear();
    generateFruit();
}

void SnakeGame::generateFruit() {
    while (true) {
        fruit = Position(rand() % width, rand() % height);
        bool overlap = (head.x == fruit.x && head.y == fruit.y);

        for (const auto &segment : tail) {
            if (segment.x == fruit.x && segment.y == fruit.y) {
                overlap = true;
                break;
            }
        }

        if (!overlap) break;
    }
}

void SnakeGame::gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SnakeGame::draw() {
    // Set the cursor position to top-left corner before drawing
    gotoxy(0, 0);

    // Draw top border
    for (int i = 0; i < width + 2; i++) cout << "*";
    cout << endl;

    // Draw game body
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "*";  // Left wall

            if (i == head.y && j == head.x) cout << "O";  // Snake's head
            else if (i == fruit.y && j == fruit.x) cout << "F";  // Fruit
            else {
                bool isTail = false;
                for (const auto &segment : tail) {
                    if (segment.x == j && segment.y == i) {
                        cout << "o";  // Snake's tail
                        isTail = true;
                        break;
                    }
                }
                if (!isTail) cout << " ";  // Empty space
            }

            if (j == width - 1) cout << "*";  // Right wall
        }
        cout << endl;
    }

    // Draw bottom border
    for (int i = 0; i < width + 2; i++) cout << "*";
    cout << endl;

    cout << "Score: " << score << endl;
}

void SnakeGame::input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void SnakeGame::logic() {
    Position prev = head;

    switch (dir) {
        case LEFT: head.x--; break;
        case RIGHT: head.x++; break;
        case UP: head.y--; break;
        case DOWN: head.y++; break;
        default: break;
    }

    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
        gameOver = true;
        return;
    }

    for (const auto &segment : tail) {
        if (segment.x == head.x && segment.y == head.y) {
            gameOver = true;
            return;
        }
    }

    if (!tail.empty()) {
        tail.pop_back();
        tail.push_front(prev);
    }

    if (head.x == fruit.x && head.y == fruit.y) {
        score += 10;
        generateFruit();
        tail.push_front(prev);
    }
}

void SnakeGame::restart() {
    cout << "Do you want to restart? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        setup(); 
        run(); 
    } else {
        gameOver = true; 
    }
}

void SnakeGame::run() {
    constexpr int FRAME_RATE = 100;
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(FRAME_RATE);
    }

    cout << "Game Over!" << endl;
    restart(); 
}

int main() {
    srand(time(0));
    SnakeGame game;
    game.run();
    return 0;
}
