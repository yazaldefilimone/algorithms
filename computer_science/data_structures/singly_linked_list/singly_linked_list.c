#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  size_t size;
} LinkedList;

LinkedList *list_create(void) {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (!list)
    return NULL;
  list->head = NULL;
  list->size = 0;
  return list;
}

void list_push_front(LinkedList *list, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  assert(new_node != NULL);
  new_node->val = val;
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void list_push_back(LinkedList *list, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  assert(new_node != NULL);
  new_node->val = val;
  new_node->next = NULL;

  if (!list->head) {
    list->head = new_node;
  } else {
    Node *curr = list->head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
  list->size++;
}

bool list_pop_front(LinkedList *list, int *out_val) {
  if (!list->head)
    return false;

  Node *temp = list->head;
  if (out_val)
    *out_val = temp->val;
  list->head = temp->next;
  free(temp);
  list->size--;
  return true;
}

bool list_delete(LinkedList *list, int val) {
  Node **curr = &list->head;
  while (*curr) {
    if ((*curr)->val == val) {
      Node *to_remove = *curr;
      *curr = (*curr)->next;
      free(to_remove);
      list->size--;
      return true;
    }
    curr = &(*curr)->next;
  }
  return false;
}

void list_free(LinkedList *list) {
  Node *curr = list->head;
  while (curr) {
    Node *next = curr->next;
    free(curr);
    curr = next;
  }
  free(list);
}

int main(void) {
  LinkedList *list = list_create();
  assert(list != NULL);
  assert(list->size == 0);

  list_push_back(list, 10);
  list_push_back(list, 20);
  list_push_front(list, 5);
  // [5, 10, 20]
  assert(list->size == 3);

  int val;
  assert(list_pop_front(list, &val) == true);
  assert(val == 5);
  assert(list->size == 2);

  assert(list_delete(list, 10) == true);
  assert(list->size == 1);
  assert(list_delete(list, 999) == false);

  list_free(list);
  printf("ok\n");
  return 0;
}
