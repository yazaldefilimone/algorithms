pub struct DynamicArray<T> {
  data: Vec<T>,
}

impl<T> DynamicArray<T> {
  pub fn new() -> Self {
    DynamicArray { data: Vec::new() }
  }

  pub fn with_capacity(capacity: usize) -> Self {
    DynamicArray { data: Vec::with_capacity(capacity) }
  }

  pub fn push(&mut self, val: T) {
    self.data.push(val);
  }

  pub fn pop(&mut self) -> Option<T> {
    self.data.pop()
  }

  pub fn get(&self, index: usize) -> Option<&T> {
    self.data.get(index)
  }

  pub fn len(&self) -> usize {
    self.data.len()
  }

  pub fn is_empty(&self) -> bool {
    self.data.is_empty()
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_push_pop() {
    let mut arr = DynamicArray::new();
    assert!(arr.is_empty());

    arr.push(10);
    arr.push(20);
    arr.push(30);

    assert_eq!(arr.len(), 3);
    assert_eq!(arr.get(1), Some(&20));
    assert_eq!(arr.pop(), Some(30));
    assert_eq!(arr.len(), 2);
  }
}
