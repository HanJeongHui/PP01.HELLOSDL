#include "GameState.h"


class GameObject;

class WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_winID; }
	static WinState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new WinState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_winID;
	std::vector<GameObject*> m_gameObjects;
	static WinState* s_pInstance;
};