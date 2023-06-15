/**
 * @file Generic_linked_list1.cpp
 * @author Ishan Grover
 * @brief Generic Linked List program.

 * Generic Linked List --> A Linked Lists which can store data of any data type.
 * Eg-: [1,2,3,4,5] or ['a','b','c','d']
 */
// Created by Ishan Grover on 05-June-2023

#include <cassert>      // Header file for assert() function for making tests.
#include <iostream>
#include <memory>       // Header file for using smart pointers and access memory.

// Macro for making assert() statements "off" & "on" any time --> Just make this line comment
#define TESTS     /**< Macro to disable tests. */

/**
 * @class Node
 * @brief Making Node of Linked list.
 *
 * Node contains 2 things-:
 * a) data
 * b) next
 * @tparam T The type of data stored in the node.
 */
template <typename T> struct Node {
  T data;    /**< Data stored in a node. */
  std::shared_ptr<Node> next;   /**< next is a pointer pointing to the next Node of Linked list.\n
                                     We can access next Node using "this->next" */

  /**
   * @brief Default Constructor of Node class.
   */
  Node() = default;

  /**
   * @brief Parameterized Constructor taking "data" input to node
   *
   * @code {.cpp}
   * Node n = Node(3);
   * @endcode
   *
   * @param data The "data" value to be stored in the node.
   * @param next "next" is null pointer.
   */
  Node(T data) {
    this->data = data;
    this->next = nullptr;
  }

public:
  T get_data() { return this->data; } /**< To get @a data from Node*/
};

/**
 * @class LinkedList
 *
 * @brief Sequential data container using linked list.
 *
 * @tparam T The type of data stored.
 */
template <typename T> class LinkedList {
private:
  std::shared_ptr<Node<T>> head;  /**< head is the first Node of Linked list. */

public:
  /**
   * @brief Default Constructor.
   */
  LinkedList() = default;

  /**
   * @brief Constructor for storing data inthis->head Node.
   *
   * @param data "data" is stored in this->head Node.
   */
  LinkedList(T data) { this->head = std::make_shared<Node<T>>(data); }


// Operations or Function needed in linked list
  /**
   * @brief Adds a Node at **LAST** of linked list.\n
   *
   * **Logic-:**
   *    1. Make copy of head in current.
   *    2. Iterate until we reach last element which can be identified by @code
   * {.cpp} current->next = nullptr @endcode
   *    3. Link the last node by new node & allots the element to it. \n
   *
   * @param element is data of any data type which we wanted to add in the LAST
   * node of linked list.
   */
  void push_back(T element) noexcept;
  
  /**
   * @brief Adds a Node at **STARTING** of linked list.

  * **Logic-:**
  *    1. Make newNode and assign data
  *    2. Point newNode to head
  *    3. Declare newNode as head \n
  * 
  * @param element is data of any data type which we wanted to add in the FIRST node of linked list.
  */
  void push_front(T element) noexcept;

  /**
  * @brief Adds a Node at **desired position** of linked list
  * 
  * **Logic-:**
  *    1. Make copy of head & make newNode and allocate data in it
  *    2. Iterate until we reach "desired position"
  *    3. link the newNode to prevNode->next and link nextNode to newNode->next.
  * 
  * @param position Location where we need to add the Node.
  * @param element is data of any data type which we wanted to add in any POSITION in linked list.
  */
  void insert(int position, T element);

  /**
   * @brief Delete the last node.
   *
   * **Logic-:**
   *    1. Make head node copy in currentNode and make a prevNode.
   *    2. Iterate LinkedList till reach the **last node** & also update the
   *       prevNode,currentNode in each iteration.
   *    3. Unlink the prevNode & currentNode by @code {.cpp} prev->next = nullptr @endcode
   *    4. Delete currentNode. 
   * 
   * @return data of deleted node
   */
  T pop_back();

  /**
   * @brief Delete the **First** node.
   *
   * **Logic-:**
   *    1. Make head node copy in currentNode.
   *    2. Delete the head node and declare 2nd node as head.
   * 
   * @return data of deleted node
   */
  T pop_front();

  /**
   * @brief Delete the node by searching @a data.
   *
   * **Logic-:**
   *    1. Make copy of head in prevNode and current as 2nd node.
   *    2. Iterate the linked list until reach element & update prevNode , currentNode.
   *    3. Delete the currentNode & link the prevNode and nextNode by @code {.cpp} prev->next = current->next @endcode
   * 
   * @param element is searched in LinkedList and the node contains this element
   * gets deleted.
   * @return true Data from linked list is removed.
   * @return false Data cannot be removed because of "Empty linked list".
   */
  bool remove(T element) noexcept;

  /**
   * @brief returns @a data of **Desired Node**.
   *
   * **Logic-:**
   *    1. Make head copy in current.
   *    2. Iterate LinkedList till reach the desired @a position of Node.
   *    3. Get the @a data from Node.
   *
   * @param position Location of desired Node to get the data.
   * @return data of any Node.
   */
  T get(int position);

  /**
   * @brief Returns the @a size of linked list
   *
   * **Logic-:**
   *    1. Make current as copy of head.
   *    2. Iterate and each time increase value of count as well as update the
   *       node by nextNode by @code {.cpp} current = current->next @endcode
   *    3. When we reach last node then count is the size.
   *
   * @return @a size It return the size of Linked list or we can say number of
   * node linked together
   */
  int size() noexcept;

  /**
   * @brief Checks if the Linked list is empty or not.
   *
   * **Logic-:**
   *    1. Just check the @a head is NULL or not.
   *
   * @return true When it contains one or more nodes in it.
   * @return false When the Linked list is empty.
   */
  bool is_empty() noexcept;

  /**
   * @brief Delete all the nodes in linked list.
   *
   * **Logic-:**
   *    1. Traverse the Linked list and delete each node.
   */
  void clear();

  /**
   * @brief Display all elements of linked list.
   * 
   * **Logic-:**
   *    1. Traverse the Linked list and print @a element.
   */
  void display_all() noexcept;
};

