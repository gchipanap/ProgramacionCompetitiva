#include <iostream>
#include <algorithm>

template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
};

template <typename T>
Node<T>* createNode(const T& data)
{
    return new Node<T> {data, nullptr, nullptr};
}

template <typename T>
void deleteTree(Node<T>* root)
{
    if(root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

template <typename T>
int getHeight(Node<T>* root)
{
    if(root == nullptr)
        return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

template <typename T>
bool isBalanced(Node<T>* root)
{
    if(root == nullptr)
        return true;
    return std::abs(getHeight(root->left) - getHeight(root->right)) < 2;
}

int main()
{
    Node<int>* root {createNode(10)};

    root->left = createNode(8);
    root->right = createNode(12);
    root->left->left = createNode(4);
    std::cout << isBalanced(root) << std::endl;

    root->left->left->left = createNode(2);
    std::cout << isBalanced(root) << std::endl;

    deleteTree(root);

    return 0;
}