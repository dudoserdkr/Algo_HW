class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = None
        self.element_count = 0

    def push(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        self.element_count += 1

    def pop(self):
        if self.head is None:
            raise Exception('Stack is empty')

        elem = self.head.data
        self.head = self.head.next
        self.element_count -= 1
        return elem

    def is_empty(self):
        return self.head is None

if __name__ == '__main__':
    bracket_sequence = input().strip()

    BRACKETS = {"(": ")", "[": "]", "{": "}"}

    stack = Stack()

    for bracket in bracket_sequence:
        if bracket in BRACKETS.keys():
            stack.push(bracket)
        else:
            if stack.is_empty():
                print("no")
                break
            popped_bracket = stack.pop()
            if BRACKETS[popped_bracket] != bracket:
                print("no")
                break
    else:
        if stack.is_empty():
            print("yes")
        else:
            print("no")
