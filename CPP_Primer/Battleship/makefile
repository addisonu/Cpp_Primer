OBJS =  b_main.o board.o ship.o pointcollection.o
CC = clang++ -stdlib=libc++ -std=c++11
DEBUG = -g
CFLAGS = -c ${DEBUG}
LFLAGS = ${DEBUG}

battle : ${OBJS}
	${CC} ${LFLAGS} ${OBJS} -o battle

b_main.o: b_main.cpp point.h pointcollection.h ship.h board.h
	${CC} ${CFLAGS} b_main.cpp

board.o: board.cpp board.h point.h pointcollection.h ship.h 
	${CC} ${CFLAGS} board.cpp

ship.o: ship.cpp ship.h pointCollection.h point.h
	${CC} ${CFLAGS} ship.cpp

pointcollection.o: pointcollection.cpp pointCollection.h point.h
	${CC} ${CFLAGS} pointcollection.cpp

clean:
	     \rm *.o *~ *.gch battle

tar:
	     tar cfv battle.tar b_main.cpp board.cpp board.h ship.cpp ship.h pointcollection.cpp \
		 pointcollection.h point.h

