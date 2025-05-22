
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  int *data;
} arry;

arry *arry_new(int size) {
  arry *arry = malloc(sizeof(arry));
  arry->size = size;
  arry->data = malloc(sizeof(int) * size);
  return arry;
}

void arry_free(arry *arry) {
  free(arry->data);
  free(arry);
}

void arry_print(arry *arry) {
  int i;
  for (i = 0; i < arry->size; i++) {
    printf("%d ", arry->data[i]);
  }
  printf("\n");
}

int arry_get(arry *arry, int index) { return arry->data[index]; }

void arry_set(arry *arry, int index, int value) { arry->data[index] = value; }

int arry_size(arry *arry) { return arry->size; }

void arry_resize(arry *arry, int size) {
  arry->size = size;
  arry->data = realloc(arry->data, sizeof(int) * size);
}

int main() {
  arry *arry = arry_new(5);
  arry_print(arry);
  arry_set(arry, 0, 1);
  arry_set(arry, 1, 2);
  arry_set(arry, 2, 3);
  arry_set(arry, 3, 4);
  arry_set(arry, 4, 5);
  arry_print(arry);
  arry_resize(arry, 10);
  arry_print(arry);
  arry_free(arry);
  return 0;
}
