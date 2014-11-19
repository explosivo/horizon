############
MACHINE= $(shell uname -s)

ifeq ($(MACHINE),Darwin)
    OPENGL_LIB= -framework OpenGL
    SDL_LIB= -framework SDL2
else
    OPENGL_LIB= -I/usr/lib64 -lGL -lGLU
    SDL_LIB= -lSDL2
endif

# object files have corresponding source files
CXX=g++
COMPILER_FLAGS= -w -std=c++11
LIBS= $(SDL_LIB) $(OPENGL_LIB)
SOURCE= *.cpp
HEADERS= *.h
OBJ= *.o
BUILD_DIR= bin/
EXEC= horizon

$(EXEC):
	$(CXX) $(SOURCE) $(COMPILER_FLAGS) $(OPENGL_LIB) $(SDL_LIB) -o $(EXEC)
	mkdir -p $(BUILD_DIR)
	mv $(EXEC) $(BUILD_DIR)


clean:
	rm -f $(OBJ)
	rm -rf *.dSYM $(BUILD_DIR)
