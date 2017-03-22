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

void Agent::GetDistance() {
	for (int x = 0; x < 5; x++) { distance[x] = NULL; }

	for (Wall wall : environment->wallList) {
		if (abs(wall.Center().x - Center().x) > abs(wall.Center().y - Center().y)) {
			if (wall.Center().x - Center().x > 0) {
				if ((rotation > -90 && rotation < 90) || rotation < -270 || rotation > 270) {
					double tempDistance = (wall.Center().x - Center().x) / cos((-rotation * M_PI) / 180);
					if (Center().y < wall.Center().y) {
						if (Center().y + direction[2].Get().y * tempDistance > wall.Center().y) {
							if (Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
					}
					else {
						if (Center().y + direction[2].Get().y * tempDistance < wall.Center().y) {
							if (Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
					}
				}
			}
			else {
				if ((rotation > 90 && rotation < 270) || (rotation > -270 && rotation < -90)) {
					double tempDistance = (wall.Center().x - Center().x) / cos((-rotation * M_PI) / 180);
					if (Center().y > wall.Center().y) {
						if (Center().y + direction[2].Get().y * tempDistance > wall.Center().y) {
							if (Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
					}
					else {
						if (Center().y + direction[2].Get().y * tempDistance < wall.Center().y) {
							if (Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) > wall.position.y && Center().y + direction[2].Get().y * (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < wall.position.y + wall.height) {
								if (distance[2] == NULL || abs(wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.x + wall.width - Center().x) / cos((-rotation * M_PI) / 180);
								}
							}
						}
					}
				}
			}
		}
		else {
			if (wall.Center().y - Center().y > 0) {
				if ((rotation > 180) || (rotation > -180 && rotation < 0)) {
					double tempDistance = (wall.Center().y - Center().y) / sin((-rotation * M_PI) / 180);
					if (Center().x < wall.Center().x) {
						if (Center().x + direction[2].Get().x * tempDistance > wall.Center().x) {
							if (Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
					}
					else {
						if (Center().x + direction[2].Get().x * tempDistance > wall.Center().x) {
							if (Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
					}
				}
			}
			else {
				if ((rotation > 0 && rotation < 180) || rotation < -180) {
					double tempDistance = (wall.Center().y - Center().y) / sin((-rotation * M_PI) / 180);
					if (Center().x > wall.Center().x) {
						if (Center().x + direction[2].Get().x * tempDistance > wall.Center().x) {
							if (Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
					}
					else {
						if (Center().x + direction[2].Get().x * tempDistance < wall.Center().x) {
							if (Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
						else {
							if (Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) > wall.position.x && Center().x + direction[2].Get().x * (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < wall.position.x + wall.width) {
								if (distance[2] == NULL || abs(wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180) < abs(distance[2])) {
									distance[2] = (wall.position.y + wall.height - Center().y) / sin((-rotation * M_PI) / 180);
								}
							}
						}
					}
				}
			}
		}
	}
}

void Agent::Update(int deltaTime) {
	float deltaTimeS = (float)(deltaTime) / 1000;

	if (std::find(keyList.begin(), keyList.end(), SDLK_LEFT) != keyList.end()) { rotation += 75 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_RIGHT) != keyList.end()) { rotation -= 75 * deltaTimeS; GetDirection(); }
	if (std::find(keyList.begin(), keyList.end(), SDLK_UP) != keyList.end()) { if (velocity < 250) { velocity += .5; } else { velocity = 250; } } else { velocity *= .995; }

	if (rotation >= 360) { rotation -= 360; }
	if (rotation <= -360) { rotation += 360; }

	GetDistance();

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