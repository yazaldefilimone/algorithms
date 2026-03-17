export function removeElement(nums: number[], val: number): number {
  let count = 0;
  const len = nums.length;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === val) {
      count++;
      nums.splice(i, 1);
      i--;
    }
  }

  return len - count;
}
