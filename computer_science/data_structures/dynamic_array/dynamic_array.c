#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *darray_create(size_t initial_capacity) {
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  if (!arr)
    return NULL;
  arr->capacity = initial_capacity > 0 ? initial_capacity : 2;
  arr->size = 0;
  arr->data = (int *)malloc(arr->capacity * sizeof(int));
  if (!arr->data) {
    free(arr);
    return NULL;
  }
  return arr;
}

void darray_push(DynamicArray *arr, int val) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    int *new_data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    assert(new_data != NULL);
    arr->data = new_data;
  }
  arr->data[arr->size++] = val;
}

bool darray_pop(DynamicArray *arr, int *out_val) {
  if (arr->size == 0)
    return false;
  arr->size--;
  if (out_val)
    *out_val = arr->data[arr->size];
  return true;
}

int darray_get(const DynamicArray *arr, size_t index) {
  assert(index < arr->size);
  return arr->data[index];
}

void darray_free(DynamicArray *arr) {
  if (arr) {
    free(arr->data);
    free(arr);
  }
}

int main(void) {
  DynamicArray *arr = darray_create(2);
  assert(arr != NULL);
  assert(arr->size == 0);
  assert(arr->capacity == 2);

  darray_push(arr, 100);
  darray_push(arr, 200);
  darray_push(arr, 300); // Trigger resize: capacity becomes 4
  assert(arr->size == 3);
  assert(arr->capacity == 4);

  assert(darray_get(arr, 0) == 100);
  assert(darray_get(arr, 1) == 200);
  assert(darray_get(arr, 2) == 300);

  int popped;
  assert(darray_pop(arr, &popped) == true);
  assert(popped == 300);
  assert(arr->size == 2);

  darray_free(arr);
  printf("ok\n");
  return 0;
}
