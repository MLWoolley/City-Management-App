#pragma once
#include "BSTInterface.h"
#include "Node.h"
#include <iostream>

/** Linked Binary Search Tree class, uses Node class, implements BSTInterface.
* BinarySearchTree is templated to work with any primitive type or any
* class that conforms to standard operations on primitive types.
* @author Madeleine Woolley
* @see GeeksForGeeks.com for print2D() and print2DUtil()
*/

using namespace std;

template <typename T>
class BinarySearchTree : public BSTInterface<T> {
public:
    /** Default constructor */
    BinarySearchTree();
    /** Destructor */
    ~BinarySearchTree();

    /** Checks whether the BST is empty.
    * @return True if BST contains no items, false otherwise
    */
    bool isEmpty() const;
    /** Inserts the specified item into the BST according to the value of its key.
    * @param item Item to be inserted
    * @return Always true
    */
    bool insert(const T& item);
    /** Removes the specified item from the BST.
    * @param item Item to be removed
    * @return True if removal is successful, false otherwise
    */
    bool remove(const T& item);
    /** Checks whether the specified item is in the BST.
    * @param item Item to be searched for
    * @return True if item is found in tree, false otherwise
    */
    bool contains(const T& item) const;
    /** Removes all items from the BST. */
    void clear();

    /** Performs an in-order traversal of the BST.
    * This means for each node, the left child is traversed,
    * the current node is visited and then the right child is traversed.
    * @param visitor Visitor pattern containing visit method
    */
    void inOrderTraverse(Visitor& visitor) const;
    /** Performs a pre-order traversal of the BST.
    * This means for each node, the current node is visited,
    * the left child is traversed and then the right child is traversed.
    * @param visitor Visitor pattern containing visit method
    */
    void preOrderTraverse(Visitor& visitor) const;
    /** Performs a post-order traversal of the BST.
    * This means for each node, the left child is traversed,
    * the right child is traversed and then the current node is visited.
    * @param visitor Visitor pattern containing visit method
    */
    void postOrderTraverse(Visitor& visitor) const;
    /** Prints a 2D representation of the BST using reverse in-order traversal.
    * @see https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    */
    void print2D() const;

private:
    /** Pointer to root Node of BST */
    Node<T>* root;
    /** Number of spaces between each tree level. Used in print2DUtil(). */
    static const int COUNT = 10; //should be > 0
    /** Places newNode in either currRoot's position or in the appropriate position
    * in the left or right subtree. 
    * Position determined by comparing currRoot and newNode's items using the < operator.
    * @param currRoot Root of current tree
    * @param newNode Node to be inserted
    * @return Pointer to updated tree
    */
    Node<T>* placeNode(Node<T>* currRoot, Node<T>* newNode);
    /** Searches the current tree for item by comparing currRoot's item and 
    * the specified item using the < operator.
    * @param currRoot Root of the current tree
    * @param item Item to search for
    * @return True if item found, false otherwise
    */
    bool findNode(Node<T>* currRoot, const T& item) const;
    /** Prints a 2D representation of the BST using reverse in-order traversal.
    * Uses COUNT value to determine spacing between each level.
    * @see https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    */
    void print2DUtil(Node<T>* currRoot, int space) const;
    /** Performs an in-order traversal of the tree.
    * @param currRoot Root of the current tree
    * @param visitor Visitor pattern containing visit method
    */
    void inorder(Node<T>* currRoot, Visitor& visitor) const;
    /** Performs a pre-order traversal of the tree.
    * @param currRoot Root of the current tree
    * @param visitor Visitor pattern containing visit method
    */
    void preorder(Node<T>* currRoot, Visitor& visitor) const;
    /** Performs a post-order traversal of the tree.
    * @param currRoot Root of the current tree
    * @param visitor Visitor pattern containing visit method
    */
    void postorder(Node<T>* currRoot, Visitor& visitor) const;
    /** Deletes all items from the tree using a postorder traversal.
    * @param currRoot Root of the current tree
    */
    void deleteTree(Node<T>* currRoot);
    /** Searches for item in the tree specified by subTreePtr and removes it.
    * @param subTreePtr Pointer to current tree
    * @param item Item to be removed
    * @param success Removal success status, will be changed to true if item is removed
    * @return Pointer to updated tree
    */
    Node<T>* removeItem(Node<T>* subTreePtr, const T& item, bool& success);
    /** Removes the node specified by nodePtr from the tree, while maintaining
    * the rest of the tree in a valid order.
    * @param nodePtr Node to be removed
    * @return Updated subtree in removed node's location. Returns nullptr if removed node is a leaf.
    */
    Node<T>* removeNode(Node<T>* nodePtr);
    /** Removes the smallest item from the tree specified by subTreePtr.
    * @param subTreePtr Pointer to current tree
    * @param smallestItem Item to be removed, will be assigned a value when smallest item is found.
    * @returns The item removed
    */
    Node<T>* removeSmallestItem(Node<T>* subTreePtr, T& smallestItem);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    deleteTree(root);
    //cout << "Tree deleted" << endl; //testing
}

template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return root == nullptr;
}

template <class T>
bool BinarySearchTree<T>::insert(const T& item) {
    Node<T>* newNode = new Node<T>(item);
    root = placeNode(root, newNode);
    return true;
}

template<typename T>
bool BinarySearchTree<T>::remove(const T& item) {
    bool success = false;
    root = removeItem(root, item, success);
    return success;
}

