#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge(int *arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));
  assert(L && R);

  memcpy(L, arr + left, n1 * sizeof(int));
  memcpy(R, arr + mid + 1, n2 * sizeof(int));

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];

  free(L);
  free(R);
}

void merge_sort(int *arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main(void) {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int expected[] = {3, 9, 10, 27, 38, 43, 82};

  merge_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    assert(arr[i] == expected[i]);
  }

  printf("ok\n");
  return 0;
}
