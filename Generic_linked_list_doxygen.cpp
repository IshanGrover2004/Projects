/**
 * @file Generic_linked_list1.cpp
 * @author Ishan Grover
 * @brief Generic Linked List program.

 * Generic Linked List --> A Linked Lists which can store data of any data type. Eg-: [1,2,3,4,5] or ['a','b','c','d']
 */

// Created by Ishan Grover on 05-June-2023

#include <iostream>
#include <cassert>           // Header file for assert() function for making tests
#include <memory>            // Header file for using smart pointers and access memory


// For making a Node template of a linked list
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
  T data;     /**< Data stored in a node. */
  std::shared_ptr<Node> next;  /**< next is a pointer pointing to the next Node of Linked list. We can access next Node using "this->next" */

  /**
   * @brief Default Constructor of Node class.
   * @code {.cpp}
   * Node() = default;
   * @endcode
   * 
   * @return nothing
   */
  Node() = default;

  /**
   * @brief Parameterized Constructor taking "data" input to node
   * 
   * @code {.cpp}
   * Node(T data) {
   *     this->data = data;
   *     this->next = nullptr;
   * }
   * @endcode
   * @param data The "data" value to be stored in the node.
   * @param next "next" is null pointer for now
   */
  Node(T data) {
    this->data = data;
    this->next = nullptr;
  }

};


/**
 * @class LinkedList
 * @brief Creating Linked List structure.
 * LinkedList contains different function for different operations in linked list
 * @tparam T The type of data stored in the linked list.
 */
template <typename T> class LinkedList {
private:
  std::shared_ptr<Node<T>> head;    /**< head is the first Node of Linked list. */

public:

  /**
   * @brief Default Constructor of LinkedList class.
   * @code {.cpp}
   * LinkedList() {head = nullptr;}
   * @endcode
   */
  LinkedList() {head = nullptr;}

  /**
   * @brief Constructor for storing data in head Node.
   * 
   * @code {.cpp}
   *   LinkedList(T data) {
   *      head->data = data;
   *      head->next = nullptr;
   *   }
   * @endcode
   * @param data "data" is stored in head Node.
   * @param next making "head->next" to null pointer.
   */
  LinkedList(T data) {
    head->data = data;
    head->next = nullptr;
  }

  // Operations or Function needed in linked list
  void push_back(T element);
  void push_front(T element);
  void insert(int position, T element);
  void pop_back();
  void pop_front();
  void remove(T element);
  T get(int position);
  int size();
  bool is_empty();
  void clear();
  void display_all();
};


/**
 * @brief Adds a Node at **LAST** of linked list.
 * @code {.cpp}
 * // push_back(element) --> push the element in the last node of linked list
 * template <typename T> void LinkedList<T>::push_back(T element) {
 *   if (head == nullptr) {        // if head is empty then data alloted in head node
 *     head = new Node<T>(element);
 * 
 *   } else {              // if head is not empty then make a new node current and data gets alloted
 *     Node<T> *current = head;
 * 
 *     while (current->next != nullptr) {
 *       current = current->next;
 *     }
 *     current->next = new Node<T>(element);
 *   }
 * }
 * @endcode
 * **Logic-:**
 *    1. Make current same as head
 *    2. Iterate until we reach last element which can be identified by ( current->next = nullptr )
 *    3. Points the node having data to current->next \n
 * @param element is data of any data type which we wanted to add in the LAST node of linked list.
 */
template <typename T> void LinkedList<T>::push_back(T element) {

  if (head == nullptr) {        // if head is empty then data alloted in head node
    head = std::make_shared<Node<T>>(element);

  } else {              // if head is not empty then make a new node current and data gets alloted
    std::shared_ptr<Node<T>> current = head;

    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = std::make_shared<Node<T>>(element);
  }
}

/**
 * @brief Adds a Node at **STARTING** of linked list.
 * @code {.cpp}
 * // push_front(element) --> push the element in the first node of linked list
 * template <typename T> void LinkedList<T>::push_front(T element) {
 *   if (head == nullptr) {
 *     head->data = element;
 *     head->next = nullptr;
 *   } else {
 *      Node<T> *new_node = new Node<T>(element);    // Assign the value to new node
 *      new_node->next = head;                       // new node gets address of head in its next
 *      head = new_node;
 *   }
 * }
 * @endcode
 * **Logic-:**
 *    1. Make newNode and assign data
 *    2. Point newNode to head
 *    3. Declare newNode as head \n
 * @param element is data of any data type which we wanted to add in the FIRST node of linked list. 
 */
