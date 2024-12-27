use std::io;

struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

struct LinkedList {
    head: Option<Box<Node>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn create(&mut self) {
        if self.head.is_some() {
            println!("List is already created. You can now add or delete nodes.");
            return;
        }

        println!("Enter the number of nodes you want to create: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let no: usize = input.trim().parse().expect("Invalid input");

        if no == 0 {
            println!("Invalid input. Number of nodes should be a positive integer.");
            return;
        }

        for i in 1..=no {
            println!("Enter the data in node {}: ", i);
            input.clear();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            let data: i32 = input.trim().parse().expect("Invalid input");

            let new_node = Box::new(Node { data, next: None });
            if self.head.is_none() {
                self.head = Some(new_node);
            } else {
                let mut current = &mut self.head;
                while current.as_mut().unwrap().next.is_some() {
                    current = &mut current.as_mut().unwrap().next;
                }
                current.as_mut().unwrap().next = Some(new_node);
            }
        }
    }

    fn print_list(&self) {
        if self.head.is_none() {
            println!("\nNo nodes created.\n");
            return;
        }

        let mut current = &self.head;
        print!("The linked list is: ");
        while let Some(ref node) = current {
            print!("{} ", node.data);
            current = &node.next;
        }
        println!();
    }

    fn insert_node(&mut self) {
        if self.head.is_none() {
            println!("No nodes created. Please create the Linked List first.");
            return;
        }

        let mut input = String::new();
        println!("Enter the position you want to add node at (1-{}): ", self.count_nodes());
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let pos: usize = input.trim().parse().expect("Invalid input");

        println!("Enter the data you want to add in new node: ");
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let data: i32 = input.trim().parse().expect("Invalid input");

        let mut new_node = Box::new(Node { data, next: None });

        if pos == 1 {
            new_node.next = self.head.take();
            self.head = Some(new_node);
        } else {
            let mut current = &mut self.head;
            for _ in 0..pos - 2 {
                if current.as_mut().unwrap().next.is_none() {
                    println!("Position does not exist.");
                    return;
                }
                current = &mut current.as_mut().unwrap().next;
            }
            new_node.next = current.as_mut().unwrap().next.take();
            current.as_mut().unwrap().next = Some(new_node);
        }
    }

    fn delete_node(&mut self) {
        if self.head.is_none() {
            println!("No nodes available to delete.");
            return;
        }

        let mut input = String::new();
        println!("Enter the node position you want to delete (1-{}): ", self.count_nodes());
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let pos: usize = input.trim().parse().expect("Invalid input");

        if pos == 1 {
            self.head = self.head.take().and_then(|node| node.next);
        } else {
            let mut current = &mut self.head;
            for _ in 0..pos - 2 {
                if current.as_mut().unwrap().next.is_none() {
                    println!("Invalid position.");
                    return;
                }
                current = &mut current.as_mut().unwrap().next;
            }
            let target_node = current.as_mut().unwrap().next.take();
            current.as_mut().unwrap().next = target_node.and_then(|node| node.next);
        }
    }

    fn reverse(&mut self) {
        let mut prev = None;
        let mut current = self.head.take();

        while let Some(mut node) = current {
            current = node.next.take();
            node.next = prev;
            prev = Some(node);
        }
        self.head = prev;
    }

    fn free_list(&mut self) {
        self.head = None;
    }

    fn sort_list(&mut self) {
        let mut swapped = true;
        while swapped {
            swapped = false;
            let mut current = &mut self.head;

            while let Some(ref mut node) = current {
                if let Some(ref mut next_node) = node.next {
                    if node.data > next_node.data {
                        std::mem::swap(&mut node.data, &mut next_node.data);
                        swapped = true;
                    }
                }
                current = &mut node.next;
            }
        }
        println!("The linked list is sorted.");
    }

    fn count_nodes(&self) -> usize {
        let mut count = 0;
        let mut current = &self.head;
        while let Some(ref node) = current {
            count += 1;
            current = &node.next;
        }
        count
    }
}

fn main() {
    let mut list = LinkedList::new();
    let mut input = String::new();

    loop {
        println!("\nWhat do you want to do?\n");
        println!("Press \"1\" to create list");
        println!("Press \"2\" to insert a node in the list");
        println!("Press \"3\" to delete a node in the list");
        println!("Press \"4\" to reverse the list");
        println!("Press \"5\" to print the list");
        println!("Press \"6\" to free the list");
        println!("Press \"7\" to sort the list");
        println!("Press \"0\" to end\n");

        println!("Enter the value of operation to execute: ");
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let check: i32 = input.trim().parse().expect("Invalid input");

        match check {
            0 => {
                println!("\nThank you for using this.");
                list.free_list();
                break;
            }
            1 => list.create(),
            2 => list.insert_node(),
            3 => list.delete_node(),
            4 => list.reverse(),
            5 => list.print_list(),
            6 => list.free_list(),
            7 => list.sort_list(),
            _ => println!("\nOperation not valid. Please enter a valid option."),
        }
    }
}
