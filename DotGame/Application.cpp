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

UpdateState Application::Update()
{
	//Separating the update between three methods helps us diferentiate when each one is 
	//called regardless of the order the modules are in the vector

	UpdateState result = UpdateState::UpdateContinue;

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end() && result == UpdateState::UpdateContinue; ++it)
	{
		result = (*it)->PreUpdate();
	}

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end() && result == UpdateState::UpdateContinue; ++it)
	{
		result = (*it)->Update();
	}

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end() && result == UpdateState::UpdateContinue; ++it)
	{
		result = (*it)->PostUpdate();
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
