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
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();

	void update();
	void handleEvents();
	void clean();
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	int F_currentFrame;
	//	TextureManager m_textureManager;
	//	SDL_Texture*m_pTexture;
	//	SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle; 
	//float speed;
	std::vector<GameObject*> m_gameObjects;
	GameObject* F_monster;
	GameObject* S_monster;
	bool m_bRunning;
};