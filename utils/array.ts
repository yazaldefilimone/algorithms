export function arrays_equal<T>(a: T[], b: T[]): boolean {
  if (a.length !== b.length) return false;
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) return false;
  }
  return true;
}

export function cloneArray<T>(arr: T[]): T[] {
  return [...arr];
}

export function matrix_equal<T>(a: T[][], b: T[][]): boolean {
  if (a.length !== b.length) return false;
  for (let i = 0; i < a.length; i++) {
    if (!arrays_equal(a[i], b[i])) return false;
  }
  return true;
}

export function print_array<T>(arr: T[]): void {
  console.log(arr.join(", "));
}

export function print_matrix<T>(matrix: T[][]): void {
  for (const row of matrix) {
    console.log(row.join(", "));
  }
}

export function assert_equal<T>(actual: T, expected: T, message?: string): void {
  if (actual !== expected) {
    throw new Error(message || `expected ${expected}, got ${actual}`);
  }
}

export function assert_arrays_equal<T>(actual: T[], expected: T[], message?: string): void {
  if (!arrays_equal(actual, expected)) {
    throw new Error(message || `expected [${expected}], got [${actual}]`);
  }
}

export function assert_matrix_equal<T>(actual: T[][], expected: T[][], message?: string): void {
  if (!matrix_equal(actual, expected)) {
    throw new Error(
      message || `expected ${JSON.stringify(expected)}, got ${JSON.stringify(actual)}`,
    );
  }
}
