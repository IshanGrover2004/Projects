// Created by Ishan Grover on 05-June-2023
// Generic Linked List --> A Linked Lists which can store data of any data type. Eg-: [1,2,3,4,5] or ['a','b','c','d']

#include <iostream>
#include <cassert>           // Header file for assert() function for making tests

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
  void push_front(T element);                      // Done
  void insert(int position, T element);            // Done
  void pop_back();                                 // Done
  void pop_front();                                // Done
  void remove(T element);                          // Done
  T get(int position);                             // Done
  int size();                                      // Done
  bool is_empty();                                 // Done
  void clear();                                    // Done
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

  if (head == nullptr) {
    head->data = element;
    head->next = nullptr;
  } else {
    Node<T> *new_node = new Node<T>(element);    // Assign the value to new node
    new_node->next = head;                       // new node gets address of head in its next
    head = new_node;              //Doubt????..

  }
}

// insert(position,element) --> Add element at desired position
template<typename T> void LinkedList<T>::insert(int position,T element){

  if (position > this->size()+1 || position <= 0){     
    std::cout << "Invalid position" << std::endl;
  }
  else if (position == 1) {
    Node<T> *new_node = new Node<T>(element);
    new_node->next = head;
    head = new_node;
  }
  else if (position == this->size()+1){    // if linked list size = 3 and position = 4 (to add at back)
    this->push_back(element);
  }
  else{
    Node<T> *current = head;
    Node<T> *new_node = new Node<T>(element);
    int count = 1;

    for (int i=1;i <= position;i++){
      if (count == position-1){
        auto temp = current->next;
        current->next = new_node;
        new_node->next = temp;
        break;
      }
      current = current->next;
      count++;
    }
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

// pop_back() --> delete the last node
template<typename T> void LinkedList<T>::pop_back(){
  
  if (head == nullptr) 
    std::cout << "Empty Linked List" << std::endl;

  else if (this->size() == 1){
    std::cout << "Data removed: " << head->data << std::endl;
    delete head;
    head = nullptr;
  }
  else{
    Node<T> *current = head;
    Node<T> *prev = nullptr;

    while(current->next != nullptr){
      prev = current;
      current = current->next;
    }

    std::cout << "Data removed: " << current->data << std::endl;
    delete current;
    prev->next = nullptr;
  }
}

// pop_front() --> delete the first node
template<typename T> void LinkedList<T>::pop_front(){
  if (head == nullptr)
    std::cout << "Empty Linked List" << std::endl;
  
  else if (head->next == nullptr){
    std::cout << "Head data removed: " << head->data << std::endl;
    delete head;
    head = nullptr;
  }
  else{
    Node<T> *current = head->next;
    std::cout << "Data removed: " << head->data << std::endl;
    delete head;
    head = current;
  }
}

// remove(element) --> delete the node have data = element
template<typename T>
void LinkedList<T>::remove(T element) {
  if (head == nullptr) {
    std::cout << "Empty Linked List" << std::endl;
  }
  else if (head->data == element) {
    std::cout << "Head data removed: " << head->data << std::endl;
    this->pop_front();
  }
  else {
    Node<T> *prev = head;
    Node<T> *current = head->next;

    while (current != nullptr) {
      if (current->data == element) {
        std::cout << "Data removed: " << current->data << std::endl;
        prev->next = current->next;
        delete current;
        return;
      }
      prev = current;
      current = current->next;
    }
    std::cout << "Element not found in the Linked List" << std::endl;
  }
}


// clear() --> delete all the nodes and clear the linked list
template<typename T> void LinkedList<T>::clear(){
  Node<T> *current = head;
  Node<T> *prev = current;
  while (current->next != nullptr){
    prev = current;
    current = current->next;
    delete prev;
  }
  head = nullptr;
  std::cout << "All Node deleted successfully..." << std::endl;
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

  LinkedList<int> list;         // Linked List declaration
  
//Tests using assert() function
// is_empty()
  assert(list.is_empty() == true);
  std::cout << "Empty Linked List" << std::endl << std::endl;
  
// push_back(element)
  list.push_back(2);     // 1
  list.push_back(4);     // 2
  list.push_back(6);     // 3
  
  assert(list.get(1) == 2);
  assert(list.get(2) == 4);
  assert(list.get(3) == 6);
  std::cout << "Successfully executed: push_back()" << std::endl << std::endl;
  
// push_front(element)
  list.push_front(1);
  list.push_front(3);
  
  assert(list.get(2) == 1);
  assert(list.get(1) == 3);
  std::cout << "Successfully executed: push_front()" << std::endl << std::endl;
 
// insert(position,element)
  list.insert(1,9);
  list.insert(3,10);

  assert(list.get(1) == 9);
  assert(list.get(2) == 3);
  assert(list.get(3) == 10);
  assert(list.get(6) == 4);
  std::cout << "Successfully executed: insert()" << std::endl << std::endl;
  
// pop_back() & pop_front()
  list.pop_back();
  list.pop_front();   // 2 elements removed
  
  assert(list.size() == 5);
  assert(list.get(4) == 2);
  std::cout << "Successfully executed: pop_back() & pop_front()" << std::endl << std::endl;

// remove(element)
  list.remove(10);
  
  assert(list.get(2) == 1);
  std::cout << "Successfully executed: remove()" << std::endl << std::endl;

  list.display_all();
  
// clear()
  list.clear();
  
  assert(list.is_empty() == true);
  std::cout << std::endl << "Successfully executed: clear()" << std::endl << std::endl;
std::cout << "All tests successfully passed" << std::endl;
  
}


/*things to add more
     operator overloading in display_all funcn
     remove(T element) , clear()
*/

/* Doubts
    Why "new Node<T>" at line 69
    why head = new_node at line 71
    pop_back (T type or void)
    line 175 should do it or not (head->next = nullptr;) after deleting head
*/
