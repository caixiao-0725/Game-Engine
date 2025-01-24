#pragma once

namespace Cngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define CG_KEY_SPACE           ::Cngine::Key::Space
#define CG_KEY_APOSTROPHE      ::Cngine::Key::Apostrophe    /* ' */
#define CG_KEY_COMMA           ::Cngine::Key::Comma         /* , */
#define CG_KEY_MINUS           ::Cngine::Key::Minus         /* - */
#define CG_KEY_PERIOD          ::Cngine::Key::Period        /* . */
#define CG_KEY_SLASH           ::Cngine::Key::Slash         /* / */
#define CG_KEY_0               ::Cngine::Key::D0
#define CG_KEY_1               ::Cngine::Key::D1
#define CG_KEY_2               ::Cngine::Key::D2
#define CG_KEY_3               ::Cngine::Key::D3
#define CG_KEY_4               ::Cngine::Key::D4
#define CG_KEY_5               ::Cngine::Key::D5
#define CG_KEY_6               ::Cngine::Key::D6
#define CG_KEY_7               ::Cngine::Key::D7
#define CG_KEY_8               ::Cngine::Key::D8
#define CG_KEY_9               ::Cngine::Key::D9
#define CG_KEY_SEMICOLON       ::Cngine::Key::Semicolon     /* ; */
#define CG_KEY_EQUAL           ::Cngine::Key::Equal         /* = */
#define CG_KEY_A               ::Cngine::Key::A
#define CG_KEY_B               ::Cngine::Key::B
#define CG_KEY_C               ::Cngine::Key::C
#define CG_KEY_D               ::Cngine::Key::D
#define CG_KEY_E               ::Cngine::Key::E
#define CG_KEY_F               ::Cngine::Key::F
#define CG_KEY_G               ::Cngine::Key::G
#define CG_KEY_H               ::Cngine::Key::H
#define CG_KEY_I               ::Cngine::Key::I
#define CG_KEY_J               ::Cngine::Key::J
#define CG_KEY_K               ::Cngine::Key::K
#define CG_KEY_L               ::Cngine::Key::L
#define CG_KEY_M               ::Cngine::Key::M
#define CG_KEY_N               ::Cngine::Key::N
#define CG_KEY_O               ::Cngine::Key::O
#define CG_KEY_P               ::Cngine::Key::P
#define CG_KEY_Q               ::Cngine::Key::Q
#define CG_KEY_R               ::Cngine::Key::R
#define CG_KEY_S               ::Cngine::Key::S
#define CG_KEY_T               ::Cngine::Key::T
#define CG_KEY_U               ::Cngine::Key::U
#define CG_KEY_V               ::Cngine::Key::V
#define CG_KEY_W               ::Cngine::Key::W
#define CG_KEY_X               ::Cngine::Key::X
#define CG_KEY_Y               ::Cngine::Key::Y
#define CG_KEY_Z               ::Cngine::Key::Z
#define CG_KEY_LEFT_BRACKET    ::Cngine::Key::LeftBracket   /* [ */
#define CG_KEY_BACKSLASH       ::Cngine::Key::Backslash     /* \ */
#define CG_KEY_RIGHT_BRACKET   ::Cngine::Key::RightBracket  /* ] */
#define CG_KEY_GRAVE_ACCENT    ::Cngine::Key::GraveAccent   /* ` */
#define CG_KEY_WORLD_1         ::Cngine::Key::World1        /* non-US #1 */
#define CG_KEY_WORLD_2         ::Cngine::Key::World2        /* non-US #2 */

