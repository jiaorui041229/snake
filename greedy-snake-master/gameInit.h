#pragma once

/// <summary>
/// 游戏初始类
/// </summary>
class gameInit
{
public:
	void Start();

public:

	static void clear();
	/// <summary>
/// 宽度
/// </summary>
	static int Width;
	/// <summary>
	/// 高度
	/// </summary>
	static int Height;
	/// <summary>
	/// 帧率
	/// </summary>
	static int FrameRatio;
};

