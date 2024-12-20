EXE=final

# Main target
all: $(EXE)

# Msys/MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall -DUSEGLEW
LIBS=-lfreeglut -lglew32 -lglu32 -lopengl32 -lm
CLEAN=rm -f *.exe *.o *.a csci_lib/*.o objects/*.o .o
else
# OSX
ifeq "$(shell uname)" "Darwin"
RES=$(shell uname -r|sed -E 's/(.).*/\1/'|tr 12 21)
CFLG=-O3 -Wall -Wno-deprecated-declarations -DRES=$(RES)
LIBS=-framework GLUT -framework OpenGL
# Linux/Unix/Solaris
else
CFLG=-O0 -Wall -g
LIBS=-lglut -lGLU -lGL -lm
endif
# OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a csci_lib/*.o objects/*.o objects/primitives/*.o objects/generic/*.o objects/prefabs/*.o
endif

# Dependencies
final.o: final.cpp csci_lib/CSCIx229.h
csci_lib/fatal.o: csci_lib/fatal.c csci_lib/CSCIx229.h
csci_lib/errcheck.o: csci_lib/errcheck.c csci_lib/CSCIx229.h
csci_lib/print.o: csci_lib/print.c csci_lib/CSCIx229.h
csci_lib/loadtexbmp.o: csci_lib/loadtexbmp.c csci_lib/CSCIx229.h
csci_lib/loadobj.o: csci_lib/loadobj.c csci_lib/CSCIx229.h
csci_lib/projection.o: csci_lib/projection.c csci_lib/CSCIx229.h

# Primitives
objects/primitives/cuboid.o: objects/primitives/cuboid.cpp objects/primitives/cuboid.h
objects/primitives/cylinder.o: objects/primitives/cylinder.cpp objects/primitives/cylinder.h
objects/primitives/pyramid.o: objects/primitives/pyramid.cpp objects/primitives/pyramid.h
objects/primitives/sphere.o: objects/primitives/sphere.cpp objects/primitives/sphere.h
objects/primitives/pipe.o: objects/primitives/pipe.cpp objects/primitives/pipe.h

# Objects
objects/object.o: objects/object.cpp objects/object.h
objects/skybox.o: objects/skybox.cpp objects/skybox.h
objects/terrain.o: objects/terrain.cpp objects/terrain.h
objects/water.o: objects/water.cpp objects/water.h

# Generic Objects
objects/generic/skyscraper.o: objects/generic/skyscraper.cpp objects/generic/skyscraper.h
objects/generic/intersection_light.o: objects/generic/intersection_light.cpp objects/generic/intersection_light.h
objects/generic/street_light.o: objects/generic/street_light.cpp objects/generic/street_light.h
objects/generic/street.o: objects/generic/street.cpp objects/generic/street.h
objects/generic/intersection.o: objects/generic/intersection.cpp objects/generic/intersection.h
objects/generic/park_bench.o: objects/generic/park_bench.cpp objects/generic/park_bench.h
objects/generic/eiffel_tower.o: objects/generic/eiffel_tower.cpp objects/generic/eiffel_tower.h
objects/generic/sidewalk.o: objects/generic/sidewalk.cpp objects/generic/sidewalk.h
objects/generic/golden_gate.o: objects/generic/golden_gate.cpp objects/generic/golden_gate.h


boundingbox.o: boundingbox.cpp boundingbox.h
vector2.o: vector2.cpp vector2.h
vector3.o: vector3.cpp vector3.h
vector4.o: vector4.cpp vector4.h
polygon.o: polygon.cpp polygon.h
camera.o: camera.cpp camera.h
renderer.o: renderer.cpp renderer.h
light.o: light.cpp light.h
scene.o: scene.cpp scene.h
example_scene.o: example_scene.cpp example_scene.h
texture.o: texture.cpp texture.h

# Create archive
csci_lib/CSCIx229.a: csci_lib/fatal.o csci_lib/errcheck.o csci_lib/print.o csci_lib/loadtexbmp.o csci_lib/loadobj.o csci_lib/projection.o
	ar -rcs $@ $^

# Compile rules 
csci_lib/%.o: csci_lib/%.c csci_lib/CSCIx229.h
	gcc -c $(CFLG) -Icsci_lib -o $@ $<

objects/%.o: objects/%.cpp objects/%.h
	g++ -c $(CFLG) -Icsci_lib -o $@ $<

objects/primitives/%.o: objects/primitives/%.cpp objects/primitives/%.h

objects/generic/%.o: objects/generic/%.cpp objects/generic/%.h
	g++ -c $(CFLG) -Icsci_lib -o $@ $<

# Compile C files to object files
.c.o:
	gcc -c $(CFLG) -Icsci_lib $<

# Compile C++ files to object files
.cpp.o:
	g++ -c $(CFLG) -Icsci_lib $<

# Link
final: final.o camera.o scene.o example_scene.o light.o vector4.o vector3.o vector2.o texture.o polygon.o boundingbox.o renderer.o objects/object.o objects/primitives/cuboid.o objects/primitives/sphere.o objects/primitives/cylinder.o objects/primitives/pipe.o objects/primitives/pyramid.o objects/skybox.o objects/terrain.o objects/water.o objects/generic/eiffel_tower.o objects/generic/golden_gate.o objects/generic/sidewalk.o objects/generic/skyscraper.o objects/generic/street_light.o objects/generic/intersection_light.o objects/generic/street.o objects/generic/intersection.o objects/generic/park_bench.o csci_lib/CSCIx229.a
	g++ $(CFLG) -o $@ $^ $(LIBS)

# Clean
clean:
	$(CLEAN)
