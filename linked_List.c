#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next;};

void print_list(struct node * node){
  while(node -> next){
    printf("value:%d\n", node -> i);
    node = node -> next;
  }printf("value:%d\n", node -> i);
}

struct node * insert_front(struct node * node, int x){
  struct node *f = (struct node *)malloc(sizeof(struct node));
  f->next = node;
  f->i = x;
  return f;
}

struct node * free_list(struct node * node){
    struct node * beginning = node;
  while(node -> next){
    free(node);
    node = node -> next;
  }
  free(node);
  return beginning;
}

int main(){
    struct node *list = insert_front(NULL, 0);
  int i = 1;
  for(; i < 10; i++){
    list = insert_front(list, i);
  }printf("VALUES BEFORE FREEING MEMORY:\n\n");
  print_list(list);
  printf("\nVALUES AFTER FREEING MEMORY:\n\n");
  free_list(list);
  print_list(list);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next;};

void print_list(struct node * node){
  while(node -> next){
    printf("value:%d\n", node -> i);
    node = node -> next;
  }printf("value:%d\n", node -> i);
}

struct node * insert_front(struct node * node, int x){
  struct node *f = (struct node *)malloc(sizeof(struct node));
  f->next = node;
  f->i = x;
  return f;
}

struct node * free_list(struct node * node){
  while(node -> next){
    struct node * f = node -> next;
    free(node);
    printf("node: %p\nf: %p", node, f);
    node = f;
  }free(node);
  return node;
}

int main(){
  struct node org;
  org.i = 0;
  org.next = NULL;
  struct node *list = &org;
  int i = 1;
  for(; i < 10; i++){
    list = insert_front(list, i);
  }print_list(list);
  free_list(list);
  print_list(list);
  return 0;
}
