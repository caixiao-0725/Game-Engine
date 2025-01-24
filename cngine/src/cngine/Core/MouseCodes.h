#pragma once

namespace Cngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define CG_MOUSE_BUTTON_0      ::Cngine::Mouse::Button0
#define CG_MOUSE_BUTTON_1      ::Cngine::Mouse::Button1
#define CG_MOUSE_BUTTON_2      ::Cngine::Mouse::Button2
#define CG_MOUSE_BUTTON_3      ::Cngine::Mouse::Button3
#define CG_MOUSE_BUTTON_4      ::Cngine::Mouse::Button4
#define CG_MOUSE_BUTTON_5      ::Cngine::Mouse::Button5
#define CG_MOUSE_BUTTON_6      ::Cngine::Mouse::Button6
#define CG_MOUSE_BUTTON_7      ::Cngine::Mouse::Button7
#define CG_MOUSE_BUTTON_LAST   ::Cngine::Mouse::ButtonLast
#define CG_MOUSE_BUTTON_LEFT   ::Cngine::Mouse::ButtonLeft
#define CG_MOUSE_BUTTON_RIGHT  ::Cngine::Mouse::ButtonRight
#define CG_MOUSE_BUTTON_MIDDLE ::Cngine::Mouse::ButtonMiddle