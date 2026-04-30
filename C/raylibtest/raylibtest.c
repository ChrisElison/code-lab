/*
 * Raylib Test
 *
 * Shows a window with text message
 *
 * Compile (Linux):
 * $ gcc raylibtest.c -o raylibtest.out -I../include -L../lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
 *
 * Requires OpenGL Mesa Dev packages:
 * $ sudo apt install libgl1-mesa-dev libglu1-mesa-dev
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

#include <stdio.h>
#include "../include/raylib.h"

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(800, 600, "Raylib Test by Chris Elison");

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Chris Elison Was Here!", 100, 200, 20, WHITE);
		DrawText("ChrisElison.uk - youtube.com/@ChrisElison - x.com/ChrisElison", 100, 250, 20, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
