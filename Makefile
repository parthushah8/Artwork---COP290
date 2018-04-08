EXE = ArtWorks
CC = g++

SRC_DIR = ./src
OBJ_DIR = ./obj
EXE_DIR = ./bin

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = Point2.o Point3.o Line.o Edge.o Edge_P.o Face.o graph.o wireframe.o twoD_Fig.o threeD_Fig.o window2.o window3.o secondwindow.o thirdwindow.o firstwindow.o main_firstwindow.o
CPPFLAGS += -I. -Iinclude/.
CFLAGS += -Wall
LDFLAGS += -Llib
LDLIBS += -lm -lGLU -lGL -lglut

.PHONY: all clean

all: $(EXE)

%.o: $(SRC_DIR)/%.cpp
	$(CC) $< $(CPPFLAGS) $(LDLIBS) -c `pkg-config gtkmm-3.0 --cflags --libs` -o $(OBJ_DIR)/$@

$(EXE): $(OBJ)
	 $(CC) $(OBJ_DIR)/*.o $(LDLIBS) -o $(EXE_DIR)/$@ `pkg-config gtkmm-3.0 --cflags --libs`
	 @echo "Done build"
	 @echo "COP290 project : Engineering drawing package"
clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(EXE_DIR)/*


