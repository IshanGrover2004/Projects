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
  Node<T> *head;

public:
  LinkedList() {head = nullptr;}
  LinkedList(T data) {
    head->data = data;
    head->next = nullptr;
  }

  // Operations or Function needed in linked list
  void push_back(T element);                       // Done
  void push_front(T element);                      // On it
  void insert(int position, T element);            // On it
  T pop_back();                                    //
  T pop_front();                                   //
  void remove(T element);                          // 
  T get(int position);                             // Done
  int size();                                      // Done
  bool is_empty();                                 // Done
  void clear();                                    //
  void display_all();                              // Done
};

// push_back(element) --> push the element in the last node of linked list
template <typename T> void LinkedList<T>::push_back(T element) {
  if (head == nullptr) {        // if head is empty then data alloted in head node
    head = new Node<T>(element);

  } else {              // if head is not empty then make a new node current and data gets alloted
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
    // Continue kr...
  }
}

// size() --> Returns the size of linked list created
template<typename T> int LinkedList<T>::size(){
  Node<T> *current = new Node<T>;
  current = head;
  int size = 0;

  if (head != nullptr){
    while (current != nullptr){
      size++;
      current = current->next;
    }
  }
  return size;
}

// insert(position,element) --> Add element at desired position
template<typename T> void LinkedList<T>::insert(int position,T element){
  Node<T> *current = new Node<T>(nullptr);
  if (position > this->size()){     
    std::cout << "Invalid place" << std::endl;
  }
  else{
    if (position == 1){
      head->data = element;
      head->next = nullptr;
    }
    else{

    }
  }
}

// get(position) --> returns the element of linked list at any desired position
template<typename T> T LinkedList<T>::get(int position){
  Node<T> *current = head;
  int count = 0;
  if ((position > this->size()) && (position <= 0))
    return 0;      // Use Exception handling concept later
  
  while(current != nullptr){
    count++;
    if (count == position){
      return current->data;
    }
    current = current->next;
  }
  return 0;
}

// is_empty() --> Is the list empty or not
template<typename T> bool LinkedList<T>::is_empty(){
  bool is_empty = false;
  if (head == nullptr)
    is_empty = true;
  
  return is_empty;
}

// display_all() --> Display all elements of linked list
template <typename T>
void LinkedList<T>::display_all() {
  Node<T> *current = head;
  int count = 0;

  if (head == nullptr) {
    std::cout << "Empty Linked List" << std::endl;
  }

  else {
    while (current != nullptr) {
      count++;
      std::cout << "Element at Node " << count << " is: " << current->data
                << std::endl;
      current = current->next;
    }
  }
}

int main() {
  std::cout << std::endl;

  LinkedList<int> list;

  list.push_back(5);
  list.push_back(7);
  list.push_back(8);

  std::cout << "Element at postion 2 is : " << list.get(2) << std::endl;

  int size = list.size();
  std::cout << "Size: " << size << std::endl;

  std::cout << "List is empty: " << list.is_empty() << std::endl;

  list.display_all();
}



/*things to add more
     operator overloading in display_all funcn
     complete line 69 , 100 , 
*/
