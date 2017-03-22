#pragma once
#include "vector2.h"
#include "spritebatch.h"
#include "input.h"
#include "environment.h"

class Agent {
	Environment* environment;

	Vector2 position, resetPosition, direction[5];
	double distance[5];
	int width = 25, height = 25;

	double velocity = 0;
	double rotation = 0;
public:
	Agent(Vector2 pos, Environment* env) {
		position = pos;
		resetPosition = pos;
		GetDirection();

		environment = env;
	}

	inline Vector2 Center() { return position.Get() + Vector2(width / 2, height / 2); }

	void GetDirection();
	void GetDistance();
	void Update(int deltaTime);
	void Draw();
};