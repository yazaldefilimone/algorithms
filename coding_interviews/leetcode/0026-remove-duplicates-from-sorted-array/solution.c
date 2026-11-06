#include <assert.h>
#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize <= 1) {
    return numsSize;
  }

  int k = 1;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] != nums[k - 1]) {
      nums[k++] = nums[i];
    }
  }
  return k;
}

int main(void) {
  // Caso 1: [1, 1, 2] -> k = 2, nums = [1, 2]
  int nums1[] = {1, 1, 2};
  int k1 = removeDuplicates(nums1, 3);
  assert(k1 == 2);
  assert(nums1[0] == 1 && nums1[1] == 2);

  // Caso 2: [0,0,1,1,1,2,2,3,3,4] -> k = 5, nums = [0,1,2,3,4]
  int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k2 = removeDuplicates(nums2, 10);
  assert(k2 == 5);
  int expected2[] = {0, 1, 2, 3, 4};
  for (int i = 0; i < k2; i++) {
    assert(nums2[i] == expected2[i]);
  }

  // Caso 3: Array vazio ou de 1 elemento
  int nums3[] = {42};
  int k3 = removeDuplicates(nums3, 1);
  assert(k3 == 1 && nums3[0] == 42);

  printf("ok\n");
  return 0;
}
