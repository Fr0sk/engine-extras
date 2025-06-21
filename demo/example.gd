extends Node


func _ready() -> void:
	await get_tree().create_timer(2).timeout
	EngineExtras.set_mouse_passthrough(true)
	await get_tree().create_timer(2).timeout
	EngineExtras.set_mouse_passthrough(false)