template<typename T>
Node<T>* BinarySearchTree<T>::removeItem(Node<T>* subTreePtr, const T& item, bool& success) {
    if (subTreePtr == nullptr) { //Base case
        success = false;
        return nullptr;
    }
    if (subTreePtr->getItem() == item) { //Item is in the root of this subtree
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr; //The root of this tree is replaced with an item which maintains BST order
    }
    else {
        if (subTreePtr->getItem() > item) // Search the left subtree
            subTreePtr->setLeftChild(removeItem(subTreePtr->getLeftChild(), item, success));
        else // Search the right subtree
            subTreePtr->setRightChild(removeItem(subTreePtr->getRightChild(), item, success));
        return subTreePtr; //The root of this subtree remains unchanged
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::removeNode(Node<T>* nodePtr) {
    if (nodePtr->isLeaf()) { // Node is a leaf - it is deleted
        delete nodePtr;
        return (nodePtr = nullptr); // Assign and return
    }
    else if (nodePtr->getLeftChild() == nullptr) { // Has right child only - right subtree becomes main tree
        Node<T>* nodeToConnectPtr = nodePtr->getRightChild();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightChild() == nullptr) { // Has left child only - left subtree becomes main tree
        Node<T>* nodeToConnectPtr = nodePtr->getLeftChild();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else { // Has two children - replaces root item with smallest item in the right subtree
        T replaceItem;
        nodePtr->setRightChild(removeSmallestItem(nodePtr->getRightChild(), replaceItem));
        nodePtr->setItem(replaceItem);
        return nodePtr;
    }
}

template<typename T>
Node<T>* BinarySearchTree<T>::removeSmallestItem(Node<T>* subTreePtr, T& smallestItem) {
    if (subTreePtr->getLeftChild() == nullptr) { //if this root is the smallest item node
        smallestItem = subTreePtr->getItem();
        //set this subtree to its right child
        Node<T>* rightChild = subTreePtr->getRightChild();
        delete subTreePtr;
        return rightChild; //return right child as replacement for subtree root
    }
    else {
        subTreePtr->setLeftChild(removeSmallestItem(subTreePtr->getLeftChild(), smallestItem));
        return subTreePtr;
    }
}

template <class T>
Node<T>* BinarySearchTree<T>::placeNode(Node<T>* currRoot, Node<T>* newNode) {
    if (currRoot == nullptr) {
        return newNode;
    }
    else {
        if (newNode->getItem() < currRoot->getItem()) {
            currRoot->setLeftChild(placeNode(currRoot->getLeftChild(), newNode));
        }
        else {
            currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
        }
        return currRoot;
    }
}

template <typename T>
void BinarySearchTree<T>::inOrderTraverse(Visitor& visitor) const {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorder(root, visitor);
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* currRoot, Visitor& visitor) const {
    if (currRoot != nullptr) {
        inorder(currRoot->getLeftChild(), visitor); //left
        visitor.visit(currRoot->getItem()); //visit
        inorder(currRoot->getRightChild(), visitor); //right
    }
}

template<typename T>
void BinarySearchTree<T>::preOrderTraverse(Visitor& visitor) const {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    preorder(root, visitor);
}

template<typename T>
void BinarySearchTree<T>::preorder(Node<T>* currRoot, Visitor& visitor) const {
    if (currRoot != nullptr) {
        visitor.visit(currRoot->getItem()); //visit
        preorder(currRoot->getLeftChild() , visitor); //left
        preorder(currRoot->getRightChild(), visitor); //right
    }
}

template<typename T>
void BinarySearchTree<T>::postOrderTraverse(Visitor& visitor) const {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    postorder(root, visitor);
}

template<typename T>
void BinarySearchTree<T>::postorder(Node<T>* currRoot, Visitor& visitor) const {
    if (currRoot != nullptr) {
        postorder(currRoot->getLeftChild(), visitor); //left
        postorder(currRoot->getRightChild(), visitor); //right
        visitor.visit(currRoot->getItem()); //visit
    }
}

template <typename T>
bool BinarySearchTree<T>::contains(const T& item) const {
    return findNode(root, item);
}

template <typename T>
bool BinarySearchTree<T>::findNode(Node<T>* currRoot, const T& item) const {
    if (currRoot == nullptr)
       return false;
    else if (item == currRoot->getItem())
        return true;
    else if (item < currRoot->getItem())
        return findNode(currRoot->getLeftChild(), item);
    else
        return findNode(currRoot->getRightChild(), item);
}

template<typename T>
void BinarySearchTree<T>::clear() {
    deleteTree(root);
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* currRoot) {
    if (currRoot != nullptr) {
        deleteTree(currRoot->getLeftChild());
        deleteTree(currRoot->getRightChild());
        delete currRoot;
    }
}

template <typename T>
void BinarySearchTree<T>::print2DUtil(Node<T>* currRoot, int space) const {
    if (currRoot == NULL) // Base case
        return;
    
    space += COUNT; // Increase distance between levels

    // Process right child first
    print2DUtil(currRoot->getRightChild(), space);

    // Print current node after <space-COUNT> spaces (or 0 spaces if space<COUNT)
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << currRoot->getItem() << "\n";

    // Process left child
    print2DUtil(currRoot->getLeftChild(), space);
}

template <typename T>
void BinarySearchTree<T>::print2D() const {
    print2DUtil(root, 0); // Pass initial space count as 0
}