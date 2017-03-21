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

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end()) { rotation += 75 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end()) { rotation -= 75 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_UP) != keyList.end()) { if (velocity < 250) { velocity += .5; } else { velocity = 250; } } else { velocity *= .995; }

	for (Wall wall : environment->wallList) {
		if (abs(wall.Center().x - Center().x) > abs(wall.Center().y - Center().y)) {
			if (wall.Center().x - Center().x > 0) { 
				if ((rotation > -90 && rotation < 90) || rotation < -270 || rotation > 270) {
					distance[2] = (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180);
				}
			}
			else { 
				if ((rotation > 90 && rotation < 270) || (rotation > -270 && rotation < -90)) {
					distance[2] = ((wall.position.x + wall.width) - Center().x) / cos((-rotation * M_PI) / 180);
				}
			}
		}
		else {
			if (wall.Center().y - Center().y > 0) { 
				if ((rotation > 180) || (rotation > -180 && rotation < 0)) {
					distance[2] = (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180);
				}
			}
			else { 
				if ((rotation > 0 && rotation < 180) || rotation < -180) {
					distance[2] = ((wall.position.y + wall.height) - Center().y) / sin((-rotation * M_PI) / 180);
				}
			}
		}
	}

	if (rotation >= 360) { rotation -= 360; }
	if (rotation <= -360) { rotation += 360; }

	position += (direction[2].Get() * deltaTimeS) * velocity;
}

void Agent::Draw() {
	DrawTriangle(position, width, height, rotation);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), Center() + direction[0].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), Center() + direction[1].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), Center() + direction[2].Get() * distance[2]);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), Center() + direction[3].Get() * 500);
	DrawLine(position.Get() + Vector2(width / 2, height / 2), Center() + direction[4].Get() * 500);
}