
#include "Player.h"
#include "Game.h"
Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 8));
	m_acceleration.setX(1);
	SDLGameObject::update();
}
void Player::clean()
{
}


