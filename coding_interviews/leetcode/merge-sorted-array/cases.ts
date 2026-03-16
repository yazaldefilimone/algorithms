import { arrays_equal } from "utils/array";
import { run_cases, type TestCase } from "utils/test_cases";
import { merge } from "leetcode/merge-sorted-array";

const cases: TestCase<[number[], number, number[], number], number[]>[] = [
  {
    input: [[1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3],
    expected: [1, 2, 2, 3, 5, 6],
    description: "merge overlapping arrays",
  },
  {
    input: [[1], 1, [], 0],
    expected: [1],
    description: "single element, no merge",
  },
  {
    input: [[0], 0, [1], 1],
    expected: [1],
    description: "empty nums1, all from nums2",
  },
  {
    input: [[0, 1], 1, [2], 1],
    expected: [1, 2],
    description: "empty nums1, all from nums2",
  },
];

const executor = (nums1: number[], m: number, nums2: number[], n: number) => {
  merge(nums1, m, nums2, n);
  return nums1;
};

run_cases(executor, cases, arrays_equal);
