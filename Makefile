CC=gcc
WARNING_FLAGS=-Wall -Wextra
EXE=main
SCAN_BUILD_DIR = scan-build-out
# LIBS is placed at the end of gcc's linking stage (after all .o files) so it links the necessary library functions (like pthread) to your code

# the -g flag at all gcc compilation stages ensures that you can use gdb to debug your code
$(EXE): main.o 537malloc.o tree.o
	$(CC) -g -o $(EXE) main.o 537malloc.o tree.o

main.o: main.c
	$(CC) -g $(WARNING_FLAGS) -c main.c

537malloc.o: 537malloc.c 537malloc.h
	$(CC) -g $(WARNING_FLAGS) -c 537malloc.c 537malloc.h

tree.o: tree.c tree.h
	$(CC) -g $(WARNING_FLAGS) -c tree.c tree.h

# the -f flag for rm ensures that clean doesn't fail if file to be deleted doesn't exist
clean:
	rm -f $(EXE) *.o

# recompile runs clean and then makes everything again to generate executable
# this is equivalent to running "make clean" followed by "make"
recompile: clean $(EXE)

#
# Run the Clang Static Analyzer
#
scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

#
# View the one scan available using firefox
#
scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html
