#include "game.h"
#include "surface.h"
#include <cstdio> //printf

namespace Tmpl8
{
	const vec2 Game::GRAVITY{ 0, 90.0f };
	const vec2 Game::BALL_RADIUS{ 25.0f, 25.0f };

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		ball = new Sprite(new Surface("assets/ball.png"), 1);
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		delete ball;
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// Convert to seconds...
		deltaTime /= 1000.0f;

		// Physics and Gameplay...
		ballVel += GRAVITY * deltaTime;

		ballPos += ballVel * deltaTime;

		if (ballPos.y  + BALL_RADIUS.y >= ScreenHeight)
		{
			ballPos.y =  (ScreenHeight - 1.0f) - BALL_RADIUS.y;
			ballVel.y *= -0.9f;
		}
		if (ballPos.x + BALL_RADIUS.x >= ScreenWidth)
		{
			ballPos.x = (ScreenWidth - 1.0f) - BALL_RADIUS.x;
			ballVel.x *= -0.9f;
		}

		// Render the game.
		// clear the graphics window
		screen->Clear(0);
		// print something in the graphics window

		ball->Draw(screen, ballPos.x - BALL_RADIUS.x, ballPos.y - BALL_RADIUS.y);
	}
};