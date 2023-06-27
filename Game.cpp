#include "Game.h"
#include <iostream>
#include "StateManager.h"
#include "States.h"

using namespace std;

Game::Game()
	: m_running{ false }
	, windowPtr{ NULL }
	, rendererPtr{ NULL }
	//, m_rectangleTransform{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, 100 }
	, m_keyStates{ NULL }
{
}
Game& Game::GetInstance()
{
	static Game* instancePtr = new Game();
	return *instancePtr;
}
int Game::Init(const char* title, int xPos, int yPos)
{
	cout << "Initializing SDL Engine..." << endl;

	// Call to SDL_Init(). This will initialize SDL and the video subsystem.
	int errorCode = SDL_Init(SDL_INIT_EVERYTHING);
	if (errorCode == 0)
		cout << "SDL_Init() succeeded." << endl;
	else
	{
		cout << "SDL_Init() failed. Error Code " << errorCode << ": " << SDL_GetError() << endl;
		system("pause");
		return errorCode;
	}

	// Attempt to create a maximized window that can be restored to a SCREEN_WIDTH*SCREEN_HEIGHT, centered window.
	windowPtr = SDL_CreateWindow("Spectrum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (windowPtr != NULL)
		cout << "SDL_CreateWindow() succeeded." << endl;
	else
	{
		cout << "SDL_CreateWindow() failed. Error Code " << errorCode << ": " << SDL_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	// Attempt to create a hardware-accelerated renderer for our window.
	rendererPtr = SDL_CreateRenderer(windowPtr, -1, SDL_RENDERER_ACCELERATED);
	if (rendererPtr != NULL)
		cout << "SDL_CreateRenderer() succeeded." << endl;
	else
	{
		cout << "SDL_CreateRenderer() failed. Error code " << errorCode << ": " << SDL_GetError() << endl;
		SDL_DestroyWindow(windowPtr);
		SDL_Quit();
		system("pause");
		return -1;
	}

	cout << "Initialization Successful!" << endl;
	StateManager::PushState(new TitleState());

	m_keyStates = SDL_GetKeyboardState(NULL);
	m_running = true;
	return 0;
}
bool Game::IsRunning()
{
	return m_running;
}
void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		}
	}
}
void Game::Update(float deltaTime)
{
	StateManager::Update(deltaTime);

	//if (KeyDown(SDL_SCANCODE_W))
	//	m_rectangleTransform.y -= RECTANGLE_SPEED * deltaTime;
	//if (KeyDown(SDL_SCANCODE_S))
	//	m_rectangleTransform.y += RECTANGLE_SPEED * deltaTime;
	//if (KeyDown(SDL_SCANCODE_A))
	//	m_rectangleTransform.x -= RECTANGLE_SPEED * deltaTime;
	//if (KeyDown(SDL_SCANCODE_D))
	//	m_rectangleTransform.x += RECTANGLE_SPEED * deltaTime;
}
void Game::Render()
{
	StateManager::Render();

	//SDL_SetRenderDrawColor(rendererPtr, 0, 125, 255, 255);
	//SDL_RenderClear(rendererPtr);

	// Any Drawing Here...
	/*SDL_Rect rectanglePlacement;
	rectanglePlacement.x = 20;
	rectanglePlacement.y = 40;
	rectanglePlacement.w = 60;
	rectanglePlacement.h = 80;*/

	/*SDL_SetRenderDrawColor(rendererPtr, 0, 0, 255, 255);
	SDL_RenderFillRectF(rendererPtr, &m_rectangleTransform);*/

	SDL_RenderPresent(rendererPtr); // Flip Buffer - Sends data to Window.
}
void Game::Clean()
{
	cout << "Cleaning Engine..." << endl;
	StateManager::Quit();
	SDL_DestroyRenderer(rendererPtr);
	SDL_DestroyWindow(windowPtr);
	SDL_Quit();

	delete this;
}
bool Game::KeyDown(SDL_Scancode key)
{
	if (m_keyStates)
	{
		return m_keyStates[key] == 1;
	}
	return false;
}

