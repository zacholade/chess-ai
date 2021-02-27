#include "Window.h"
#include "Constants.h"

Window::Window(SDL_Window* window)
{
    this->window = window;
    SDL_GetMouseState(&mouseX, &mouseY);
    borderScale = windowBorderScale;
}

Window::~Window()
{
}

SDL_Window* Window::getWindow()
{
    return window;
}

int Window::getBoardPosition(Board* board, int mouseX, int mouseY)
{
    return 0;
}

float Window::getBorderWidth()
{
    return borderScale;
}

int Window::getMouseX()
{
    return mouseX;
}

int Window::getMouseY()
{
    return mouseY;
}

int Window::getWidth()
{
    return width;
}

int Window::getHeight()
{
    return height;
}

float Window::getBorderScale()
{
    return borderScale;
}

std::pair<int, int> Window::getMousePos()
{
    return std::pair<int, int>(mouseX, mouseY);
}

void Window::handleMouseButtonDown(Board* board)
{
    SDL_GetMouseState(&mouseX, &mouseY);
    int boardPos = getBoardPosition(board, mouseX, mouseY);
}

void Window::handleMouseButtonUp()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Window::handleMouseMovement()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Window::handleWindowResized(SDL_Event event)
{
    width = event.window.data1;
    height = event.window.data2;
}
