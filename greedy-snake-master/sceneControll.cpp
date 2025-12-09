#include <iostream>
#include <windows.h>
#include <conio.h>

#include "sceneControll.h"
#include "IView.h"
#include "gameInit.h"
#include "time.h"
#include "Input.h"
#include "tools.h"


using namespace std;


std::list<IView*> sceneControll::views;
std::list<IView*> sceneControll::delViews;

sceneControll::Enum_RunState sceneControll::runState = sceneControll::Enum_RunState::None;



sceneControll::sceneControll() {

	runState = Enum_RunState::None;
	startView();
	loopView();
}


#pragma region 静态的添加删除方法
/// <summary>
/// 添加视图
/// </summary>
/// <param name="view"></param>

void sceneControll::addView(IView* view) {

	views.emplace_back(view);

	if (runState == Enum_RunState::Loop)
		view->Start();
}

/// <summary>
/// 移除视图
/// </summary>
/// <param name="view"></param>
void sceneControll::removeView(IView* view) {

	delViews.emplace_back(view);

}

#pragma endregion


#pragma region 游戏内部循环方法

/// <summary>
/// 游戏初始化
/// </summary>
void sceneControll::startView() {

	runState = Enum_RunState::Init;
	int count = views.size();

	for (auto& item : views) {
		try
		{
			item->Start();
		}
		catch (const std::exception&)
		{

		}
	}
}

/// <summary>
/// 游戏循环
/// </summary>
void sceneControll::loopView() {
	gameInit::clear();

	LARGE_INTEGER t1, t2, tc;

	double frameRatio = 1.0 / gameInit::FrameRatio;

	QueryPerformanceFrequency(&tc);

	runState = Enum_RunState::Loop;
	//long runtime = frameRatio;

	time::deltatime = frameRatio;
	while (true)
	{
		QueryPerformanceCounter(&t1);

		if (_kbhit()) {
			Input::keyCode = _getch();
			if (Input::keyCode != Input::LastkeyCode) {
				Input::keyCodeDown = Input::keyCode;
			}
		}

		if (!views.size())
			break;

		for (auto& item : views) {
			try
			{
				item->Loop(time::deltatime);
			}
			catch (const std::exception& error)
			{
				std::cout << error.what() << std::endl;
			}
		}

		// 清除需要删除得 页面
		if (delViews.size() > 0) {

			for (auto& item : delViews) {
				try
				{
					item->Destroy();
				}
				catch (const std::exception&)
				{

				}

				views.remove(item);
				delete item;
			}

			delViews.clear();
		}

		Input::LastkeyCode = Input::keyCode;
		Input::keyCodeDown = 0;
		Input::keyCode = 0;

		QueryPerformanceCounter(&t2);
		time::deltatime = (long)(t2.QuadPart - t1.QuadPart) / (long)tc.QuadPart;

		if (time::deltatime < frameRatio) {
			Sleep((frameRatio - time::deltatime) * 1000);
			time::deltatime = frameRatio;
		}

		time::totalTime += time::deltatime;
	}

	gameInit::clear();
	runState = Enum_RunState::Quit;
	std::cout << "视图已全部关闭" << endl;
}
#pragma endregion


sceneControll::~sceneControll() {


	for (auto& item : views) {
		try
		{
			item->Destroy();
		}
		catch (const std::exception&)
		{

		}

		delete item;
	}


	for (auto& item : delViews) {
		try
		{
			item->Destroy();
		}
		catch (const std::exception&)
		{

		}
		delete item;
	}


	views.clear();
	delViews.clear();
}



//std::deque<IView*>  views;