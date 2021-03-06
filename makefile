#gdb ./romano
#run ./romano

IDIR =include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=src/obj
LDIR=lib
SRCDIR=src

LIBS=-lm

_DEPS = romano.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_romano.o romano.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(OBJ): $(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -std=c++0x -c -o $@ $< $(CFLAGS)

testes: $(OBJ)
	$(CC) -std=c++0x -o $@ $^ $(CFLAGS) $(LIBS)
	cppcheck --enable=warning src/romano.cpp src/testa_romano.cpp include/romano.h
	cpplint src/romano.cpp src/testa_romano.cpp include/romano.h
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./testes

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
