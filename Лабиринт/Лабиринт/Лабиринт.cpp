#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>


const int rows = 15;
const int cols = 30;

void generateMaze(char maze[rows][cols]) {
    // Заполнение лабиринта случайными символами - стенами (#) и проходами (.)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                maze[i][j] = '#'; // Границы лабиринта
            }
            else {
                if (rand() % 4 == 0) {
                    maze[i][j] = '#'; // Случайно создаем стену с вероятностью 1/4
                }
                else {
                    maze[i][j] = '.'; // Оставляем проход
                }
            }
        }
    }

    // Установка начальной и конечной точек в лабиринте
    maze[1][1] = '.';
    maze[rows - 2][cols - 2] = 'E'; // Обозначение выхода
}

void printMaze(char maze[rows][cols], int playerX, int playerY) {
    // Вывод лабиринта в консоль с отображением игрока
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == playerY && j == playerX) {
                std::cout << 'P' << " "; // Позиция игрока
            }
            else {
                std::cout << maze[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    char maze[rows][cols];
    int playerX = 1; // Начальное положение игрока по X
    int playerY = 1; // Начальное положение игрока по Y

    generateMaze(maze); // Генерация лабиринта

    while (true) {
        system("cls"); // Очистка консоли для обновления лабиринта

        printMaze(maze, playerX, playerY); // Вывод лабиринта с позицией игрока

        // Проверка на достижение выхода из лабиринта
        if (playerX == cols - 2 && playerY == rows - 2) {
            std::cout << "Congratulations! You have found a way out of the maze!" << std::endl;
            break;
        }

        // Получение ввода от пользователя для перемещения игрока
        char move = _getch(); // Получение символа без вывода в консоль (используется в Windows)

        switch (move) {
        case 'w':
            if (maze[playerY - 1][playerX] != '#') {
                playerY--;
            }
            break;
        case 's':
            if (maze[playerY + 1][playerX] != '#') {
                playerY++;
            }
            break;
        case 'a':
            if (maze[playerY][playerX - 1] != '#') {
                playerX--;
            }
            break;
        case 'd':
            if (maze[playerY][playerX + 1] != '#') {
                playerX++;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
