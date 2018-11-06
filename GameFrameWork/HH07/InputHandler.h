#include <iostream>
#include <SDL.h>
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
class Vector2D;

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();
	void clean();

	
	Vector2D* getMousePosition();
	bool getMouseButtonState(int buttonNumber);

private:
	const Uint8* m_keystates;
	InputHandler();
	~InputHandler() {}
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	static InputHandler* s_pInstance;
	
};


typedef InputHandler TheInputHandler;