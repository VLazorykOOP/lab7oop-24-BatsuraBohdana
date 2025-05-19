#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;


    TreeNode<T>* insert(TreeNode<T>* node, T val) {
        if (!node) return new TreeNode<T>(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T val) {
        root = insert(root, val);
    }

    TreeNode<T>* getRoot() const {
        return root;
    }

    void inorder(TreeNode<T>* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void printInorder() const {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }


    void printWithIterator();
};

// Ітератор для інфіксного обходу
template <typename T>
class TreeIterator {
private:
    stack<TreeNode<T>*> st;

    void pushLeft(TreeNode<T>* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    TreeIterator(TreeNode<T>* root) {
        pushLeft(root);
    }

    bool hasNext() const {
        return !st.empty();
    }

    T next() {
        TreeNode<T>* node = st.top();
        st.pop();
        T result = node->data;
        if (node->right) {
            pushLeft(node->right);
        }
        return result;
    }
};

template <typename T>
void BinaryTree<T>::printWithIterator() {
    TreeIterator<T> it(root);
    cout << "Traversal using iterator: ";
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;
}


int main() {
    BinaryTree<int> tree;

    // Додаємо елементи
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.printInorder();

    tree.printWithIterator();

    return 0;
}
