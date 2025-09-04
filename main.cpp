#include <iostream>
#include <raylib.h>
#include "simulation.h"


// ok so basic logic of conway's game of life is shrimpl.

// each cell has 1 of 2 statuses. DEAD or ALIVE (bool)

// living 
// neighbors - status
//		1		DEAD
//		2		ALIVE
//		3		ALIVE
//	4 & above	DEAD

// birth req is exactly 3 living neighbors


int main() {

	const int WINDOW_WIDTH = 600; /*! Width of the window. */
	const int WINDOW_HEIGHT = 600; /*! Height of the window. */
	const int TARGET_FPS = 8; /*! The target FPS of the simulation. More accurately, this is the FPS Ceiling. */
	const int CELL_SIZE = 5; /*! The size of the cell. Length of one side in pixels. Minimum of 2px*/

	Color BACKGROUND_COLOR = { 25, 25, 30, 255 }; /*! A variable to define the color of the background. Default set to Blue-ish Gray. */

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game Of Life");
	SetTargetFPS(TARGET_FPS);

	// conway sim
	Simulation sim(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

	while (!WindowShouldClose()) {

		sim.Update();
		/*! After processing all events and updating states, draw the*/
		BeginDrawing();
		ClearBackground(BACKGROUND_COLOR);
		sim.Draw();

		EndDrawing();
	
	}

	CloseWindow();
	return 0;
}