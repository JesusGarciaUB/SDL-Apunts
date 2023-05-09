#include "Bullet.h"

Bullet::Bullet(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, float tud) : GameObject(rend, 9, 9, Vector2(33, 32)) {
	position = pos;
	rotation = rot;
	scale = scl;
	TimeUntilDeath = tud;
	currentTime = 0;

	velocity = Vector2();
	angularVelocity = 0.0f;

	angularAcceleration = 0.0f;

	linearDrag = 0;
	angularDrag = 6.f;

	accelerationFactor = 500.f;
	angularAccelerationFactor = 100000.f;

	Vector2 dir;
	float rotationInRadians = rotation * (M_PI / 180.f);
	dir.x = cos(rotationInRadians);
	dir.y = sin(rotationInRadians);

	velocity = dir * accelerationFactor;
}

void Bullet::DestroyOnLeave() {
	currentTime += frameTime;
	if (currentTime >= TimeUntilDeath) Destroy();
}