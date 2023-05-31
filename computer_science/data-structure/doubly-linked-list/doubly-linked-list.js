class Node {
  constructor(value, prev, next) {
    this.value = value;
    this.prev = prev ?? null;
    this.next = next ?? null;
  }
}

export class DoublyLinkedList {
  constructor(value) {
    const node = new Node(value, null, null);
    this.head = node;
    this.tail = node;
    this.len = 1;
  }

  push(value) {
    const node = new Node(value, null, null);
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      node.prev = this.tail;
      this.tail = node;
    }
    this.len++;
  }

  pop() {
    if (this.len === 0) return undefined;
    const temp = this.tail;
    if (this.len === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = temp.prev;
      this.tail.next = null;
      temp.prev = null;
    }
    this.len--;
    return temp;
  }
}
