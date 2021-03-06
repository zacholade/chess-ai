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
    double boardPosX = ((double) ((double) mouseX - ((double) borderWidth / 2)) / (double) pieceSize) + 1;
    double boardPosY = ((double) ((double) height - (double) mouseY - ((double) borderHeight / 2)) / (double) pieceSize) + 1;

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

const double Window::getBorderScale()
{
    return borderScale;
}

double Window::getPieceSize()
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
    if (boardPos != -1 && board->getBoard()[boardPos] != Piece::None)
    {
        board->setHeldBoardPosition(boardPos);
    }
}

void Window::handleMouseButtonUp(Board* board)
{
    int heldBoardPosition = board->getHeldBoardPosition();
    SDL_GetMouseState(&mouseX, &mouseY);
    if (heldBoardPosition != -1)
    {
        int newPos = getBoardPosition(board, mouseX, mouseY);
        if (newPos != -1) 
        {
            board->movePiece(heldBoardPosition, newPos);
        }
    }
    board->setHeldBoardPosition(-1);
}

void Window::handleMouseMovement()
{
    SDL_GetMouseState(&mouseX, &mouseY);
}

void Window::handleWindowResized(int width, int height)
{
    this->width = width;
    this->height = height;

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
