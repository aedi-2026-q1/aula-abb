CC = gcc -Wall -pedantic
CPPFLAGS = -Isrc
UNIT_TEST_CFLAGS = -Wall -Wextra -pedantic -std=c11

build_dir:
	mkdir -p build

bst_node: build_dir
	$(CC) $(CPPFLAGS) -c -o build/bst_node.o src/bst_node.c

stack_element: bst_node
	$(CC) $(CPPFLAGS) -c -o build/stack_element.o src/stack_element.c

stack: stack_element
	$(CC) $(CPPFLAGS) -c -o build/stack.o src/stack.c

bst_element: build_dir
	$(CC) $(CPPFLAGS) -c -o build/bst_element.o src/bst_element.c

bst: bst_node stack_element stack bst_element
	$(CC) $(CPPFLAGS) -c -o build/bst.o src/bst.c

main: bst
	$(CC) $(CPPFLAGS) -o build/main src/main.c build/bst.o build/bst_element.o build/bst_node.o build/stack_element.o build/stack.o

tests: build_dir
	$(CC) $(UNIT_TEST_CFLAGS) $(CPPFLAGS) -o build/test_bst_iter src/bst.c src/bst_node.c src/bst_element.c src/stack_element.c src/stack.c tests/test_bst_iter.c

tests_run: tests
	./build/test_bst_iter

clean:
	rm -rf build