#include <SDL.h>
#include <SDL_opengl.h>
#include "input.h"
#include "global.h"
#include "environment.h"
#include "agent.h"

void Update(int);
void Render(SDL_Window*, SDL_GLContext);

SDL_Event event;
SDL_GLContext context;
SDL_Window* displayWindow;

Environment environment(0);
Agent agent(Vector2(100, 100), &environment);

bool isRunning = true;
int frameStart, frameEnd, deltaTime = 0;
int main(int argc, char *argv[]) {
	displayWindow = SDL_CreateWindow("Bad Drivers", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(displayWindow);
	glOrtho(-SCREENWIDTH / 2, SCREENWIDTH / 2, SCREENHEIGHT / 2, -SCREENHEIGHT / 2, 0, 1);

	while (isRunning) {
		RemoveInitialPress();
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				isRunning = false;

			GetKeys(event);
		}

		if (deltaTime < 1 / 60) {
			frameStart = SDL_GetTicks();
			SDL_Delay(1);
			frameEnd = SDL_GetTicks();
			deltaTime = frameEnd - frameStart;
		}
		frameStart = SDL_GetTicks();
		Update(deltaTime);
		Render(displayWindow, context);
		frameEnd = SDL_GetTicks();
		deltaTime = frameEnd - frameStart;
	}

	return 0;
}

void Update(int deltaTime) {
	agent.Update(deltaTime);
}

void Render(SDL_Window* window, SDL_GLContext context) {
	SDL_GL_MakeCurrent(window, context);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);

	environment.Draw();
	agent.Draw();

	SDL_GL_SwapWindow(window);
}