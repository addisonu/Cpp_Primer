# Manage compilation of Web_Mancing_Wbot project

Cpp = c++
CC = g++
CCFlags = -Wall -g
LDFLAGS = -lm

Word.o : Word.cpp Word.h
	${Cpp} -c Word.cpp

build_url.o : build_url.cpp
	${Cpp} -c build_url.cpp

cpp_webpage.o : cpp_webpage.cpp cpp_webpage.h
	${Cpp} -c cpp_webpage.cpp

Indexer.o : Indexer.cpp Indexer.h Word.h cpp_webpage.h Word.h
	${Cpp} -c Indexer.cpp

Hash_indexer.o : Hash_indexer.cpp Hash_indexer.h Word.h cpp_webpage.h node2.h
	${Cpp} -c Hash_indexer.cpp

ubc_idx.o : ubc_idx.cpp Word.h cpp_webpage.h Indexer.h
	${Cpp} -c ubc_idx.cpp

ubc_hash.o : ubc_hash.cpp Word.h cpp_webpage.h Hash_indexer.h node2.h
	${Cpp} -c ubc_hash_cpp

ubc_idx : Word.o build_url.o cpp_webpage.o Indexer.o CommandRunner.o FileInputStream.o FileSystem.o HTTPInputStream.o StringUtil.o URLConnection.o ubc_idx.o
	${Cpp} -c Word.o build_url.o cpp_webpage.o Indexer.o CommandRunner.o FileInputStream.o FileSystem.o HTTPInputStream.o StringUtil.o URLConnection.o -o ubc_idx.o -o ubc_idx

ubc_hash : Word.o build_url.o cpp_webpage.o Hash_indexer.o CommandRunner.o FileInputStream.o FileSystem.o HTTPInputStream.o StringUtil.o URLConnection.o ubc_hash.o
	${Cpp} -c Word.o build_url.o cpp_webpage.o Hash_indexer.o CommandRunner.o FileInputStream.o FileSystem.o HTTPInputStream.o StringUtil.o URLConnection.o -o ubc_hash.o -o ubc_hash
