#include "engine_extras.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

EngineExtras *EngineExtras::singleton = nullptr;

EngineExtras *EngineExtras::get_singleton() {
	return singleton;
}

EngineExtras::EngineExtras() {
	singleton = this;
}

EngineExtras::~EngineExtras() {
	singleton = nullptr;
}

void EngineExtras::set_mouse_passthrough(bool enabled) {
#ifdef _WIN32
	HWND hWnd = GetActiveWindow();
	SetWindowLongPtr(hWnd, GWL_EXSTYLE, enabled ? WS_EX_LAYERED | WS_EX_TRANSPARENT : WS_EX_TRANSPARENT);
#else
	print_line("EngineExtras::set_mouse_passthrough is not defined for this platform");
#endif
}

void EngineExtras::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("set_mouse_passthrough"), &EngineExtras::set_mouse_passthrough);
}
