#include <raylib.h>
#include <iostream>
static struct {
	const char* text = "Space Orcs";
	Vector2 position = {400, 400};
	Font font = GetFontDefault();
	float fontSize = 20;
	float spacing = 5;
	Color color = GREEN;
} title;



int main()
{	
	InitWindow(800, 800, title.text);
	SetTargetFPS(60);

	const Vector2 titleSize = MeasureTextEx(GetFontDefault(), title.text, title.fontSize, title.spacing);
		
	title.position = [titleSize]() {
		const Vector2 scaled = Vector2(titleSize.x * 0.5, titleSize.y * 0.5);
		const Vector2 diff = Vector2(title.position.x - scaled.x, title.position.y - scaled.y);
		return diff;
	}();


	while (true) {
		BeginDrawing();
		ClearBackground(BLACK);

		
		std::cout << title.position.x << " " << title.position.y;
		DrawTextEx(title.font, title.text, title.position, title.fontSize, title.spacing, title.color);

		EndDrawing();

	}

	return 0;
}
