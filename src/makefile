# CXX = g++
# CXXFLAGS = -std=c++14 -Wall -Werror -g
# EXEC = vec3d
# OBJECTS = Ai1.o Ai2.o Ai3.o Ai4.o Bishop.o Board.o Display.o Game.o Human.o\
# 	King.o Knight.o main.o Move.o Pawn.o Queen.o Rook.o\
# 	Square.o TextualDisplay.o PotentialMove.o

# ${EXEC}: ${OBJECTS}
# 	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

# Ai1.o : Ai1.cc Ai1.h Player.h
# Ai2.o : Ai2.cc Ai2.h Player.h
# Ai3.o : Ai3.cc Ai3.h Player.h
# Ai4.o : Ai4.cc Ai4.h Player.h
# Bishop.o: Bishop.cc Bishop.h Piece.h PotentialMove.h
# Board.o: Board.cc Board.h Piece.h Square.h Move.h
# Display.o: Display.cc Display.h
# Game.o: Game.cc Game.h Board.h Piece.h Pawn.h\
# 		Rook.h Knight.h Bishop.h Queen.h King.h Square.h
# Human.o: Human.cc Human.h Player.h
# King.o: King.cc King.h Piece.h PotentialMove.h
# Knight.o: Knight.cc Knight.h Piece.h PotentialMove.h
# main.o: main.cc Game.h Board.h
# Move.o: Move.cc Move.h 
# Pawn.o: Pawn.cc Pawn.h Piece.h PotentialMove.h
# Queen.o: Queen.cc Queen.h Piece.h PotentialMove.h
# Rook.o: Rook.cc Rook.h Piece.h PotentialMove.h
# Square.o: Square.cc Square.h Pawn.h\
# 		Rook.h Knight.h Bishop.h Queen.h King.h
# TextualDisplay.o: TextualDisplay.cc TextualDisplay.h Display.h
# PotentialMove.o: PotentialMove.cc PotentialMove.h

# .PHONY: clean
# clean:
# 	rm ${OBJECTS} ${EXEC}

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = chess
OBJECTS = Ai1.o Ai2.o Ai3.o Ai4.o Bishop.o Board.o Display.o Game.o Human.o\
	King.o Knight.o main.o Move.o Pawn.o Queen.o Rook.o Piece.o Player.o\
	Square.o TextualDisplay.o GraphicalDisplay.o PotentialMove.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean