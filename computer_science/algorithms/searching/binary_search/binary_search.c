#include <assert.h>
#include <stdio.h>

int binary_search(const int *arr, int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main(void) {
  int arr[] = {-1, 0, 3, 5, 9, 12};
  int size = sizeof(arr) / sizeof(arr[0]);

  assert(binary_search(arr, size, 9) == 4);
  assert(binary_search(arr, size, -1) == 0);
  assert(binary_search(arr, size, 12) == 5);
  assert(binary_search(arr, size, 2) == -1);

  printf("ok\n");
  return 0;
}
