#include "pch.h"
#include "SDL.h"
#include "Application.h"
#include <iostream>
#include "Globals.h"

Application* App = nullptr;

int main(int argc, char* argv[])
{

	int mainReturn = EXIT_FAILURE;
	MainStates mState = MainStates::Create;

	while (mState != MainStates::Exit)
	{
		switch (mState)
		{
		case MainStates::Create:
			//Create the application
			App = new Application();
			mState = MainStates::Init;
			break;
		case MainStates::Init:
			if (!App->Init())
			{
				mState = MainStates::Exit;
			}
			else
			{
				mState = MainStates::Update;
			}
			break;
		case MainStates::Update:
			break;
		case MainStates::Finish:
			break;
		}
	}

    
	return EXIT_SUCCESS;
}