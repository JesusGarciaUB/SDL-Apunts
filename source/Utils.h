#pragma once
#include "Vector2.h"
#include <stdlib.h>

#define GAME_WIDTH 500
#define GAME_HEIGHT 500

inline Vector2 CalculatePositionInRadius(float r) {
	Vector2 perimeterPosition;
	float angle = rand() % 360;
	angle *= M_PI / 180.f;
	perimeterPosition.x = cos(angle) * r;
	perimeterPosition.y = sin(angle) * r;
	return perimeterPosition;
}

inline float CalculateRadius(int width, int height) {
	//Calculate radius
	float a = (float)GAME_WIDTH / 2.f;
	a *= a;	//power of 2
	float b = (float)GAME_HEIGHT / 2.f;
	b *= b;

	float h = sqrt(a + b); //radius
	return h;
}

inline Vector2 ClampPositionToRectangle(Vector2 pos, float halfWidth, float halfHeight) {
	
	if (pos.y > halfHeight) pos.y = halfHeight;
	if (pos.x > halfWidth) pos.x = halfWidth;
	if (pos.y < -halfHeight) pos.y = -halfHeight;
	if (pos.x < -halfWidth) pos.x = -halfWidth;
	return pos;
}