# Autor: Integrante 1
CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = $(wildcard src/*.cpp)

ifeq ($(OS),Windows_NT)
EXE = gestor.exe
RUN = $(EXE)
RM = del /Q /F
else
EXE = gestor
RUN = ./$(EXE)
RM = rm -f
endif

all: $(EXE)

$(EXE): $(SRC) $(wildcard src/*.h)
	$(CXX) $(CXXFLAGS) $(SRC) -Isrc -o $(EXE)

run: $(EXE)
	$(RUN)

clean:
	-$(RM) $(EXE)

.PHONY: all run clean
