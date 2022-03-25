#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct NodeType {
    T key;
    NodeType<T> *left;
    NodeType<T> *right;
}; // NodeType

template<class T>
class BinaryTree {

    private:
        NodeType<T> *root;

    public:
        BinaryTree();

        ~BinaryTree();

        void insert(T &key);

        void deleteItem(T &key);

        void retrieve(T &item, bool &found) const;

        void preOrder() const;

        void inOrder() const;

        void postOrder() const;

        int getLength() const;

        int getNumSingleParent() const;

        int getNumLeafNodes() const;

        int getSumOfSubtrees(NodeType<T> &node) const;
}; // Binary Tree

#endif