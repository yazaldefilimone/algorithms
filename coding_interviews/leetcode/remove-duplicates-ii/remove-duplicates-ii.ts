export function removeDuplicates(nums: number[]): number {
  let k = 2;
  for (let idx = 2; idx < nums.length; idx++) {
    if (nums[idx] != nums[k - 2]) {
      nums[k] = nums[idx];
      k += 1;
    }
  }
  return k;
}
