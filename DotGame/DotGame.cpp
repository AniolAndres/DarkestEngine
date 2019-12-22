#include "Application.h"
#include "Globals.h"
#include <iostream>

#include "SDL.h"
#include <assert.h>

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
			{
				UpdateState updateStatus = UpdateState::UpdateContinue;

				if (App->Update() != UpdateState::UpdateContinue)
				{
					mState = MainStates::Finish;
				}
				else
				{
					mState = MainStates::Update;
				}

				break;
			}
		case MainStates::Finish:
			if (!App->CleanUp())
			{
				assert(0); //Exiting with error at cleanUp
			}
			else
			{
				mainReturn = EXIT_SUCCESS;
			}

			mState = MainStates::Exit;
			break;
		}
	}

	delete App;
	App = nullptr;
    
	return mainReturn;
}