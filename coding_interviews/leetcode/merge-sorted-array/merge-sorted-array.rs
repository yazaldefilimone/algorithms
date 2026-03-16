impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut i = m as isize - 1;
        let mut j = n as isize - 1;
        let mut k = (m + n) as isize - 1;

        while i >= 0 && j >= 0 {
            if nums1[i as usize] > nums2[j as usize] {
                nums1[k as usize] = nums1[i as usize];
                i -= 1;
            } else {
                nums1[k as usize] = nums2[j as usize];
                j -= 1;
            }
            k -= 1;
        }

        while j >= 0 {
            nums1[k as usize] = nums2[j as usize];
            j -= 1;
            k -= 1;
        }
    }
}