template <typename T> void LinkedList<T>::push_front(T element) {

  if (head == nullptr) {
    head->data = element;
    head->next = nullptr;
  } else {
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(element);    // Assign the value to new node
    new_node->next = head;                       // new node gets address of head in its next
    head = new_node;              //Doubt????..
  }
}


/**
 * @brief Adds a Node at **desired position** of linked list
 * @code {.cpp}
 * template<typename T> void LinkedList<T>::insert(int position,T element){
 * 
 *   if (position > this->size()+1 || position <= 0){     
 *     std::cout << "Invalid position" << std::endl;
 *   }
 *   else if (position == 1) {
 *     Node<T> *new_node = new Node<T>(element);
 *     new_node->next = head;
 *     head = new_node;
 *   }
 *   else if (position == this->size()+1){    // if linked list size = 3 and position = 4 (to add at back)
 *     this->push_back(element);
 *   }
 *   else{
 *     Node<T> *current = head;
 *     Node<T> *new_node = new Node<T>(element);
 *     int count = 1;
 * 
 *     for (int i=1;i <= position;i++){
 *       if (count == position-1){
 *         auto temp = current->next;
 *         current->next = new_node;
 *         new_node->next = temp;
 *         break;
 *       }
 *       current = current->next;
 *       count++;
 *     }
 *   }
 * }
 * @endcode
 * **Logic-:**
 *    1. Make current same as head & make newNode and allocate data in it
 *    2. Iterate until we reach "desired position"
 *    3. link the newNode to prevNode->next and link nextNode to newNode->next.
 * @param position Location where we need to add the Node
 * @param element is data of any data type which we wanted to add in any POSITION linked list.
 */
