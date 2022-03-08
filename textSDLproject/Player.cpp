#include <string>
#include "SDL.h"

#include "Player.h"
#include "InputHandler.h"
#include <iostream>
#include "Board.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{

	SDLGameObject::draw();
	
}
void Player::update()
{
	//handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	//SDLGameObject::update();
}



void Player::handleInput()
{
	
	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();
	m_position.setX(x);
	m_position.setY(y);
	return;
}

void Player::clean() {}
