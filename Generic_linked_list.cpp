// Created by Ishan Grover on 05-June-2023
// Generic Linked List --> A Linked Lists which can store data of any data type
// Eg-: [1,2,3,4,5] or ['a','b','c','d']

#include <iostream>

// For making a Node of a linked list
template <typename T> struct Node {
  T data;
  Node *next;

  Node() = default;

  Node(T data) { // Parameterised Constructor taking data input to node
    this->data = data;
    this->next = nullptr;
  }
};

// Creating Linked List structure
template <typename T> class LinkedList {
private:
  Node<T> *head = new Node<T>;

public:
  LinkedList() { head->next = nullptr; }
  LinkedList(T data) {
    head->data = data;
    head->next = nullptr;
  }

  // Operations or Function needed in linked list
  void push_back(T element);
  void push_front(T element);
  void insert(int position, T element);
  T pop_back(); // pop element return and shows up
  T pop_front();
  void remove(T element);
  T get(int position);
  int size();
  bool is_empty();
  void clear();
  void display_all();
};

// push_back(element) --> push the element in the last node of linked list
template <typename T> void LinkedList<T>::push_back(T element) {
  if (head == nullptr) {          // if head is empty then data alloted in head node
    head = new Node<T>(element);
  } else {                        // if head is not empty then make a new node current and data gets alloted
    Node<T> *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node<T>(element);

  }
}

// push_front(element) --> push the element in the first node of linked list
template <typename T> void LinkedList<T>::push_front(T element) {
  Node<T> *current = new Node<T>;

  if (head == nullptr) {
    head->data = element;
    head->next = nullptr;
  } else {
    current = head;
    head->data = element;
    head->next = nullptr;
  }
}

// display_all() --> Display all elements of linked list
template <typename T> void LinkedList<T>::display_all() {
  Node<T> *current = head;
  int count = 1;
  while (current != nullptr) {
    std::cout << "Elements at Node " << count << " is: " << current->data << std::endl;
    current = current->next;
    count++;
  }
}

int main() {
  LinkedList<int> list;
  
  list.push_back(5);
  list.push_back(7);
  list.push_back(8);

  list.display_all();
}
