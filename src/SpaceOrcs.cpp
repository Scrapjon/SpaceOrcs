#include <iostream>
#include <raylib.h>
#include "Math.h"

static struct {
	const char* text = "Space Orcs";
	Vector2D position = {400, 400};
	Font font = GetFontDefault();
	float fontSize = 20;
	float spacing = 5;
	Color color = GREEN;
} title;

constexpr float FPS = 60;
constexpr float delta_time = 1/FPS;


constexpr float GetMoveSpeed(float move_speed = 100) {
	return move_speed* delta_time;
}

int main()
{	

	

	InitWindow(800, 800, title.text);
	SetTargetFPS(FPS);

	

	const Vector2D titleSize = MeasureTextEx(GetFontDefault(), title.text, title.fontSize, title.spacing);
		
	title.position = Vector2D(title.position - (titleSize*0.5f));

	Camera2D camera{};

	

	while (true) {


		if (IsKeyDown(KEY_RIGHT)) {
			camera.target.x += GetMoveSpeed();
		} else if (IsKeyDown(KEY_LEFT)) {
			camera.target.x -= GetMoveSpeed();
		}

		if (IsKeyDown(KEY_UP)) {
			camera.target.y -= GetMoveSpeed();
		} else if (IsKeyDown(KEY_DOWN)) {
			camera.target.y += GetMoveSpeed();
		}

		if (IsKeyDown(KEY_LEFT_SHIFT)) {
			camera.zoom += 0.1 * delta_time;
		} else if (IsKeyDown(KEY_LEFT_CONTROL)) {
			camera.zoom -= 0.1 * delta_time;
		}

		if (IsKeyDown(KEY_ESCAPE)) {
			break;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		BeginMode2D(camera);

		
		std::cout << camera.target.x << " " << camera.target.y << " " << camera.zoom << "\n";
		DrawTextEx(title.font, title.text, title.position, title.fontSize, title.spacing, title.color);

		EndMode2D();
		EndDrawing();

	}

	return 0;
}
