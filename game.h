#pragma once

#include "template.h"

namespace Tmpl8 {

	class Surface;
	class Sprite;

class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }
private:
	Surface* screen = nullptr;
	Sprite* ball = nullptr;
	vec2 ballPos{ 100, 0 };
	vec2 ballVel{ 100, 0 };
	static const vec2 GRAVITY;
	static const vec2 BALL_RADIUS;
};

}; // namespace Tmpl8