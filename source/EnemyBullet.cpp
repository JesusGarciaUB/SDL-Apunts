#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(SDL_Renderer* renderer, Vector2 pos, float velocityFactor)
	: GameObject(renderer, 7, 8, Vector2(33, 31)) {


	float speed = rand() % 360;
	float angle = rand() % 360;

	Vector2 bulletSpawn = pos + (Vector2(cos(angle), sin(angle)) * 22);
	position = bulletSpawn;

	velocity = Vector2(cos(speed), sin(speed)) * velocityFactor;
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.1f;
	angularDrag = 0.0f;

	accelerationFactor = 0.0f;					
	angularAccelerationFactor = 0.0f;				
	lifeTime = 0.6f;
}

void EnemyBullet::Update(float dt) {

	GameObject::Update(dt);
	UpdateLifetime(dt);
}

void EnemyBullet::UpdateLifetime(float dt) {

	lifeTime -= dt;

	if (lifeTime <= 0.0f)
		Destroy();
}

void EnemyBullet::Render(SDL_Renderer* renderer) {

	SDL_SetTextureColorMod(texture, 0xF9, 0x3C, 0x37);

	GameObject::Render(renderer);

}