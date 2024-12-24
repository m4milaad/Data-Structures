class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.is_empty():
            print("Stack Underflow")
            return None
        data = self.top.data
        self.top = self.top.next
        return data

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
            return None
        return self.top.data

    def print_list(self):
        current = self.top
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

    def is_empty(self):
        return self.top is None

# Main program
if __name__ == "__main__":
    stack = Stack()

    while True:
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Print list")
        print("0. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter number to push: "))
            stack.push(n)
        elif choice == 2:
            result = stack.pop()
            if result is not None:
                print(f"\t\t\tPopped: {result}")
        elif choice == 3:
            result = stack.peek()
            if result is not None:
                print(f"\t\t\tPeeked at: {result}")
        elif choice == 4:
            stack.print_list()
        elif choice == 0:
            print("\t\t\tThank you\nExiting...")
            break
        else:
            print("Option does not exist, try again...")
