pub fn binary_search(arr: &[i32], target: i32) -> Option<usize> {
  let mut left = 0;
  let mut right = arr.len();

  while left < right {
    let mid = left + (right - left) / 2;
    if arr[mid] == target {
      return Some(mid);
    } else if arr[mid] < target {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  None
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_found() {
    let arr = [-1, 0, 3, 5, 9, 12];
    assert_eq!(binary_search(&arr, 9), Some(4));
    assert_eq!(binary_search(&arr, -1), Some(0));
    assert_eq!(binary_search(&arr, 12), Some(5));
  }

  #[test]
  fn test_not_found() {
    let arr = [-1, 0, 3, 5, 9, 12];
    assert_eq!(binary_search(&arr, 2), None);
  }
}
