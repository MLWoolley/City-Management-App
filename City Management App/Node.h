#pragma once
#include <cstddef>
#include <iostream>

/** Tree Node class. Node is templated to work with any primitive type or any
* class that conforms to standard operations on primitive types.
* @author Madeleine Woolley
*/

template <typename T>
class Node {
public:
    /** Default constructor */
    Node();
    /** Overloaded constructor, allows you to set a type T item in the Node along with up to two child nodes.
    * You can enter 0 child nodes, a left child node or both child nodes.
    * @param item Item in node
    * @param left Pointer to left child node
    * @param right Pointer to right child node
    */
    Node(const T& item, Node<T>* left = nullptr, Node<T>* right = nullptr);
    /** Copy constructor.
    * @param orig Node to be copied
    */
    Node(const Node& orig);
    /** Destructor. */
    ~Node();
    /** Item accessor method
    * @return Item in node
    */
    T getItem() const;
    /** Item mutator method
    * @param New item in node
    */
    void setItem(const T& item);
    
    /** Left child accessor method
    * @return Pointer to left child node
    */
    Node<T>* getLeftChild() const;
    /** Right child accessor method
    * @return Pointer to right child node
    */
    Node<T>* getRightChild() const;
    /** Left child mutator method
    * @param New pointer to left child node
    */
    void setLeftChild(Node<T>* left);
    /** Right child mutator method
    * @param New pointer to right child node
    */
    void setRightChild(Node<T>* right);
    /** Checks if the node is a leaf node, i.e. has no child nodes
    * @return True if node has no children, false otherwise
    */
    bool isLeaf() const;

private:
    /** Item in the Node */
    T item;
    /** Pointer to left child Node */
    Node<T>* leftChild;
    /** Pointer to right child Node */
    Node<T>* rightChild;
};

template <typename T>
Node<T>::Node() {
    leftChild = nullptr;
    rightChild = nullptr;
}

template <typename T>
Node<T>::Node(const T& item, Node<T>* left, Node<T>* right) : item(item), leftChild(left), rightChild(right) {}

template <typename T>
Node<T>::Node(const Node& orig) {
    item = orig.item;
    leftChild = orig.leftChild;
    rightChild = orig.rightChild;
}

template <typename T>
Node<T>::~Node() {}

template <typename T>
T Node<T>::getItem() const {
    return item;
}

template <typename T>
void Node<T>::setItem(const T& item) {
    this->item = item;
}

template <typename T>
Node<T>* Node<T>::getLeftChild() const {
    return leftChild;
}

template <typename T>
Node<T>* Node<T>::getRightChild() const {
    return rightChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>* left) {
    leftChild = left;
}

template <typename T>
void Node<T>::setRightChild(Node<T>* right) {
    rightChild = right;
}

template <typename T>
bool Node<T>::isLeaf() const {
    return (leftChild == nullptr && rightChild == nullptr);
}