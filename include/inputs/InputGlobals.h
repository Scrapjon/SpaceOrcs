#pragma once 
#include <raylib.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <functional>

namespace input {

	enum class InputAction {
		MoveUp,
		MoveDown,
		MoveLeft,
		MoveRight,
		Shoot,
	};

	const static std::unordered_map<KeyboardKey, InputAction> inputMappings = {
		{ KEY_W, InputAction::MoveUp },
		{ KEY_S, InputAction::MoveDown },
		{ KEY_A, InputAction::MoveLeft },
		{ KEY_D, InputAction::MoveRight },
		{ KEY_SPACE, InputAction::Shoot }
	};




	static std::vector<KeyboardKey> GetKeysDynamic(std::function<bool(KeyboardKey)> function) {
		std::vector<KeyboardKey> pressedKeys;
		pressedKeys.reserve(inputMappings.size());
		std::cout << "Size: " << inputMappings.size() << "\n";
		for (const auto& [key, action] : inputMappings) {
			if (function(key))
				pressedKeys.push_back(key);
		}
		pressedKeys.shrink_to_fit();
		return pressedKeys;
	}

	static std::vector<KeyboardKey> GetKeysDown() {
		return GetKeysDynamic(IsKeyDown);
	}
};