/* Function keys */
#define CG_KEY_ESCAPE          ::Cngine::Key::Escape
#define CG_KEY_ENTER           ::Cngine::Key::Enter
#define CG_KEY_TAB             ::Cngine::Key::Tab
#define CG_KEY_BACKSPACE       ::Cngine::Key::Backspace
#define CG_KEY_INSERT          ::Cngine::Key::Insert
#define CG_KEY_DELETE          ::Cngine::Key::Delete
#define CG_KEY_RIGHT           ::Cngine::Key::Right
#define CG_KEY_LEFT            ::Cngine::Key::Left
#define CG_KEY_DOWN            ::Cngine::Key::Down
#define CG_KEY_UP              ::Cngine::Key::Up
#define CG_KEY_PAGE_UP         ::Cngine::Key::PageUp
#define CG_KEY_PAGE_DOWN       ::Cngine::Key::PageDown
#define CG_KEY_HOME            ::Cngine::Key::Home
#define CG_KEY_END             ::Cngine::Key::End
#define CG_KEY_CAPS_LOCK       ::Cngine::Key::CapsLock
#define CG_KEY_SCROLL_LOCK     ::Cngine::Key::ScrollLock
#define CG_KEY_NUM_LOCK        ::Cngine::Key::NumLock
#define CG_KEY_PRINT_SCREEN    ::Cngine::Key::PrintScreen
#define CG_KEY_PAUSE           ::Cngine::Key::Pause
#define CG_KEY_F1              ::Cngine::Key::F1
#define CG_KEY_F2              ::Cngine::Key::F2
#define CG_KEY_F3              ::Cngine::Key::F3
#define CG_KEY_F4              ::Cngine::Key::F4
#define CG_KEY_F5              ::Cngine::Key::F5
#define CG_KEY_F6              ::Cngine::Key::F6
#define CG_KEY_F7              ::Cngine::Key::F7
#define CG_KEY_F8              ::Cngine::Key::F8
#define CG_KEY_F9              ::Cngine::Key::F9
#define CG_KEY_F10             ::Cngine::Key::F10
#define CG_KEY_F11             ::Cngine::Key::F11
#define CG_KEY_F12             ::Cngine::Key::F12
#define CG_KEY_F13             ::Cngine::Key::F13
#define CG_KEY_F14             ::Cngine::Key::F14
#define CG_KEY_F15             ::Cngine::Key::F15
#define CG_KEY_F16             ::Cngine::Key::F16
#define CG_KEY_F17             ::Cngine::Key::F17
#define CG_KEY_F18             ::Cngine::Key::F18
#define CG_KEY_F19             ::Cngine::Key::F19
#define CG_KEY_F20             ::Cngine::Key::F20
#define CG_KEY_F21             ::Cngine::Key::F21
#define CG_KEY_F22             ::Cngine::Key::F22
#define CG_KEY_F23             ::Cngine::Key::F23
#define CG_KEY_F24             ::Cngine::Key::F24
#define CG_KEY_F25             ::Cngine::Key::F25

/* Keypad */
#define CG_KEY_KP_0            ::Cngine::Key::KP0
#define CG_KEY_KP_1            ::Cngine::Key::KP1
#define CG_KEY_KP_2            ::Cngine::Key::KP2
#define CG_KEY_KP_3            ::Cngine::Key::KP3
#define CG_KEY_KP_4            ::Cngine::Key::KP4
#define CG_KEY_KP_5            ::Cngine::Key::KP5
#define CG_KEY_KP_6            ::Cngine::Key::KP6
#define CG_KEY_KP_7            ::Cngine::Key::KP7
#define CG_KEY_KP_8            ::Cngine::Key::KP8
#define CG_KEY_KP_9            ::Cngine::Key::KP9
#define CG_KEY_KP_DECIMAL      ::Cngine::Key::KPDecimal
#define CG_KEY_KP_DIVIDE       ::Cngine::Key::KPDivide
#define CG_KEY_KP_MULTIPLY     ::Cngine::Key::KPMultiply
#define CG_KEY_KP_SUBTRACT     ::Cngine::Key::KPSubtract
#define CG_KEY_KP_ADD          ::Cngine::Key::KPAdd
#define CG_KEY_KP_ENTER        ::Cngine::Key::KPEnter
#define CG_KEY_KP_EQUAL        ::Cngine::Key::KPEqual

#define CG_KEY_LEFT_SHIFT      ::Cngine::Key::LeftShift
#define CG_KEY_LEFT_CONTROL    ::Cngine::Key::LeftControl
#define CG_KEY_LEFT_ALT        ::Cngine::Key::LeftAlt
#define CG_KEY_LEFT_SUPER      ::Cngine::Key::LeftSuper
#define CG_KEY_RIGHT_SHIFT     ::Cngine::Key::RightShift
#define CG_KEY_RIGHT_CONTROL   ::Cngine::Key::RightControl
#define CG_KEY_RIGHT_ALT       ::Cngine::Key::RightAlt
#define CG_KEY_RIGHT_SUPER     ::Cngine::Key::RightSuper
#define CG_KEY_MENU            ::Cngine::Key::Menu