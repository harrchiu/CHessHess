CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = chess
OBJECTS = Ai1.o Ai2.o Ai3.o Ai4.o Bishop.o Board.o Display.o Game.o Human.o\
	King.o Knight.o main.o Move.o Pawn.o Queen.o Rook.o Piece.o Player.o\
	Square.o TextualDisplay.o GraphicalDisplay.o PotentialMove.o sdl_wrap.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lSDL2 -lSDL2_image -lSDL2_ttf

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
