CC = gcc
CFLAGS = -Wall -pedantic
BSTDIR = ../bst_recur/src
CPPFLAGS = -I$(BSTDIR)
SRCDIR = .
BUILDDIR = build

.PHONY: all clean insert_test main removal_test search_test traversal_test

all: $(BUILDDIR)/insert_test $(BUILDDIR)/main $(BUILDDIR)/removal_test \
     $(BUILDDIR)/search_test $(BUILDDIR)/traversal_test

insert_test: $(BUILDDIR)/insert_test

main: $(BUILDDIR)/main

removal_test: $(BUILDDIR)/removal_test

search_test: $(BUILDDIR)/search_test

traversal_test: $(BUILDDIR)/traversal_test

$(BUILDDIR):
	mkdir -p $@

$(BUILDDIR)/element.o: $(BSTDIR)/element.c $(BSTDIR)/element.h | $(BUILDDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILDDIR)/bst.o: $(BSTDIR)/bst.c $(BSTDIR)/bst.h | $(BUILDDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILDDIR)/insert_test: $(SRCDIR)/insert_test.c $(BUILDDIR)/bst.o $(BUILDDIR)/element.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILDDIR)/main: $(SRCDIR)/main.c $(BUILDDIR)/bst.o $(BUILDDIR)/element.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILDDIR)/removal_test: $(SRCDIR)/removal_test.c $(BUILDDIR)/bst.o $(BUILDDIR)/element.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILDDIR)/search_test: $(SRCDIR)/search_test.c $(BUILDDIR)/element.o | $(BUILDDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILDDIR)/traversal_test: $(SRCDIR)/traversal_test.c $(BUILDDIR)/element.o | $(BUILDDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^

clean:
	rm -rf $(BUILDDIR)
