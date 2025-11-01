CC = g++
SOURCES = chess_analyser.cpp visualiser.cpp
LINKERS = -lm -lglfw -lGL
chess:
	$(CC) -g -o run $(SOURCES) $(LINKERS)

clean:
	rm -f run
