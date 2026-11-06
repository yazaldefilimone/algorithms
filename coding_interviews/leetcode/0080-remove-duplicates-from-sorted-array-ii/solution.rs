pub struct Solution;

impl Solution {
  pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    if nums.len() <= 2 {
      return nums.len() as i32;
    }

    let mut k = 2;
    for i in 2..nums.len() {
      if nums[i] != nums[k - 2] {
        nums[k] = nums[i];
        k += 1;
      }
    }
    k as i32
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_case_1() {
    let mut nums = vec![1, 1, 1, 2, 2, 3];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 5);
    assert_eq!(&nums[..k as usize], &[1, 1, 2, 2, 3]);
  }

  #[test]
  fn test_case_2() {
    let mut nums = vec![0, 0, 1, 1, 1, 1, 2, 3, 3];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 7);
    assert_eq!(&nums[..k as usize], &[0, 0, 1, 1, 2, 3, 3]);
  }

  #[test]
  fn test_short_array() {
    let mut nums = vec![1, 1];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 2);
  }
}
