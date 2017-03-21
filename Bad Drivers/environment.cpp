#include "environment.h"

void Environment::Generate() {
	for (int y = 0; y < 18; y++) {
		for (int x = 0; x < 32; x++) {
			if (tileMap[y][x] == 0) { roadList.push_back(Road(Vector2(x * 40, y * 40), 40, 40)); }
			if (tileMap[y][x] == 1) { wallList.push_back(Wall(Vector2(x * 40, y * 40), 40, 40)); }
		}
	}
}

void Environment::Draw() {
	for (Road road : roadList) { road.Draw(); }
	for (Wall wall : wallList) { wall.Draw(); }
}