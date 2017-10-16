all: linked_List.c
	gcc -o linked_list linked_List.c
run: all
	./linked_list
