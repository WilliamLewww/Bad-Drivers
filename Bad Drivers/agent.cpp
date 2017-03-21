#include "agent.h"

void Agent::Update(int deltaTime) {
	float deltaTimeS = (float)(deltaTime) / 1000;

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end()) {
		rotation += 50 * deltaTimeS;
	}

	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end()) {
		rotation -= 50 * deltaTimeS;
	}

	if (std::find(keyList.begin(), keyList.end(), SDLK_UP) != keyList.end()) {
		Vector2 direction = Vector2((float)cos((-rotation * M_PI) / 180), sin((-rotation * M_PI) / 180));
		direction.Normalize();
		position += (direction * deltaTimeS) * 75;
	}
}

void Agent::Draw() {
	DrawTriangle(position, width, height, rotation);
}