import { run_cases, type TestCase } from "utils/test_cases";
import { removeDuplicates } from "./remove-duplicates-ii";
import { arrays_equal } from "utils/array";

const cases: TestCase<number[], number[]>[] = [
  {
    input: [1, 1, 1, 2, 2, 3],
    expected: [1, 1, 2, 2, 3],
    description: "allow at most two duplicates",
  },
  {
    input: [0, 0, 1, 1, 1, 1, 2, 3, 3],
    expected: [0, 0, 1, 1, 2, 3, 3],
    description: "multiple duplicates",
  },
  {
    input: [1, 1, 2, 2, 3, 3],
    expected: [1, 1, 2, 2, 3, 3],
    description: "already valid",
  },
  {
    input: [1, 1, 1, 1],
    expected: [1, 1],
    description: "all same, keep two",
  },
  {
    input: [1, 2, 3, 4],
    expected: [1, 2, 3, 4],
    description: "no duplicates",
  },
  {
    input: [1],
    expected: [1],
    description: "single element",
  },
  {
    input: [],
    expected: [],
    description: "empty array",
  },
];

const executor = (nums: number[]) => {
  const values = removeDuplicates(nums);
  return nums.slice(0, values);
};

run_cases(executor, cases, arrays_equal);
