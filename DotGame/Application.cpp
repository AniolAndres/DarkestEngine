#include "pch.h"
#include "Application.h"

#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"

Application::Application()
{
}


Application::~Application()
{
}

bool Application::Init()
{
	//Create all modules and put them in the vector, order matters!

	modules.push_back(input = new ModuleInput());
	modules.push_back(window = new ModuleWindow());
	modules.push_back(render = new ModuleRender());

	bool result = true;

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		result = (*it)->Init();
	}

	return result;
}

bool Application::CleanUp()
{
	bool result = true;
	//We clean them backwards
	for (std::vector<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend(); ++it)
	{
		result = (*it)->CleanUp();
	}

	return result;
}
