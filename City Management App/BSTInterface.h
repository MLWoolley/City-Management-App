#pragma once
#include "Visitor.h"

/** BST (Binary Search Tree) Interface specifies the Binary Tree ADT.
* BSTInterface is templated to work with any primitive type or any
* class that conforms to standard operations on primitive types.
* @author Madeleine Woolley
*/

template <typename T>
class BSTInterface {
public:
	/** Checks whether the BST is empty.
	* @return True if BST contains no items, false otherwise
	*/
	virtual bool isEmpty() const = 0;
	/** Inserts the specified item into the BST according to the value of its key.
	* @param item Item to be inserted
	* @return True if insertion is successful, false otherwise
	*/
	virtual bool insert(const T& item) = 0;
	/** Removes the specified item from the BST.
	* @param item Item to be removed
	* @return True if removal is successful, false otherwise
	*/
	virtual bool remove(const T& item) = 0;
	/** Checks whether the specified item is in the BST.
	* @param item Item to be searched for
	* @return True if item is found in tree, false otherwise
	*/
	virtual bool contains(const T& item) const = 0;
	/** Removes all items from the BST. */
	virtual void clear() = 0;

	/** Performs an in-order traversal of the BST.
	* This means for each node, the left child is traversed,
	* the current node is visited and then the right child is traversed.
	*/
	virtual void inOrderTraverse() const = 0;
	/** Performs a pre-order traversal of the BST.
	* This means for each node, the current node is visited,
	* the left child is traversed and then the right child is traversed.
	*/
	virtual void preOrderTraverse() const = 0;
	/** Performs a post-order traversal of the BST.
	* This means for each node, the left child is traversed,
	* the right child is traversed and then the current node is visited.
	*/
	virtual void postOrderTraverse() const = 0;
};