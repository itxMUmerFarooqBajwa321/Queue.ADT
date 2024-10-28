# Templated Queue Implementation in C++

This repository contains a C++ implementation of a templated Queue class, providing functionality for a dynamic queue structure with common operations such as `push`, `pop`, `front`, `back`, and utility methods for checking size, emptiness, and displaying contents.

## Features

- **Templated Queue**: Supports different data types by using C++ templates.
- **Dynamic Resizing**: Queue resizes automatically when full, allowing for efficient memory management.
- **Basic Operations**: `push`, `pop`, `front`, `back`, and more to simulate queue operations.
- **Utility Functions**: Check size (`size()`), emptiness (`empty()`), and display all queue elements (`displayQueue()`).
- **Move Semantics**: Implements both copy and move constructors for efficient memory handling.

## Code Overview

- **Queue Class**: The main class provides queue functionalities such as adding, removing, and accessing elements.
- **Private Helper Functions**:
  - `reSize()`: Dynamically adjusts queue size.
  - `full()`: Checks if the queue is full.
- **`mySwap` Function**: A generic function to swap two variables, used in the `swap` method.

## Usage

The `Queue` class can be instantiated with any data type:
```cpp
Queue<int> myQueue;
myQueue.push(10);
myQueue.push(20);
myQueue.displayQueue();  // Output: 10 20
push(const T& ele): Adds an element to the rear of the queue.
pop(): Removes an element from the front of the queue.
front(): Returns the element at the front.
back(): Returns the element at the rear.
size(): Returns the size of the queue.
empty(): Checks if the queue is empty.
swap(Queue<T>& other): Swaps contents with another queue.

Here’s a README and Description for your GitHub repository to explain and document this queue implementation.

Description
An implementation of a templated Queue class in C++ supporting dynamic resizing, push/pop, and utility functions.

README.md
markdown
Copy code
# Templated Queue Implementation in C++

This repository contains a C++ implementation of a templated Queue class, providing functionality for a dynamic queue structure with common operations such as `push`, `pop`, `front`, `back`, and utility methods for checking size, emptiness, and displaying contents.

## Features

- **Templated Queue**: Supports different data types by using C++ templates.
- **Dynamic Resizing**: Queue resizes automatically when full, allowing for efficient memory management.
- **Basic Operations**: `push`, `pop`, `front`, `back`, and more to simulate queue operations.
- **Utility Functions**: Check size (`size()`), emptiness (`empty()`), and display all queue elements (`displayQueue()`).
- **Move Semantics**: Implements both copy and move constructors for efficient memory handling.

## Code Overview

- **Queue Class**: The main class provides queue functionalities such as adding, removing, and accessing elements.
- **Private Helper Functions**:
  - `reSize()`: Dynamically adjusts queue size.
  - `full()`: Checks if the queue is full.
- **`mySwap` Function**: A generic function to swap two variables, used in the `swap` method.

## Usage

The `Queue` class can be instantiated with any data type:
```cpp
Queue<int> myQueue;
myQueue.push(10);
myQueue.push(20);
myQueue.displayQueue();  // Output: 10 20
Example Code
cpp
Copy code
#include "Queue.h"

int main() {
    Queue<int> q(3, 1, 2, 3); // Create a queue with initial elements 1, 2, 3
    q.push(4);
    q.displayQueue(); // Output: 1 2 3 4

    q.pop();
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    return 0;
}
Methods
push(const T& ele): Adds an element to the rear of the queue.
pop(): Removes an element from the front of the queue.
front(): Returns the element at the front.
back(): Returns the element at the rear.
size(): Returns the size of the queue.
empty(): Checks if the queue is empty.
swap(Queue<T>& other): Swaps contents with another queue.
Requirements
C++11 or later for move semantics.
License
This project is licensed under the MIT License. See the LICENSE file for details.

