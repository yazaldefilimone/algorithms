export function removeDuplicates(nums: number[]): number {
  let k = 1;
  for (let index = 1; index < nums.length; index++) {
    if (nums[index] != nums[k - 1]) {
      nums[k] = nums[index];
      k++;
    }
  }
  return k;
}
