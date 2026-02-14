#pragma once
#include <raylib.h>

// Unscaled screen width that the game coordinate system uses
constexpr int DEFAULT_SCREEN_WIDTH = 1280;


constexpr int DEFAULT_SCREEN_HEIGHT = 780;

struct ScreenData {


	ScreenData(int screenWidth = DEFAULT_SCREEN_WIDTH, int screenHeight = DEFAULT_SCREEN_HEIGHT, int targetFrameRate = 60)
		: screenWidth(screenWidth), screenHeight(screenHeight), targetFrameRate(targetFrameRate)
	{

	}
	int screenWidth;
	int screenHeight;
	int targetFrameRate;
};

static ScreenData screenData = { DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT };

// Converts from the cartesian coordinate space to the corresponding screen position
static Vector2 ToScreenSpace(const Vector2 worldLocation) {
	Vector2 newLocation = { worldLocation.x, worldLocation.y };
	newLocation.x += GetScreenWidth() * 0.5;
	newLocation.y += GetScreenHeight() * 0.5;
	return newLocation;

}
// Converts from the screen position to the corresponding cartesian coordinate space
static Vector2 ToWorldSpace(const Vector2 screenLocation) {
	Vector2 newLocation = { screenLocation.x, -screenLocation.y };
	newLocation.x -= GetScreenWidth() * 0.5;
	newLocation.y += GetScreenHeight() * 0.5;
	return newLocation;
}



