#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer)
	: GameObject(renderer, 53, 30, Vector2(196, 96)) {

	float spawnRadius = CalculateRadius(GAME_WIDTH, GAME_HEIGHT);

	Vector2 perimeterPosition = CalculatePositionInRadius(spawnRadius);

	float halfHeight = GAME_HEIGHT / 2.0f + (float)radius;
	float halfWidth = GAME_WIDTH / 2.0f + (float)radius;

	perimeterPosition = ClampPositionToRectangle(perimeterPosition, halfWidth, halfHeight);

	position = perimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);
	rotation = -90.0f;
	scale = Vector2(1.0f, 1.0f);

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 0.0f;
	angularDrag = 0.0f;

	accelerationFactor = 0.0f;				
	angularAccelerationFactor = 0.0f;			

	canShoot = false;

	maxShotTime = 0.75f;
	lastShotTime = maxShotTime;

	changeDirectionTime = 0.0f;

	radius = CalculateRadius(width, height);

	score = 150;
}

void Enemy::Update(float dt) {
	GameObject::Update(dt);
	UpdateMovement(dt);
	UpdateShot(dt);
}

void Enemy::UpdateMovement(float dt) {

	GameObject::UpdateMovement(dt);

	changeDirectionTime += dt;

	if (changeDirectionTime >= 5.0f) {
		float newX = 20 - rand() % 41;
		float newY = 20 - rand() % 41;

		Vector2 newPosition = position + Vector2(newX, newY);
		velocity = (newPosition - position) * 2.5f;
		position = newPosition;


		changeDirectionTime = 0.0f;

	}

}

bool Enemy::BulletShooted() {
	if (canShoot) {

		lastShotTime = 0.0f;

		return true;
	}
		return false;
}

void Enemy::UpdateShot(float dt) {

	lastShotTime += dt;

	canShoot = lastShotTime >= maxShotTime;
}