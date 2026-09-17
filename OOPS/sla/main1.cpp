#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>   // Standard library on Windows for _kbhit() and _getch()
#include <windows.h> // Required for smooth screen rendering without flashing

using namespace std;

// Game Configuration Constants
const int MAP_HEIGHT = 11;
const int MAP_WIDTH = 15;

// The layout map configuration: # = Wall, . = Open Path, E = Exit, P = Player Initial Position
const char INITIAL_MAP[MAP_HEIGHT][MAP_WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'P', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

class GameEngine
{
private:
    char maze[MAP_HEIGHT][MAP_WIDTH];
    int playerX, playerY;
    int movesCount;
    bool gameRunning;
    bool won;
    HANDLE hConsole; // Console handle for smart cursor manipulation

    // NEW VISIBILITY LOGIC: Reveals a 3x3 square (including diagonals) around the player
    bool isVisible(int r, int c)
    {
        int rowDiff = abs(r - playerY);
        int colDiff = abs(c - playerX);
        // True only if the block is at most 1 row away AND 1 column away
        return (rowDiff <= 1 && colDiff <= 1);
    }

    // Teleports the console cursor back to the top left corner to avoid screen clearing flicker
    void resetCursorPosition()
    {
        COORD cursorPosition;
        cursorPosition.X = 0;
        cursorPosition.Y = 0;
        SetConsoleCursorPosition(hConsole, cursorPosition);
    }

public:
    GameEngine()
    {
        movesCount = 0;
        gameRunning = true;
        won = false;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Hide the blinking console cursor for cleaner game visuals
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        // Initialize internal array state from static map configuration template
        for (int i = 0; i < MAP_HEIGHT; ++i)
        {
            for (int j = 0; j < MAP_WIDTH; ++j)
            {
                maze[i][j] = INITIAL_MAP[i][j];
                if (maze[i][j] == 'P')
                {
                    playerY = i;
                    playerX = j;
                    maze[i][j] = '.'; // Clear initial character spot to path floor asset
                }
            }
        }

        // Perform an initial regular clear once at launch
        std::system("cls");
    }

    void renderFrame()
    {
        resetCursorPosition();

        cout << "=========================================\n";
        cout << "        THE MIDNIGHT ESCAPE (C++)        \n";
        cout << "=========================================\n";
        cout << " Total Moves Taken: " << movesCount << "        \n";
        cout << " Controls: W (Up), A (Left), S (Down), D (Right) | X (Exit)\n";
        cout << "-----------------------------------------\n\n";

        for (int i = 0; i < MAP_HEIGHT; ++i)
        {
            cout << "   ";
            for (int j = 0; j < MAP_WIDTH; ++j)
            {
                if (i == playerY && j == playerX)
                {
                    cout << "P ";
                }
                else if (isVisible(i, j))
                {
                    cout << maze[i][j] << " ";
                }
                else
                {
                    cout << "  "; // Option B: Pure darkness
                }
            }
            cout << "\n";
        }
        cout << "\n=========================================\n";
    }

    void handleInput()
    {
        if (_kbhit())
        {
            char key = _getch();
            int targetX = playerX;
            int targetY = playerY;

            switch (key)
            {
            case 'w':
            case 'W':
                targetY--;
                break;
            case 's':
            case 'S':
                targetY++;
                break;
            case 'a':
            case 'A':
                targetX--;
                break;
            case 'd':
            case 'D':
                targetX++;
                break;
            case 'x':
            case 'X':
                gameRunning = false;
                return;
            default:
                return;
            }

            // Boundary collision physics detection filters
            if (targetY >= 0 && targetY < MAP_HEIGHT && targetX >= 0 && targetX < MAP_WIDTH)
            {
                if (maze[targetY][targetX] != '#')
                {
                    playerX = targetX;
                    playerY = targetY;
                    movesCount++;

                    if (maze[playerY][playerX] == 'E')
                    {
                        won = true;
                        gameRunning = false;
                    }
                }
            }
        }
    }

    void startLoop()
    {
        renderFrame();
        while (gameRunning)
        {
            if (_kbhit())
            {
                handleInput();
                renderFrame();
            }
        }

        // Restore the standard blinking text cursor when the game finishes
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        // Clear one final time to present clean completion splash screen
        std::system("cls");
        if (won)
        {
            cout << "\nCONGRATULATIONS! You reached the Exit 'E' in " << movesCount << " moves!\n\n";
        }
        else
        {
            cout << "\nGame session terminated successfully.\n\n";
        }
    }
};

int main()
{
    GameEngine game;
    game.startLoop();
    return 0;
}
