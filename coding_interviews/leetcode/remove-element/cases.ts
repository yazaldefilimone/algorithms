import { run_cases, type TestCase } from "utils/test_cases";
import { removeElement } from "./remove-element";
import { arrays_equal } from "utils/array";
import { assert } from "utils/value";

const cases: TestCase<[number[], number], number[]>[] = [
  {
    input: [[3, 2, 2, 3], 3],
    expected: [2, 2],
    description: "remove all 3s",
  },
  {
    input: [[0, 1, 2, 2, 3, 0, 4, 2], 2],
    expected: [0, 1, 3, 0, 4],
    description: "remove all 2s, mixed array",
  },
  {
    input: [[1, 1, 1], 1],
    expected: [],
    description: "all elements are val",
  },
  {
    input: [[0, 1, 2, 3, 4], 5],
    expected: [0, 1, 2, 3, 4],
    description: "val not in array",
  },
  {
    input: [[], 0],
    expected: [],
    description: "empty array",
  },
  {
    input: [[2], 3],
    expected: [2],
    description: "next array",
  },
];

const executor = (input: [number[], number], expected: number[]) => {
  const [nums, val] = input;
  const index = removeElement(nums, val);
  assert(index === expected.length, `expected length ${expected.length}, got ${index}`);
  return nums.slice(0, expected.length);
};

run_cases(executor, cases, arrays_equal);
