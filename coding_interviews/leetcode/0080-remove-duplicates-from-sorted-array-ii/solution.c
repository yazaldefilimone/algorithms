#include <assert.h>
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize <= 2) {
    return numsSize;
  }

  int k = 2;
  for (int i = 2; i < numsSize; i++) {
    if (nums[i] != nums[k - 2]) {
      nums[k++] = nums[i];
    }
  }
  return k;
}

int main(void) {
  // Caso 1: [1,1,1,2,2,3] -> k = 5, nums = [1,1,2,2,3]
  int nums1[] = {1, 1, 1, 2, 2, 3};
  int k1 = removeDuplicates(nums1, 6);
  assert(k1 == 5);
  int expected1[] = {1, 1, 2, 2, 3};
  for (int i = 0; i < k1; i++) {
    assert(nums1[i] == expected1[i]);
  }

  // Caso 2: [0,0,1,1,1,1,2,3,3] -> k = 7, nums = [0,0,1,1,2,3,3]
  int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  int k2 = removeDuplicates(nums2, 9);
  assert(k2 == 7);
  int expected2[] = {0, 0, 1, 1, 2, 3, 3};
  for (int i = 0; i < k2; i++) {
    assert(nums2[i] == expected2[i]);
  }

  printf("ok\n");
  return 0;
}
