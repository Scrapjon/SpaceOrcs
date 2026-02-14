// SpaceOrcs.cpp : Defines the entry point for the application.
//

#include "SpaceOrcs.h"

using namespace std;

int main()
{
	InitWindow(screenData.screenWidth, screenData.screenHeight, "Space Orcs");
	SetTargetFPS(screenData.targetFrameRate);

	OrcShip orcShip = { {static_cast<float>(screenData.screenWidth / 2), static_cast<float>(screenData.screenHeight / 2)} };
	
	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		auto keysDown = input::GetKeysDown();

		for (auto key : keysDown) {
			cout << key << "\n";
		}

		orcShip.Draw();

		Vector2 shipWorldSpace = ToWorldSpace(orcShip.location);
		cout << "Unaltered Location: " << orcShip.location.x << " " << orcShip.location.y << "\n";
		cout << "World Space: " << shipWorldSpace.x << " " << shipWorldSpace.y << "\n";
		cout << "Screen Space: " << ToScreenSpace(shipWorldSpace).x << " " << ToScreenSpace(shipWorldSpace).y << "\n";

		EndDrawing();
	}
	
	return 0;
}
