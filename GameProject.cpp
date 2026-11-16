#include<iostream>
#include<windows.h>
#include "myconsole.h"
#include "mygraphics.h"
using namespace std;
int main() {
    int x = 200, y = 200;
    const int SIZE = 30, SPEED = 10;
    bool running = true;

    while (running) {
        // 1. Erase old position (slightly bigger to cover the outline)
        myRect(x - 3, y - 3, x + SIZE + 3, y + SIZE + 3, RGB(0, 0, 0), RGB(0, 0, 0));

        // 2. Input
        int key = CheckKeyPressed(20);

        // 3. Update
        if (key == LEFTKEY)  x -= SPEED;
        if (key == RIGHTKEY) x += SPEED;
        if (key == UPKEY)    y -= SPEED;
        if (key == DOWNKEY)  y += SPEED;
        if (key == ESCKEY)   running = false;

        // Keep inside the screen
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        // 4. Draw
        myRect(x, y, x + SIZE, y + SIZE, RGB(255, 255, 255), RGB(255, 0, 0));

        // 5. Delay
        Sleep(100);
    }
    return 0;
}