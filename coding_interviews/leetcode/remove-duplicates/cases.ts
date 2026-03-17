import { run_cases, type TestCase } from "utils/test_cases";
import { removeDuplicates } from "./remove-duplicates";
import { arrays_equal } from "utils/array";

const cases: TestCase<number[], number[]>[] = [
  {
    input: [1, 1, 2],
    expected: [1, 2],
    description: "remover duplicados simples",
  },
  {
    input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
    expected: [0, 1, 2, 3, 4],
    description: "array com multiplos duplicados",
  },
  {
    input: [1, 2, 3, 4],
    expected: [1, 2, 3, 4],
    description: "array sem duplicados",
  },
  {
    input: [1, 1, 1, 1],
    expected: [1],
    description: "todos iguais",
  },
  {
    input: [],
    expected: [],
    description: "array vazio",
  },
];

const executor = (nums: number[]) => {
  console.log({ nums });
  const k = removeDuplicates(nums);
  console.log({ nums, k, slice: nums.slice(0, k) });
  return nums.slice(0, k);
};

run_cases(executor, cases, arrays_equal);
