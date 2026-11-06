#include <assert.h>
#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  (void)nums1Size;
  (void)nums2Size;

  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;

  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) {
      nums1[k--] = nums1[i--];
    } else {
      nums1[k--] = nums2[j--];
    }
  }

  while (j >= 0) {
    nums1[k--] = nums2[j--];
  }
}

int main(void) {
  // Caso 1: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
  int nums1[6] = {1, 2, 3, 0, 0, 0};
  int nums2[3] = {2, 5, 6};
  merge(nums1, 6, 3, nums2, 3, 3);
  int expected1[6] = {1, 2, 2, 3, 5, 6};
  for (int idx = 0; idx < 6; idx++) {
    assert(nums1[idx] == expected1[idx]);
  }

  // Caso 2: nums1 = [1], m = 1, nums2 = [], n = 0
  int nums3[1] = {1};
  int nums4[1] = {0};
  merge(nums3, 1, 1, nums4, 0, 0);
  assert(nums3[0] == 1);

  // Caso 3: nums1 = [0], m = 0, nums2 = [1], n = 1
  int nums5[1] = {0};
  int nums6[1] = {1};
  merge(nums5, 1, 0, nums6, 1, 1);
  assert(nums5[0] == 1);

  printf("ok\n");
  return 0;
}
