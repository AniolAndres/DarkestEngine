#include "ModuleGraphics.h"

#include "GL/glew.h"
#include "SDL.h"

#include "Application.h"
#include "ModuleWindow.h"

#include <assert.h>
ModuleGraphics::ModuleGraphics()
{
}

ModuleGraphics::~ModuleGraphics()
{
}

bool ModuleGraphics::Init()
{
	GLenum err = glewInit();

	glClearColor(0.3f, 0.3f, 0.3f, 1.f);

	if (GLEW_OK != err)
	{
		assert(0);
	}

	return true;
}

UpdateState ModuleGraphics::PreUpdate()
{
	return UpdateState::UpdateContinue;
}

UpdateState ModuleGraphics::PostUpdate()
{

	return UpdateState::UpdateContinue;
}

bool ModuleGraphics::CleanUp()
{
	return true;
}
