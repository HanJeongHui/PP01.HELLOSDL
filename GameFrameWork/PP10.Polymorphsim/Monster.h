#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Monster : public GameObject
{
public:
	void drawFrame(SDL_Renderer* pRenderer);
	void update();
	void velocity(int vel);

private:
	const int turnCycle = 400;
	int dire;
	
};
