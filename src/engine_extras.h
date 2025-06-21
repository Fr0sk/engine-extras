#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class EngineExtras : public Object {
	GDCLASS(EngineExtras, Object)

public:
	static EngineExtras *get_singleton();
	EngineExtras();
	~EngineExtras();

	void set_mouse_passthrough(bool enabled);

protected:
	static void _bind_methods();
	static EngineExtras *singleton;
};
