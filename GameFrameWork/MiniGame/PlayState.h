#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include "Background.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	 const unsigned int Firerate = 500;
	 const unsigned int Firerate2 = 1000;
	 unsigned int Nextfire = 0;
	 unsigned int Nextfire2 = 0;
	 long hp = 50;
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;

};