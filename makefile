CC=g++
SRC=Gilet_joueur.cc Ecran.cc CRS.cc Grenade.cc Voiture.cc Game.cc
OBJS_LIB = ${SRC:.cc=.o}
OBJS = ${OBJS_LIB} main.o
LSFML= -lsfml-system -lsfml-window -lsfml-graphics


all: Yellow_Jacket

Yellow_Jacket: ${OBJS} 
	${CC} -o Yellow_Jacket ${OBJS} ${LSFML}


%.o: %.c
	${CC} -c $<

.depend:
	g++ -MM ${SRC} > $@

-include .depend

test.exe: test.o
	g++ -o test.exe test.o ${LSFML}


test.o: test.cc
	g++ -c test.cc

clean:
	rm -f test.o test.exe ${OBJS} Yellow_Jacket .depend

.PHONY: clean