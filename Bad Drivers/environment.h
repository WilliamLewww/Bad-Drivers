#pragma once
#include <vector>
#include "vector2.h"
#include "spritebatch.h"

struct Road {
	Vector2 position;
	int width, height;

	double color[3] = { 100, 100, 100 };
	Road(Vector2 pos, int w, int h) {
		position = pos;
		width = w;
		height = h;
	}

	inline void Draw() { DrawRect(position, width, height, color); }
};

struct Wall {
	Vector2 position;
	int width, height;

	double color[3] = { 0, 0, 0 };

	Wall(Vector2 pos, int w, int h) {
		position = pos;
		width = w;
		height = h;
	}

	inline void Draw() { DrawRect(position, width, height, color); }
};

class Environment {
	std::vector<Road> roadList;
	std::vector<Wall> wallList;

	std::vector<std::vector<int>> tileMap;
public:
	Environment(int) {
		SetTileMap();
		Generate();
	}

	void SetTileMap();
	void Generate();
	void Draw();
};