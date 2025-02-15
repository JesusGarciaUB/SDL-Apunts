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
	float a = (float)width / 2.f;
	a *= a;	//power of 2
	float b = (float)height / 2.f;
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

inline bool CheckColision(Vector2 posA, float radiusA, Vector2 posB, float radiusB) {
	Vector2 sToA = posA - posB;
	float distanceSquare = sToA.x * sToA.x + sToA.y * sToA.y;
	float radiusSum = radiusA * 0.7f + radiusB * 0.7f;
	radiusSum *= radiusSum;
	
	return distanceSquare < radiusSum;
}

inline bool CheckPointInsideCenteredRectangle(Vector2 point, Vector2 rectCenter, int w, int h) {
	float distX = abs(point.x - rectCenter.x);
	float distY = abs(point.y - rectCenter.y);

	bool insideX = distX < (float)w / 2.0f;
	bool insideY = distY < (float)h / 2.0f;

	return insideX && insideY;
}