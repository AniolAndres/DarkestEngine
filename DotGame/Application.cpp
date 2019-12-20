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

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->PreUpdate();
	}

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->Update();
	}

	for (std::vector<Module*>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
		(*it)->PostUpdate();
	}

	return UpdateState::UpdateContinue;
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
