export type TestCase<Input extends any[], Output> = {
  input: Input;
  expected: Output;
  description?: string;
};

const GREEN = "\x1b[32m";
const RED = "\x1b[31m";
const RESET = "\x1b[0m";

export function run_cases<Input extends any[], Output>(
  fn: (input: Input, expected: Output) => Output,
  cases: TestCase<Input, Output>[],
  compare: (a: Output, b: Output) => boolean,
) {
  cases.forEach((tc, index) => {
    const result = fn(tc.input, tc.expected);
    const description = tc.description || "";
    if (compare(result, tc.expected)) {
      const success = `${GREEN}case ${index + 1} passed${RESET}`;
      console.log(`${success}${description ? `: ${description}` : ""}`);
    } else {
      const error = `${RED}case ${index + 1} failed${RESET}`;
      console.error(`${error}${description ? `: ${description}` : ""}`);
    }
  });
  // console.log(`all ${passed} cases passed`);
}
