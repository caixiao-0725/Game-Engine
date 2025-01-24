#pragma once

#include "Cngine/Core/core.h"
#include "Cngine/Core/KeyCodes.h"
#include "Cngine/Core/MouseCodes.h"

namespace Cngine {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}