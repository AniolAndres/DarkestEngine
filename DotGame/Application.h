#ifndef APPLICATION_H
#define APPLICATION_H

#include "Globals.h"
#include "Module.h"
#include <vector>

class ModuleWindow;
class ModuleRender;
class ModuleInput;
class ModuleTextures;


class Application
{
public:
	Application();
	~Application();

	bool Init();

	UpdateState Update();

	bool CleanUp();

public:
	ModuleWindow* window = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;

private:
	std::vector<Module*> modules;
};

extern Application* App;

#endif // APPLICATION_H