#pragma once
#include <SDL.h>

class Game
{
private:
	Game(); //private constructor
public:
	static const int kWidth = 1024;
	static const int kHeight = 768;

	static Game& GetInstance();
	int Init(const char* title, int xPos, int yPos);
	bool IsRunning();
	void HandleEvents();
	bool KeyDown(SDL_Scancode key);
	void Update(float deltaTime);
	void Render();
	void Clean();

	SDL_Window* GetWindow() { return m_pWindow; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }

private:
	bool m_running;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	const Uint8* m_keyStates;
};