#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	GameObject m_go;
	Player m_player;
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	//	TextureManager m_textureManager;
	//	SDL_Texture*m_pTexture;
	//	SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle; 
	//float speed;

	bool m_bRunning;
};