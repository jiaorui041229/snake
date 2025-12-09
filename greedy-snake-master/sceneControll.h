#pragma once
#include <list>
#include "IView.h"

using namespace std;



// 静态的视图控制器
class sceneControll
{



public:
	enum  Enum_RunState
	{
		None,
		Init,
		Loop,
		Quit,
	};


	sceneControll();
	~sceneControll();





public:
	/// <summary>
	/// 注册视图
	/// </summary>
	static void addView(IView* view);
	/// <summary>
	/// 移除视图
	/// </summary>
	static void removeView(IView* view);




private:

	void startView();
	void loopView();

private:
	static std::list<IView*>  views;

	static std::list<IView*>  delViews;
	/// <summary>
	/// 主循环运行状态
	/// </summary>
	static sceneControll::Enum_RunState runState;



};