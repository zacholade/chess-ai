#include "Window.h"

Window::Window(SDL_Window* window)
{
    this->window = window;
    SDL_GetMouseState(&mouseX, &mouseY);
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
    return borderWidth;
}

int Window::getMouseX()
{
    return mouseX;
}

int Window::getMouseY()
{
    return mouseY;
}

std::pair<int, int> Window::getMousePos()
{
    return std::pair<int, int>(mouseX, mouseY);
}

void Window::handleMouseButtonDown()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Window::handleMouseButtonUp()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Window::handleMouseMovement()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}
