pub struct Node<T> {
  pub val: T,
  pub next: Option<Box<Node<T>>>,
}

pub struct LinkedList<T> {
  head: Option<Box<Node<T>>>,
  size: usize,
}

impl<T> LinkedList<T> {
  pub fn new() -> Self {
    LinkedList { head: None, size: 0 }
  }

  pub fn push_front(&mut self, val: T) {
    let new_node = Box::new(Node { val, next: self.head.take() });
    self.head = Some(new_node);
    self.size += 1;
  }

  pub fn pop_front(&mut self) -> Option<T> {
    self.head.take().map(|node| {
      self.head = node.next;
      self.size -= 1;
      node.val
    })
  }

  pub fn peek_front(&self) -> Option<&T> {
    self.head.as_ref().map(|node| &node.val)
  }

  pub fn len(&self) -> usize {
    self.size
  }

  pub fn is_empty(&self) -> bool {
    self.size == 0
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn test_push_and_pop() {
    let mut list = LinkedList::new();
    assert!(list.is_empty());

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    assert_eq!(list.len(), 3);
    assert_eq!(list.peek_front(), Some(&30));

    assert_eq!(list.pop_front(), Some(30));
    assert_eq!(list.pop_front(), Some(20));
    assert_eq!(list.pop_front(), Some(10));
    assert_eq!(list.pop_front(), None);
    assert!(list.is_empty());
  }
}
