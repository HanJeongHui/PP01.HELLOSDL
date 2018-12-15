#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"

class Loding : public SDLGameObject
{
public:
	Loding(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};