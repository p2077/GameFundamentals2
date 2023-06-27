#pragma once
#include <SDL.h>

class GameObject
{
public:
	GameObject(float x, float y, float w, float h, 
		       Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 0);
	void Draw(SDL_Renderer* pRenderer);
	void UpdatePositionX(float x);
	void UpdatePositionY(float y);
	SDL_FRect& GetTransform() { return m_Transform; }
private:
	SDL_FRect m_Transform;
	SDL_Color m_Color;
};

