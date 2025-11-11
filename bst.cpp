#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* root = NULL;

Node* tempRoot = NULL;

void insertNode() {
    int value;
    cout << "Enter value to insert: ";
    cin >> value;

    Node* newNode = new Node(value);

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
            return; 
    }

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

int leftHeight, rightHeight;
int findHeight() {
    if (tempRoot == NULL)
        return 0;

    Node* saveRoot = tempRoot;

    tempRoot = saveRoot->left;
    leftHeight = findHeight();

    tempRoot = saveRoot->right;
    rightHeight = findHeight();

    tempRoot = saveRoot;
    return max(leftHeight, rightHeight) + 1;
}

int findMinimum() {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp->data;
}

void mirrorTree() {
    if (tempRoot == NULL)
        return;

    Node* saveRoot = tempRoot;

    Node* temp = saveRoot->left;
    saveRoot->left = saveRoot->right;
    saveRoot->right = temp;

    tempRoot = saveRoot->left;
    mirrorTree();

    tempRoot = saveRoot->right;
    mirrorTree();

    tempRoot = saveRoot; 
}


void searchValue() {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    Node* current = root;
    while (current != NULL) {
        if (current->data == key) {
            cout << key << " found in BST!" << endl;
            return;
        }
        else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    cout << key << " not found in BST!" << endl;
}

void inorder() {
    if (tempRoot != NULL) {
        Node* saveRoot = tempRoot;

        tempRoot = saveRoot->left;
        inorder();

        cout << saveRoot->data << " ";

        tempRoot = saveRoot->right;
        inorder();

        tempRoot = saveRoot; 
    }
}

int main() {
    int n;
    cout << "Enter number of elements to insert initially: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        insertNode();

    tempRoot = root;
    cout << "\nInorder traversal of BST: ";
    inorder();
    cout << endl;

    insertNode();
    tempRoot = root;
    cout << "Inorder after insertion: ";
    inorder();
    cout << endl;

    tempRoot = root;
    cout << "\nNumber of nodes in longest path (Height): " << findHeight() << endl;

    cout << "Minimum value in BST: " << findMinimum() << endl;

    searchValue();

    tempRoot = root;
    mirrorTree();
    tempRoot = root;
    cout << "Inorder traversal after mirroring: ";
    inorder();
    cout << endl;

    return 0;
}

