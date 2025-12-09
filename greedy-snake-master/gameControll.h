#pragma once
#include <iostream>
#include <string>

// ÓÎÏ·¿ØÖÆÆ÷ ¾²Ì¬Àà
class gameControll
{

public:
	enum gameModel
	{
		None = 0,
		Jd,
		Pt,
		Kn,
		Ly
	};
	enum gameState
	{
		Run,
		Pause,
		Fail,
	};

	//string gameState;


public:
	static int score;
	static gameControll::gameModel model;
	static gameControll::gameState state;



};

