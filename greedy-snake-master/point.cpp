#include "point.h"
#include "tools.h"
#include <iostream>
#include "gameInit.h"

void Point::Print()//输出方块
{
	if ((x >= 0 && x < gameInit::Width) &&
		(y >= 0 && y < gameInit::Height))
	{
		SetCursorPosition(x, y);
		std::cout << "■";
	}	
}

void Point::PrintCircular(bool ishead)//输出圆形
{
	if ((x >= 0 && x < gameInit::Width) &&
		(y >= 0 && y < gameInit::Height))
	{
		if (ishead) {
			SetColor(15);
		}
		else {
			SetColor(14);
		}
		
		SetCursorPosition(x, y);
		std::cout << "●";
	}	
}

void Point::Clear()//清除输出
{

	if ((x >= 0 && x < gameInit::Width) &&
		(y >= 0 && y < gameInit::Height)) {

		SetCursorPosition(x, y);
		std::cout << "  ";
	}
}

void Point::ChangePosition(const int x, const int y)//改变坐标
{
	this->x = x;
	this->y = y;
}