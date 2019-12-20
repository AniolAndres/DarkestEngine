#ifndef APPLICATION_H
#define APPLICATION_H

#include "Globals.h"
#include "Module.h"
#include <vector>

class ModuleWindow;
class ModuleRender;
class ModuleInput;


class Application
{
public:
	Application();
	~Application();

	bool Init();
	bool CleanUp();

public:
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;

private:
	std::vector<Module*> modules;
};

#endif // APPLICATION_H