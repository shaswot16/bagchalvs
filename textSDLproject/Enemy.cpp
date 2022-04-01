#include <string>
#include "SDL.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "Board.h"
#include<iostream>
#include "PlayState.h"
#include "Game.h"


//extern int gameTurn;

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
	gameTurn++;
}


void Enemy::clean() {}
