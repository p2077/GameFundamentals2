#pragma once
#include <SDL.h>
#include <iostream>

class Game
{
private:
	static const int SCREEN_WIDTH = 1024;
	static const int SCREEN_HEIGHT = 768;
	//static const int RECTANGLE_SPEED = 600;

	Game();

public:
	static Game& GetInstance();
	int Init(const char* title, int xPos, int yPos);
	bool IsRunning();
	void HandleEvents();
	void Update(float deltaTime);
	void Render();
	void Clean();
	bool KeyDown(SDL_Scancode key);


	SDL_Window* GetWindow()
	{
		return windowPtr;
	}
	SDL_Renderer* GetRenderer()
	{
		return rendererPtr;
	}
private:
	bool m_running;
	SDL_Window* windowPtr;
	SDL_Renderer* rendererPtr;

	//SDL_FRect m_rectangleTransform;
	const Uint8* m_keyStates;
};
