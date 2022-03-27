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
        BinaryTree(); // done

        ~BinaryTree(); // done

        void insert(T &key); // done

        void deleteItem(T &key); // hard not even close to being done

        void retrieve(T &item, bool &found) const; // done

        void preOrder() const; // done

        void inOrder() const; // done

        void postOrder() const; // done

        int getLength() const; // done

        int getNumSingleParent() const; // done

        int getNumLeafNodes() const; // done

        int getSumOfSubtrees(NodeType<T> *&node) const; // done
}; // Binary Tree

#endif