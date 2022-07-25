CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g
EXEC = vec3d
OBJECTS = Ai1.o Ai2.o Ai3.o Ai4.o Bishop.o Board.o Display.o Game.o Human.o King.o Knight.o main.o Move.o Pawn.o Queen.o Rook.o Square.o TextualDisplay.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

Ai1.o : Ai1.cc Ai1.h Player.h
Ai2.o : Ai2.cc Ai2.h Player.h
Ai3.o : Ai3.cc Ai3.h Player.h
Ai4.o : Ai4.cc Ai4.h Player.h
Bishop.o: Bishop.cc Bishop.h Piece.h
Board.o: Board.cc Board.h Piece.h Square.h Move.h
Display.o: Display.cc Display.h 
Game.o: Game.cc Game.h Board.h Piece.h Pawn.h 
		Rook.h Knight.h Bishop.h Queen.h King.h Square.h
Human.o: Human.cc Human.h Player.h
King.o: King.cc King.h Piece.h
Knight.o: Knight.cc Knight.h Piece.h
main.o: main.cc Game.h Board.h
Move.o: Move.cc Move.h 
Pawn.o: Pawn.cc Pawn.h Piece.h
Queen.o: Queen.cc Queen.h Piece.h
Rook.o: Rook.cc Rook.h  Piece.h
Square.o: Square.cc Square.h
TextualDisplay.o: TextualDisplay.cc TextualDisplay.h Display.h

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC}
