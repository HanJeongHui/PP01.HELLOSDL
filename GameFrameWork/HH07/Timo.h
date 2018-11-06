#pragma once
#include <iostream>
#include "SDLGameObjcet.h"

class Timo : public SDLGameObject
{
private:
	void handleInput();
public:
	Timo(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

