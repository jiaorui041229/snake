#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>


void displayText(const int x, const int y, const char* content, const bool select);
void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();

#endif // TOOLS_H