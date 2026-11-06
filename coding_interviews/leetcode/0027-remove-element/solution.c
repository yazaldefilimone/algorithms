#include <assert.h>
#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
  int k = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != val) {
      nums[k++] = nums[i];
    }
  }
  return k;
}

int main(void) {
  // Caso 1: nums = [3,2,2,3], val = 3 -> k = 2, nums = [2,2]
  int nums1[] = {3, 2, 2, 3};
  int k1 = removeElement(nums1, 4, 3);
  assert(k1 == 2);
  assert(nums1[0] == 2 && nums1[1] == 2);

  // Caso 2: nums = [0,1,2,2,3,0,4,2], val = 2 -> k = 5
  int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
  int k2 = removeElement(nums2, 8, 2);
  assert(k2 == 5);
  int expected2[] = {0, 1, 3, 0, 4};
  for (int i = 0; i < k2; i++) {
    assert(nums2[i] == expected2[i]);
  }

  printf("ok\n");
  return 0;
}
