#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include <vector>
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "SDLGameObject.h"
#include "Vector2D.h"
//#include "Board.h"

class GameObject;
class SDLGameObject;

class PlayState : public GameState 
{
public:
	
	virtual void update();
	virtual void render();
	virtual void handleState();
	
	virtual bool onEnter();
	virtual bool onExit();
	
	virtual std::string getStateID() const { return s_playID; }
	
	
	void turnTiger();
	void turnGoat();
	bool dontoverlap(int, int);
	void goatWin();
	void limitmoves(SDLGameObject*);

	bool killer(int, int);
	int x, y;

	void dynamiccasting();

	std::vector<SDLGameObject*>m_SDLgameObjectsTiger;
	std::vector<SDLGameObject*>m_SDLgameObjectsGoat;

	
private:
	
	

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;

	std::vector<SDLGameObject*>m_SDLgameObjects;


	

};

#endif // __PlayState__
