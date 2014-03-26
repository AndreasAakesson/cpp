OUTPUT=custom
CC=/opt/local/bin/g++ -std=c++11
CFLAGS = -c -Wall -Wextra -pedantic
LFLAGS = `/usr/local/bin/fltk-config --use-images --ldflags` -lfltk_jpeg

FOLDER=.
FILES=$(wildcard $(FOLDER)/*.cpp)

COBJS=$(FILES:.cpp=.o)

# compile each .cpp to .o
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


all: $(COBJS)
	$(CC) $(LFLAGS) $(COBJS) -o $(OUTPUT)

custom: $(COBJS)
	$(CC) $(LFLAGS) $(COBJS) -o $(OUTPUT)

clean:
	$(RM) $(COBJS) *~ $(OUTPUT)
