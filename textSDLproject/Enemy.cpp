#include <string>
#include "SDL.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "Board.h"
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {
	
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{  
	
	m_currentFrame = int(((SDL_GetTicks() / 100)%1 ));
	
	
}

void Enemy::handleInput() {
	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();
	m_position.setX(x);
	m_position.setY(y);
	return;
}


void Enemy::clean() {}
