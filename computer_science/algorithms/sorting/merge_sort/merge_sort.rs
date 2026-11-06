pub fn merge_sort(arr: &mut [i32]) {
  let len = arr.len();
  if len <= 1 {
    return;
  }

  let mid = len / 2;
  merge_sort(&mut arr[..mid]);
  merge_sort(&mut arr[mid..]);

  let mut merged = Vec::with_capacity(len);
  let mut i = 0;
  let mut j = mid;

  while i < mid && j < len {
    if arr[i] <= arr[j] {
      merged.push(arr[i]);
      i += 1;
    } else {
      merged.push(arr[j]);
      j += 1;
    }
  }

  while i < mid {
    merged.push(arr[i]);
    i += 1;
  }

  while j < len {
    merged.push(arr[j]);
    j += 1;
  }

  arr.copy_from_slice(&merged);
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_merge_sort() {
    let mut arr = vec![38, 27, 43, 3, 9, 82, 10];
    merge_sort(&mut arr);
    assert_eq!(arr, vec![3, 9, 10, 27, 38, 43, 82]);
  }

  #[test]
  fn test_already_sorted() {
    let mut arr = vec![1, 2, 3, 4, 5];
    merge_sort(&mut arr);
    assert_eq!(arr, vec![1, 2, 3, 4, 5]);
  }
}
