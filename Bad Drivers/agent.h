#pragma once
#include "vector2.h"
#include "spritebatch.h"
#include "input.h"

class Agent {
	Vector2 position, direction[5];
	int width = 25, height = 25;

	double rotation = 0;
public:
	Agent(Vector2 pos) {
		position = pos;
		GetDirection();
	}

	void GetDirection();
	void Update(int deltaTime);
	void Draw();
};