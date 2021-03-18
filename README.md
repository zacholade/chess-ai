# chess-ai
A fun project of implementing a chess AI that I am working on in my free time.

Soon to be stockfish 2.

Currently includes quite simple, intuitive and slick GUI:

![](https://github.com/zacholade/chess-ai/blob/master/gui.png?raw=true)

## TODO List

[x] Store chess board in a vector and add methods to move pieces.

[x] Add methods to import a chess board from a [FEN String](https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation).

[x] Display the chess board as a GUI. Window/Renderer classes.

[ ] Generate pseudo legal moves (in progress).

[ ] Filter pseudo legal moves by legal moves. (Pins, moving into check).

[ ] Implement an AI which can use this move data to find the 'optimal' move.