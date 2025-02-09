#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <conio.h>   
#include <windows.h> 

using namespace std;

bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score;
deque<pair<int, int>> tail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void generateFruit() {
    while (true) {
        fruitX = rand() % width;
        fruitY = rand() % height;
        bool overlap = (x == fruitX && y == fruitY);
        
        for (const auto &segment : tail) {
            if (segment.first == fruitX && segment.second == fruitY) {
                overlap = true;
                break;
            }
        }
        
        if (!overlap) break;
    }
}


void setup() {
    gameOver = false;
    dir = RIGHT;
    x = width / 2;
    y = height / 2;
    score = 0;
    tail.clear();
    generateFruit();
}

void draw() {
    system("cls");  

    for (int i = 0; i < width + 2; i++) cout << "*";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "*";

            if (i == y && j == x) cout << "O";
                       else if (i == fruitY && j == fruitX) cout << "F"; 
            else {
                bool isTail = false;
                for (const auto &segment : tail) {
                    if (segment.first == j && segment.second == i) {
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }
                if (!isTail) cout << " ";
            }

            if (j == width - 1) cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "*";
    cout << endl;

    cout << "Score: " << score << endl;
}

void input() {
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

void logic() {
    pair<int, int> prev = {x, y};
    
    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

        if (x < 0 || x >= width || y < 0 || y >= height) {
        gameOver = true;
        return;
    }

        for (const auto &segment : tail) {
        if (segment.first == x && segment.second == y) {
            gameOver = true;
            return;
        }
    }

        if (!tail.empty()) {
        tail.pop_back();
        tail.push_front(prev);
    }

        if (x == fruitX && y == fruitY) {
        score += 10;
        generateFruit();
        tail.push_front(prev); 
    }
}

int main() {
    srand(time(0));
    setup();

    constexpr int FRAME_RATE = 100;  
        while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(FRAME_RATE); 
    }

    cout << "Game Over!" << endl;
    return 0;
}
