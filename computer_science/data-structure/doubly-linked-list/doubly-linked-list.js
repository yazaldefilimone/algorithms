export class Node {
  constructor(value, prev, next) {
    this.value = value;
    this.prev = prev ?? null;
    this.next = next ?? null;
  }
}

export class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  push(value) {
    const node = new Node(value);
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      node.prev = this.tail;
      this.tail = node;
    }
    this.length++;
  }
  unshift(value) {
    const node = new Node(value);
    if (!this.head) {
      this.head = node;
      this.tail = node;
    } else {
      this.head.prev = node;
      node.next = this.head;
      this.head = node;
    }
    this.length++;
  }
  pop() {
    if (this.length === 0) return undefined;
    const temp = this.tail;
    if (this.length === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = temp.prev;
      this.tail.next = null;
      temp.prev = null;
    }
    this.length--;
    return temp;
  }
  shift() {
    if (!this.head) {
      return null;
    }
    const temp = this.head;
    this.head = this.head.next;
    if (this.head) {
      this.head.prev = null;
    }
    temp.next = null;
    this.length--;
    return temp;
  }

  get(index) {
    if (!this.head || index > this.length || index == 0) {
      return undefined;
    }

    let temp = this.head;
    if (index < this.length / 2) {
      for (let idx = 1; idx < index; idx++) {
        temp = temp.next;
      }
    } else {
      temp = this.tail;
      for (let idx = this.length; idx > index; idx--) {
        temp = temp.prev;
      }
    }
    return temp;
  }



  set(index, value) {
    const node = this.get(index);
    if (node) {
      node.value = value;
      return true;
    }

    return false;
  }

  insert(index, value) {
    if (index > this.length || index <= 0) return false;
    if (index === 1) {
      this.unshift(value);
      return true;
    }
    if (index === this.length) {
      this.push(value);
      return true;
    }
    const before = this.get(index - 1);
    const after = before.next;
    const node = new Node(value);
    before.next = node;
    node.prev = before;
    node.next = after;
    after.prev = node;
    this.length++;
    return true;
  }
  remove(index) {
    if (index > this.length || index <= 0) return undefined;
    if (index === 1) return this.shift();
    if (index === this.length) return this.pop();
    const temp = this.get(index);
    let before = temp.prev;
    let after = temp.next;
    before.next = after;
    after.prev = before;
    temp.next = null;
    temp.prev = null;
    this.length--;
    return temp;
  }
}
