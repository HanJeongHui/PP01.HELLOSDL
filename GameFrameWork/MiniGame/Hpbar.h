#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"

class Hpbar : public SDLGameObject
{
public:
	Hpbar(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};