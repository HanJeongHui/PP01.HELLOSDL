#pragma once
#include <iostream>
#include "SDLGameObjcet.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void HandleInput();
};