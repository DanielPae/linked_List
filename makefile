all: linked_lists.c
	gcc -o linked_lists linked_lists.c
run: all
	./linked_lists
