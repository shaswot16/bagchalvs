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
	void turnTiger(SDLGameObject* , SDLGameObject* , SDLGameObject* , SDLGameObject* ,SDLGameObject* ,  SDLGameObject*,
		           SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, 
					SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*,
					SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*, SDLGameObject*);
	
	void turnGoat(SDLGameObject* goat1);
	int x, y;
	
private:
	
	
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;

	

};

#endif // __PlayState__
