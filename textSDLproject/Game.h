
#include "SDL.h"
#include<SDL_image.h>
#include <iostream>
#include"TextureManager.h"
#ifndef __Game__
#define __Game__
class Game
{

private:
	Game() {};
	~Game() {};
	// create the s_pInstance member variable
	static Game* s_pInstance;
	

public:
	
	
	// simply set the running variable to true
	void init() { m_bRunning = true; }
	//void drawing();
	void render();
	void update();
	void handleEvents();
	void draw();
	void clean();
	// a function to access the private running variable 
	bool running() { return m_bRunning; }
	bool init(const char* title, int xpos, int ypos, int width, int
		height, int flags);
	

	SDL_Window* m_pWindow{};
	SDL_Renderer* m_pRenderer{};
	SDL_Renderer* getRenderer()  { return m_pRenderer; }

	


	int m_currentFrame;
	

	bool m_bRunning;
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}return s_pInstance;
	}

	





};
// create the typedef

typedef Game TheGame;

#endif /* defined(__Game__) */

