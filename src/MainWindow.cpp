#include "MainWindow.h"
#include <assert.h>

Window::Window(int width, int height, int fps, std::string Title)
{
	assert(!GetWindowHandle());
	InitWindow(width, height, Title.c_str());
	SetTargetFPS(fps);
};
 
Window::~Window() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Window::gameShouldClose() const
{
	return WindowShouldClose();;
}