template<typename T> void LinkedList<T>::insert(int position,T element){
  try{
    if (position > this->size()+1 || position <= 0){     
      throw std::invalid_argument("Invalid Position in insert()");
    }
    else if (position == 1) {
      std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(element);
      new_node->next = head;
      head = new_node;
    }
    else if (position == this->size()+1){    // if linked list size = 3 and position = 4 (to add at back)
      this->push_back(element);
    }
    else{
      std::shared_ptr<Node<T>> current = head;
      std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(element);
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
  catch(int invalid_position){
    std::cout << "Invalid position: "  << std::endl << std::endl;
  }
}


/**
 * @brief Returns the @a size of linked list
 * @code {.cpp}
 * template<typename T> int LinkedList<T>::size(){
 *   Node<T> *current = new Node<T>;
 *   current = head;
 *   int size = 0;
 * 
 *   if (head != nullptr){
 *     while (current != nullptr){
 *       size++;
 *       current = current->next;
 *     }
 *   }
 *   return size;
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Make current same as head.
 *    2. Iterate and each time increase value of count as well as update the node by nextNode.
 *    3. When we reach last node then count is the size.
 * 
 * @return @a size It return the size of Linked list or we can say number of node linked together
 */
template<typename T> int LinkedList<T>::size(){
  std::shared_ptr<Node<T>> current = head;
  int size = 0;

  if (head != nullptr){
    while (current != nullptr){
      size++;
      current = current->next;
    }
  }
  return size;
}


/**
 * @brief returns @a data of desired Node.
 * @code {.cpp}
 * template<typename T> T LinkedList<T>::get(int position){
 *   Node<T> *current = head;
 *   int count = 0;
 *   if ((position > this->size()) && (position <= 0))
 *     return 0;      // Use Exception handling concept later
 *   
 *   while(current != nullptr){
 *     count++;
 *     if (count == position){
 *       return current->data;
 *     }
 *     current = current->next;
 *   }
 *   return 0;
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Make current same as head.
 *    2. Iterate LinkedList till reach the desired @a position of Node.
 *    3. Get the @a data from Node
 * 
 * @param position Location of desired Node to get the data.
 * @return data of any Node
 */
template<typename T> T LinkedList<T>::get(int position){
  std::shared_ptr<Node<T>> current = head;
  int count = 0;
  if ((position > this->size()) && (position <= 0))
    throw std::invalid_argument("Invalid Position in get()");
  
  while(current != nullptr){
    count++;
    if (count == position){
      return current->data;
    }
    current = current->next;
  }
  throw std::invalid_argument("Invalid Position in get()");
}


/**
 * @brief Delete the last node.
 * @code {.cpp}
 * template<typename T> void LinkedList<T>::pop_back(){
 *   
 *   if (head == nullptr) 
 *     std::cout << "Empty Linked List" << std::endl;
 * 
 *   else if (this->size() == 1){
 *     std::cout << "Data removed: " << head->data << std::endl;
 *     delete head;
 *     head = nullptr;
 * 
 *   } else {
 *     Node<T> *current = head;
 *     Node<T> *prev = nullptr;
 * 
 *     while(current->next != nullptr){
 *       prev = current;
 *       current = current->next;
 *     }
 *     std::cout << "Data removed: " << current->data << std::endl;
 *     delete current;
 *     prev->next = nullptr;
 *   }
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Make currentNode same as head & make prevNode.
 *    2. Iterate LinkedList till reach the **last node** & also update the prevNode,currentNode in each iteration.
 *    3. delete the currentNode(last node) & declare prevNode->next nullptr
 */
template<typename T> void LinkedList<T>::pop_back(){
  
  if (head == nullptr) 
    throw std::underflow_error("List is empty. No element is there to pop from back.");

  else if (this->size() == 1){
    std::cout << "Data removed: " << head->data << std::endl;
    head = nullptr;
  }
  else{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> prev = nullptr;

    while(current->next != nullptr){
      prev = current;
      current = current->next;
    }

    std::cout << "Data removed: " << current->data << std::endl;
    current = nullptr;
    prev->next = nullptr;
  }
}



/**
 * @brief Delete the first node.
 * @code {.cpp}
 * template<typename T> void LinkedList<T>::pop_front(){
 *   if (head == nullptr)
 *     std::cout << "Empty Linked List" << std::endl;
 *   
 *   else if (head->next == nullptr){
 *     std::cout << "Head data removed: " << head->data << std::endl;
 *     delete head;
 *     head = nullptr;
 *   }
 *   else{
 *     Node<T> *current = head->next;
 *     std::cout << "Data removed: " << head->data << std::endl;
 *     delete head;
 *     head = current;
 *   }
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Make currentNode same as head & make prevNode.
 *    2. Iterate LinkedList till reach the **last node** & also update the prevNode,currentNode in each iteration.
 *    3. delete the currentNode(last node) & declare prevNode->next nullptr.
 */
template<typename T> void LinkedList<T>::pop_front(){
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to pop from front.");
  
  else if (head->next == nullptr){
    std::cout << "Head data removed: " << head->data << std::endl;
    head = nullptr;
  }
  else{
    std::shared_ptr<Node<T>> current = head->next;
    std::cout << "Data removed: " << head->data << std::endl;
    head = nullptr;
    head = current;
  }
}

/**
 * @brief Delete the node by searching @a data.
 * @code {.cpp}
 * template<typename T> void LinkedList<T>::remove(T element) {
 *   if (head == nullptr) {
 *     std::cout << "Empty Linked List" << std::endl;
 *   }
 *   else if (head->data == element) {
 *     std::cout << "Head data removed: " << head->data << std::endl;
 *     this->pop_front();
 *   }
 *   else {
 *     Node<T> *prev = head;
 *     Node<T> *current = head->next;
 * 
 *     while (current != nullptr) {
 *       if (current->data == element) {
 *         std::cout << "Data removed: " << current->data << std::endl;
 *         prev->next = current->next;
 *         delete current;
 *         return;
 *       }
 *       prev = current;
 *       current = current->next;
 *     }
 *     std::cout << "Element not found in the Linked List" << std::endl;
 *   }
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Make prevNode same as head & current the 2nd node
 *    2. Iterate LinkedList till reach the **desired @a data node** & also update the prevNode,currentNode in each iteration.
 *    3. delete the currentNode(containing @a data to be removed)
 *    4. link the prevNode with the nextNode by address in current->next
 * 
 * @param element is searched in LinkedList and the node contains this element gets deleted.
 */
template<typename T> void LinkedList<T>::remove(T element) {
  if (head == nullptr) {
    throw std::underflow_error("List is empty. No element is there to remove.");
  }
  else if (head->data == element) {
    std::cout << "Head data removed: " << head->data << std::endl;
    this->pop_front();
  }
  else {
    std::shared_ptr<Node<T>> prev = head;
    std::shared_ptr<Node<T>> current = head->next;

    while (current != nullptr) {
      if (current->data == element) {
        std::cout << "Data removed: " << current->data << std::endl;
        prev->next = current->next;
        current = nullptr;
        return;
      }
      prev = current;
      current = current->next;
    }
    std::cout << "Element not found in the Linked List" << std::endl;
  }
}



/**
 * @brief Delete all the nodes in linked list.
 * @code {.cpp}
 * template<typename T> void LinkedList<T>::clear(){
 *   Node<T> *current = head;
 *   Node<T> *prev = current;
 *   while (current->next != nullptr){
 *     prev = current;
 *     current = current->next;
 *     delete prev;
 *   }
 *   head = nullptr;
 *   std::cout << "All Node deleted successfully..." << std::endl;
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Traverse the Linked list and delete each node.
 */
template<typename T> void LinkedList<T>::clear(){
  if (head == nullptr)
    throw std::underflow_error("List is empty. No element is there to clear.");
  else{
    std::shared_ptr<Node<T>> current = head;
    std::shared_ptr<Node<T>> prev = current;
    while (current->next != nullptr){
      prev = current;
      current = current->next;
      prev = nullptr;
    }
    head = nullptr;
    std::cout << "All Node deleted successfully..." << std::endl;
  }
}

/**
 * @brief Checks if the Linked list is empty or not.
 * @code {.cpp}
 * template<typename T> bool LinkedList<T>::is_empty(){
 *   bool is_empty = false;
 *   if (head == nullptr)
 *     is_empty = true;
 *   
 *   return is_empty;
 * }
 * @endcode
 * 
 * **Logic-:**
 *    1. Just check the @a head is NULL or not.
 * 
 * @return true When it contains one or more nodes in it.
 * @return false When the Linked list is empty.
 */
template<typename T> bool LinkedList<T>::is_empty(){
  bool is_empty = false;
  if (head == nullptr)
    is_empty = true;
  
  return is_empty;
}

/**
 * @brief Display all elements of linked list.
 * @code {.cpp}
 * template <typename T> void LinkedList<T>::display_all() {
 *   Node<T> *current = head;
 *   int count = 0;
 * 
 *   if (head == nullptr)
 *     std::cout << "Empty Linked List" << std::endl;
 *   else {
 *     while (current != nullptr) {
 *       count++;
 *       std::cout << "Element at Node " << count << " is: " << current->data << std::endl;
 *       current = current->next;
 *     }
 *   }
 * }
 * @endcode
 * **Logic-:**
 *    1. Traverse the Linked list and print @a element.
 */
template <typename T> void LinkedList<T>::display_all() {
  std::shared_ptr<Node<T>> current = head;
  int count = 0;

  if (head == nullptr) {
    std::cout << "Empty Linked List" << std::endl;
  }

  else {
    while (current != nullptr) {
      count++;
      std::cout << "Element at Node " << count << " is: " << current->data << std::endl;
      current = current->next;
    }
  }
}

/**
 * @brief main() function. \n 
 * In main() function we use tests using **assert()** to check all LinkedList functions are properly working or not.
 * If not working properly then error displayed.
 * 
 * @note assert( @a condition ) --> By using assert statements , we can verify the certain conditions hold true or false.
 *                       - If the condition is true, the program continues execution.
 *                       - If the condition is false, the assert statement fails, and the program terminates with an error message.
 */
int main() {
  std::cout << std::endl;

  LinkedList<int> list;         // Linked List declaration

// Exceptional handling
/*
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
     add exception handling where needed
*/

/* Doubts
    Why "new Node<T>" at line 69
    why head = new_node at line 71
    pop_back (T type or void)
    line 175 should do it or not (head->next = nullptr;) after deleting head
    327 exception handling not woking in get()
*/
