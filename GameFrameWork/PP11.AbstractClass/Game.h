#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"

class GameObject;
class Monster;
using namespace std;
class Game
{
private:
	Game();
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef
	typedef Game TheGame;
public:

	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	std::vector<GameObject*> m_gameObjects;
	void update();
	void handleEvents();
	void clean();
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	int F_currentFrame;
	
	std::vector<GameObject*> gameObjects;
	Monster* F_monster;
	Monster* S_monster;
	bool m_bRunning;
};
typedef Game TheGame;