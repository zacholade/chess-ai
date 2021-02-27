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
    float boardPosX = ((float) (mouseX - (borderWidth / 2)) / (float) pieceSize) + 1;
    float boardPosY = ((float) (height - mouseY - (borderHeight / 2)) / (float) pieceSize) + 1;

    std::cout << boardPosX << ", " << boardPosY << std::endl;
    if (boardPosX > 1 && boardPosX < 9 && boardPosY > 1 && boardPosY < 9)
    {
        int boardPos = (int) boardPosX - 1 + (((int) boardPosY * 8) - 8);
        return boardPos;
    }
    // out of board bounds
    return -1;
}

int Window::getBorderWidth()
{
    return borderWidth;
}

int Window::getBorderHeight()
{
    return borderHeight;
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
    std::cout << "Board Index: " << boardPos << ", " << std::endl;
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
        borderWidth = width * borderScale;
        borderHeight = height - (width - (borderWidth));
    }
    else
    {
        borderHeight = height * borderScale;
        borderWidth = width - (height - (borderHeight));
    }
    int minimum = std::min({ width, height });
    pieceSize = (minimum - std::min({ borderWidth, borderHeight })) / 8;
}