template <typename T> void LinkedList<T>::push_back(T element) noexcept {

  if (!head) { // if head is empty then data will be alloted in head Node
    this->head = std::make_shared<Node<T>>(element);

  } else { // if head is not empty then make a new node current and data gets alloted
    auto current = this->head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = std::make_shared<Node<T>>(element);
  }
}

template <typename T> void LinkedList<T>::push_front(T element) noexcept {
  if (this->head == nullptr) {
    this->head = std::make_shared<Node<T>>(element);
  } else {
    auto new_node =
        std::make_shared<Node<T>>(element); // Assign the value to new node
    new_node->next =
        this->head; // new node gets address ofthis->head in its next
    this->head = new_node;
  }
}

template <typename T> void LinkedList<T>::insert(int position, T element) {

  if (position > this->size() + 1 || position <= 0) {
    throw std::invalid_argument("Invalid Position in insert()");
  
  } else if (position == 1) {
    auto new_node = std::make_shared<Node<T>>(element);
    new_node->next = this->head;
    this->head = new_node;
  
  } else if (position == this->size() + 1) {  // If linked list size = 3 and position = 4 then add node at back.
    this->push_back(element);
  
  } else {
    auto current = this->head;
    auto new_node = std::make_shared<Node<T>>(element);
    int count = 1;

    for (int i = 1; i <= position; i++) {
      if (count == position - 1) {
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

template <typename T> int LinkedList<T>::size() noexcept {
  auto current = this->head;
  int size = 0;

  if (head != nullptr) {
    while (current != nullptr) {
      size++;
      current = current->next;
    }
  }
  return size;
}

template <typename T> T LinkedList<T>::get(int position) {
  std::shared_ptr<Node<T>> current = this->head;
  int count = 0;
  if ((position > this->size()) && (position <= 0))
    throw std::invalid_argument("Invalid Position in get()");

  while (current != nullptr) {
    count++;
    if (count == position) {
      return current->get_data();
    }
    current = current->next;
  }
  throw std::invalid_argument("Invalid Position in get()");
}

template <typename T> T LinkedList<T>::pop_back() {

  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to pop from back.");

  else if (this->size() == 1) {
    auto rv = this->head;
    this->head = nullptr;  // We can't use "delete" keyword in smart pointers so declared this node nullptr.
    return rv->data;

  } else {
    std::shared_ptr<Node<T>> current = this->head;
    std::shared_ptr<Node<T>> prev = nullptr;

    while (current->next != nullptr) {
      prev = current;
      current = current->next;
    }
    auto rv = current->data;
    prev->next = nullptr;
    return rv;
  }
}

template <typename T> T LinkedList<T>::pop_front() {
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to pop from front.");

  else if (head->next == nullptr) {
    auto rv = this->head->data;
    this->head = nullptr;         //Head deleted
    return rv;

  } else {
    std::shared_ptr<Node<T>> current = this->head->next;
    auto rv = this->head->data;
    this->head = nullptr;         //Head deleted
    this->head = current;
    return rv;
  }
}

template <typename T> bool LinkedList<T>::remove(T element) noexcept {
  bool is_removed;

  if (head == nullptr)
    is_removed = false;

  else if (head->data == element) {
    std::shared_ptr<Node<T>> current = this->head->next;
    this->head = nullptr;         //Head deleted
    this->head = current;
    is_removed = true;

  } else {
    std::shared_ptr<Node<T>> prev = this->head;
    std::shared_ptr<Node<T>> current = this->head->next;

    while (current != nullptr) {
      if (current->data == element) {
        prev->next = current->next;
        current = nullptr;         // Current removed
        break;
      }
      prev = current;
      current = current->next;
    }
    is_removed = true;
  }
  return is_removed;
}

template <typename T> void LinkedList<T>::clear() {
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to clear.");
  else {
    std::shared_ptr<Node<T>> current = this->head;
    std::shared_ptr<Node<T>> prev;
    while (current->next != nullptr) {
      prev = current;
      current = current->next;
      prev = nullptr;
    }
    this->head = nullptr;
  }
}

template <typename T> bool LinkedList<T>::is_empty() noexcept {
  bool is_empty = false;
  if (head == nullptr)
    is_empty = true;
  return is_empty;
}

template <typename T> void LinkedList<T>::display_all() noexcept {
  std::shared_ptr<Node<T>> current = this->head;

  if (head == nullptr) {
    std::cout << "Empty Linked List" << std::endl;
  }

  else {
    int count = 0;
    while (current != nullptr) {
      count++;
      std::cout << "Element at Node " << count << " is: " << current->data
                << std::endl;
      current = current->next;
    }
  }
}

/**
 * @brief main() function. \n
 * In main() function we used tests using **assert()** to check all LinkedList
 * functions are properly working or not. If not working properly then error
 * displayed.
 *
 * @note assert( @a condition ) --> By using assert statements , we can verify
 * the certain conditions hold true or false.
 *              - If the condition is true, the program continues execution.
 *              - If the condition is false, the assert statement
 *                fails, and the program terminates with an error message.
 */
int main() {
  std::cout << std::endl;

  LinkedList<int> list; // Linked List declaration

#ifdef TESTS         //this is under the macro defined 
/*
  // Exceptional handling
    try{
      list.insert(3,9);         // std::invalid_argument("Invalid Position")
      list.get(10);             // std::invalid_argument("Invalid Position")
      list.pop_back();          // std::underflow_error("List is empty")
      list.pop_front();         // std::underflow_error("List is empty")
      list.remove(4);           // std::underflow_error("List is empty")
      list.clear();             // std::underflow_error("List is empty")
    }
    catch(std::invalid_argument &error){
      std::cerr << error.what() << std::endl;
    }
*/

// Tests using assert() function
  //  is_empty()
  assert(list.is_empty() == true);
  std::cout << "Empty Linked List" << std::endl << std::endl;

  // push_back(element)
  list.push_back(2); // 1
  list.push_back(4); // 2
  list.push_back(6); // 3

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
  list.insert(1, 9);
  list.insert(3, 10);

  assert(list.get(1) == 9);
  assert(list.get(2) == 3);
  assert(list.get(3) == 10);
  assert(list.get(6) == 4);
  std::cout << "Successfully executed: insert()" << std::endl << std::endl;

  // pop_back() & pop_front()
  list.pop_front(); // 2 elements removed

  assert(list.size() == 5);
  assert(list.get(4) == 2);
  std::cout << "Successfully executed: pop_back() & pop_front()" << std::endl
            << std::endl;

  // remove(element)
  list.remove(10);

  assert(list.get(2) == 1);
  std::cout << "Successfully executed: remove()" << std::endl << std::endl;

  list.display_all();

  // clear()
  list.clear();

  assert(list.is_empty() == true);
  std::cout << std::endl
            << "Successfully executed: clear()" << std::endl
            << std::endl;
  std::cout << "All tests successfully passed" << std::endl;
#endif
}

/*things to add more
     operator overloading in display_all funcn
     add exception handling where needed
*/

/* Doubts
    Why "new Node<T>" at line 69
    whythis->head = new_node at line 71
    pop_back (T type or void)
    line 175 should do it or not (head->next = nullptr;) after
   deletingthis->head 327 exception handling not woking in get()
*/
