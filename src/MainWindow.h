#pragma once
#include "raylib.h"
#include "Board.h"
#include <string>
#include "Tetromino.h"

class Window{

public:
	Window(int width, int height, int fps, std::string Title);
	Window(const Window& other) = delete;
	Window& operator = (const Window& other) = delete;
	~Window() noexcept;
	bool gameShouldClose() const;
};