#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next;};

void print_list(struct node * node){
  while(node){
    printf("value:%d\n", node -> i);
    node = node -> next;
  }//printf("value:%d\n", node -> i);
}

struct node * insert_front(struct node * node, int x){
  struct node *f = (struct node *) malloc(sizeof(struct node));
  f->next = node;
  f->i = x;
  return f;
}

struct node * free_list(struct node * node){
  while(node -> next){
    free(node);
    node = node -> next;
  }
  free(node);
  return 0;
}

int main(){
  struct node *list = insert_front(NULL, 10);
  int i = 9;
  for(; i >= 0; i--){
    list = insert_front(list, i);
  }printf("VALUES BEFORE FREEING MEMORY:\n\n");
  print_list(list);
  printf("\nVALUES AFTER FREEING MEMORY:\n\n");
  list = free_list(list);
  print_list(list);
  return 0;
}

