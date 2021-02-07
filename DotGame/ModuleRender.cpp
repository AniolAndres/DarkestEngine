#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"

#include "SDL.h"
#include <assert.h>
#include "Math/float3.h"
#include "GL/glew.h"

ModuleRender::ModuleRender()
{
}


ModuleRender::~ModuleRender()
{
}

bool ModuleRender::Init()
{
	bool result = true;
	

	Uint32 flags = 0;

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == nullptr)
	{
		assert(renderer != nullptr); //Renderer could not be created
		result = false;
	}

	CreateTriangle();


	return result;
}

UpdateState ModuleRender::PreUpdate()
{
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
	//SDL_RenderClear(renderer);
	return UpdateState::UpdateContinue;
}

UpdateState ModuleRender::PostUpdate()
{

	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);

	SDL_GL_SwapWindow(App->window->window);

	return UpdateState::UpdateContinue;
}

bool ModuleRender::CleanUp()
{
	//Destroy window
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}
	return true;
}

void ModuleRender::CreateTriangle()
{

}
