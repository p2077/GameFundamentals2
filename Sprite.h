#pragma once
#include <SDL.h>

class Sprite
{
protected:
	SDL_Rect m_sourceTransfrom;
	SDL_FRect m_destinationTransfrom;
	int m_angle;

public:
	Sprite();
	Sprite(SDL_Rect sourceTransform, SDL_FRect destinationTransfrom, int angle);
	SDL_Rect& GetSourceTransform() { return m_sourceTransfrom; }
	SDL_FRect& GetDestinationTransform() { return m_destinationTransfrom; }
	int GetAngle() { return m_angle; }
};

