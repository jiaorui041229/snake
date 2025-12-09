#pragma once
class Input
{

public:

	enum enum_KeyCode
	{
		Arrow_Down = 80,
		Arrow_Up = 72,
		Arrow_Left = 75,
		Arrow_Right = 77,
		ESC = 27,
		Enter=13,

	};

	static int LastkeyCode;
	static int keyCode;
	static int keyCodeDown;
};

