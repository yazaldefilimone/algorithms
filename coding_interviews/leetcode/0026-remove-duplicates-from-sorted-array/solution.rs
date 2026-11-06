pub struct Solution;

impl Solution {
  pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    if nums.len() <= 1 {
      return nums.len() as i32;
    }

    let mut k = 1;
    for i in 1..nums.len() {
      if nums[i] != nums[k - 1] {
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
    let mut nums = vec![1, 1, 2];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 2);
    assert_eq!(&nums[..k as usize], &[1, 2]);
  }

  #[test]
  fn test_case_2() {
    let mut nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 5);
    assert_eq!(&nums[..k as usize], &[0, 1, 2, 3, 4]);
  }

  #[test]
  fn test_single_element() {
    let mut nums = vec![42];
    let k = Solution::remove_duplicates(&mut nums);
    assert_eq!(k, 1);
    assert_eq!(&nums[..k as usize], &[42]);
  }
}
