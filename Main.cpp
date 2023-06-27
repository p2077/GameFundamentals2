#include <iostream>
#include <SDL.h>
#include <chrono>
#include "Game.h"
#include "states.h"
#include "StateManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	Game& myGameInstance = Game::GetInstance();
	int result = myGameInstance.Init("Spectrum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	if (result == 0)
	{
		// Allocate a time_point outside that loop so that it is retained between frames.
		auto lastFrameTime = chrono::high_resolution_clock::now();

		while (Game::GetInstance().IsRunning())
		{
			// Get current time_point.
			auto thisFrameTime = chrono::high_resolution_clock::now();

			// Subtract last frame's time_point from this frame's time_point to get the duration of the frame.
			chrono::duration<float> lastFrameDuration = thisFrameTime - lastFrameTime;

			// Convert the duration to a float.
			float deltaTime = lastFrameDuration.count();

			// Don't forget to pass newFrameCounter into lastFrameCounter.
			lastFrameTime = thisFrameTime;

			myGameInstance.HandleEvents();
			myGameInstance.Update(deltaTime);
			myGameInstance.Render();
		}
		myGameInstance.Clean();
	}

	return 0;
}