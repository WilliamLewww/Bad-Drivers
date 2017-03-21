#include "agent.h"

void Agent::GetDirection() {
	direction[0] = Vector2((float)cos(((-rotation - 60) * M_PI) / 180), sin(((-rotation - 60) * M_PI) / 180));
	direction[0].Normalize();

	direction[1] = Vector2((float)cos(((-rotation - 30) * M_PI) / 180), sin(((-rotation - 30) * M_PI) / 180));
	direction[1].Normalize();

	direction[2] = Vector2((float)cos((-rotation * M_PI) / 180), sin((-rotation * M_PI) / 180));
	direction[2].Normalize();

	direction[3] = Vector2((float)cos(((-rotation + 30) * M_PI) / 180), sin(((-rotation + 30) * M_PI) / 180));
	direction[3].Normalize();

	direction[4] = Vector2((float)cos(((-rotation + 60) * M_PI) / 180), sin(((-rotation + 60) * M_PI) / 180));
	direction[4].Normalize();
}

void Agent::Update(int deltaTime) {
	float deltaTimeS = (float)(deltaTime) / 1000;

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end()) { rotation += 50 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end()) { rotation -= 50 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_UP) != keyList.end()) { position += (direction[2].Get() * deltaTimeS) * 75; }
}

void Agent::Draw() {
	DrawTriangle(position, width, height, rotation);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), (position.Get() + Vector2(width / 2, height / 2)) + direction[0].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), (position.Get() + Vector2(width / 2, height / 2)) + direction[1].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), (position.Get() + Vector2(width / 2, height / 2)) + direction[2].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), (position.Get() + Vector2(width / 2, height / 2)) + direction[3].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), (position.Get() + Vector2(width / 2, height / 2)) + direction[4].Get() * 500);
}