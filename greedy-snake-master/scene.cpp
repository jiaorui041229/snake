#include <iostream>
#include "scene.h"
#include "behavior.h"
#include "sceneControll.h"
#include "tools.h"
#include "gameInit.h"
#pragma region 添加物体

void scene::addBehavior(behavior* be)
{
	addBehaviors.emplace_back(be);
}


void scene::removeBehavior(behavior* be)
{
	//behaviors.remove(be);
	try
	{
		be->Destroy();
	}
	catch (const std::exception&)
	{

	}

	//delete be;

	delBehaviors.emplace_back(be);
}

behavior* scene::find(const char* p)
{
	for (auto& item : behaviors) {
		if (strcmp(typeid(item).name(), p)) {

			return item;
		}
	}

	return nullptr;
}


void scene::clear() {

	for (auto& item : behaviors)
	{
		item->Destroy();
		delBehaviors.emplace_back(item);
	}

	gameInit::clear();
}

#pragma endregion


#pragma region 主体循环

void scene::Start() {
	Init();


	for (auto& items : behaviors) {
		try
		{
			items->Start();
		}
		catch (const std::exception&)
		{

		}
	}
}

void scene::Loop(double time) {

	if (addBehaviors.size() > 0) {

		for (auto& item : addBehaviors) {

			item->Start();
			behaviors.emplace_back(item);
		}
		addBehaviors.clear();
	}

	for (auto& items : behaviors) {
		try
		{
			if (items)
				items->Loop(time);
		}
		catch (const std::exception&)
		{

		}
	}

	if (delBehaviors.size() > 0) {

		for (auto& items : delBehaviors)
		{

			behaviors.remove(items);
			delete items;
		}

		delBehaviors.clear();
	}

}

void scene::Destroy() {

	if (addBehaviors.size() > 0) {

		for (auto& item : addBehaviors) {

			item->Destroy();
			delete item;
		}
		addBehaviors.clear();
	}

	if (behaviors.size()) {
		for (auto& items : behaviors) {
			try
			{
				items->Destroy();


			}
			catch (const std::exception&)
			{

			}
			delete items;

		}
	}


	if (delBehaviors.size()) {
		for (auto& items : delBehaviors) {
			try
			{
				items->Destroy();
			}
			catch (const std::exception&)
			{

			}
			delete items;
		}
	}

	behaviors.clear();
	delBehaviors.clear();
}

void scene::Init()
{
}



#pragma endregion