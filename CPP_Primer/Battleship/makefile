OBJS =  $(TMP_DIR)b_main.o $(TMP_DIR)board.o $(TMP_DIR)ship.o $(TMP_DIR)pointcollection.o
CC = clang++ -stdlib=libc++ -std=c++11
DEBUG = -g
CFLAGS = -c ${DEBUG}
LFLAGS = ${DEBUG}
TMP_DIR  = battle_tmp/

all: folder battle

folder:
	mkdir ${TMP_DIR}

battle : ${OBJS}
	${CC} ${LFLAGS} ${OBJS} -o $(TMP_DIR)battle

${TMP_DIR}b_main.o: b_main.cpp point.h pointcollection.h ship.h board.h
	${CC} ${CFLAGS} b_main.cpp -o ${TMP_DIR}b_main.o

${TMP_DIR}board.o: board.cpp board.h point.h pointcollection.h ship.h 
	${CC} ${CFLAGS} board.cpp -o $(TMP_DIR)board.o

${TMP_DIR}ship.o: ship.cpp ship.h pointCollection.h point.h
	${CC} ${CFLAGS} ship.cpp -o $(TMP_DIR)ship.o

${TMP_DIR}pointcollection.o: pointcollection.cpp pointCollection.h point.h
	${CC} ${CFLAGS} pointcollection.cpp -o $(TMP_DIR)pointcollection.o

#folder:
#	mkdir ${TMP_DIR}

clean:
	\rm -r ${TMP_DIR} *.o *~ *.ghc battle

tar:
	tar cfv battle.tar b_main.cpp board.cpp board.h ship.cpp ship.h pointcollection.cpp \
		 pointcollection.h point.h

