CC = gcc -Wall -pedantic
CPPFLAGS = -Isrc

build_dir:
	mkdir -p build

element: build_dir
	$(CC) $(CPPFLAGS) -c -o build/element.o src/element.c

bst: element
	$(CC) $(CPPFLAGS) -c -o build/bst.o src/bst.c

main: bst
	$(CC) -o build/main src/main.c build/bst.o build/element.o

search_test: element
	$(CC) -o build/search_test src/search_test.c build/element.o

clean:
	rm -rf build