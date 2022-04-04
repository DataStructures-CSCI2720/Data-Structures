#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

/**
 * @brief NodeType pointer object that stores the item, a left child pointer, and right child pointer.
 *
 * @tparam T
 */
template<class T>
struct NodeType {
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
}; // NodeType

/**
 * @brief Binary Tree contains a root pointer to the first value in the tree. Also contained are user
 * interactions to insert items, delete items, retrieving items, various prints, etc.
 *
 * @tparam T
 */
template<class T>
class BinaryTree {

    private:
        NodeType<T> *root;

    public:
        BinaryTree();                                   // Binary Tree object constructor

        ~BinaryTree();                                  // Binary Tree object destructor

        void insert(T &key);                            // insert item into the tree

        void deleteItem(T &key);                        // delete item from the tree

        bool helpRetrieve(T &item, bool &found);        // verifies whether an item is in the list

        void retrieve(T &item, bool &found) const;      // retrieves an item from a list

        void preOrder() const;                          // prints items in list in pre-order style

        void inOrder() const;                           // prints items in list in in-order style

        void postOrder() const;                         // prints items in list in post-order style

        int getLength() const;                          // returns the length of the list

        int getNumSingleParent() const;                 // returns number of items with only one child pointer

        int getNumLeafNodes() const;                    // returns number of items without any child pointers

        void getSumOfSubtrees(NodeType<T> *&node) const;   // returns the sum of child pointers from reference pointer

}; // Binary Tree

#endif
