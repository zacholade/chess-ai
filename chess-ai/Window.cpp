#include "Window.h"
#include "Constants.h"
#include <iostream>

Window::Window(SDL_Window* window)
{
    this->window = window;
    borderScale = windowBorderScale;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_GetWindowSize(window, &width, &height);
    handleWindowResized(width, height);
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
    int boardPosX;
    boardPosX = mouseX - (width * borderScale);
    std::cout << boardPosX << std::endl;
    return boardPosX;
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

const float Window::getBorderScale()
{
    return borderScale;
}

int Window::getBorderX()
{
    return borderX;
}

int Window::getBorderY()
{
    return borderY;
}

int Window::getPieceSize()
{
    return pieceSize;
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

void Window::handleWindowResized(int width, int height)
{
    // We need to work out whether width or height is shorter.
    // We scale the board based off the shortest axis.
    if (width <= height) 
    { 
        borderX = (int)width * borderScale;
        borderY = height - (width - (borderX));
    }
    else
    {
        borderY = (int)height * borderScale;
        borderX = width - (height - (borderY));
    }
    int minimum = std::min({ width, height });
    pieceSize = (minimum - std::min({ borderX, borderY })) / 8;
}
