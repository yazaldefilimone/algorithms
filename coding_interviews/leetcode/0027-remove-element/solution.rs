pub struct Solution;

impl Solution {
  pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut k = 0;
    for i in 0..nums.len() {
      if nums[i] != val {
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
    let mut nums = vec![3, 2, 2, 3];
    let k = Solution::remove_element(&mut nums, 3);
    assert_eq!(k, 2);
    assert_eq!(&nums[..k as usize], &[2, 2]);
  }

  #[test]
  fn test_case_2() {
    let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
    let k = Solution::remove_element(&mut nums, 2);
    assert_eq!(k, 5);
    assert_eq!(&nums[..k as usize], &[0, 1, 3, 0, 4]);
  }

  #[test]
  fn test_all_matching() {
    let mut nums = vec![1, 1, 1];
    let k = Solution::remove_element(&mut nums, 1);
    assert_eq!(k, 0);
  }
}
