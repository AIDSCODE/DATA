#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

class tree {
public:
    node *root, *temp, *nnode;
    tree() {
        root = NULL;
    }

    void creation();
    void insertion();
    void inorder(node *temp);
    void display();
    void findMin();
    void mirror(node *root);
    void mirrorTree();
    int height(node *temp);
    void showHeight();
    void searchValue();
};

void tree::creation() {
    cout << "\n Tree Creation \n";
    insertion();
}

void tree::insertion() {
    char ch;
    do {
        nnode = new node;
        nnode->left = nnode->right = NULL;
        cout << "Enter data: ";
        cin >> nnode->data;

        if (root == NULL) {
            root = nnode;
        } else {
            temp = root;
            while (true) {
                if (nnode->data < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = nnode;
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = nnode;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
        cout << "Insert more (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void tree::inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void tree::display() {
    if (root == NULL)
        cout << "Tree is empty.\n";
    else {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }
}

void tree::findMin() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    cout << "Minimum value in the tree: " << temp->data << endl;
}

void tree::mirror(node *root) {
    if (root == NULL)
        return;

    node *swap = root->left;
    root->left = root->right;
    root->right = swap;

    mirror(root->left);
    mirror(root->right);
}

void tree::mirrorTree() {
    mirror(root);
    cout << "Tree has been mirrored successfully.\n";
}

int tree::height(node *temp) {
    if (temp == NULL)
        return 0;
    int lh = height(temp->left);
    int rh = height(temp->right);
    return (lh > rh ? lh : rh) + 1;
}

void tree::showHeight() {
    cout << "Number of nodes in the longest path (height): " << height(root) << endl;
}

void tree::searchValue() {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    int key;
    char ch;
    do {
        cout << "Enter value to search: ";
        cin >> key;
        temp = root;
        bool found = false;

        while (temp != NULL) {
            if (key == temp->data) {
                found = true;
                break;
            } else if (key < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (found)
            cout << "Value found in BST.\n";
        else
            cout << "Value not found in BST.\n";

        cout << "Search more (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

int main() {
    tree obj;

    obj.creation();

    cout << "\nYour BST (Inorder Traversal): ";
    obj.display();

    cout << "\n Insert a new node \n";
    obj.insertion();
    cout << "\nUpdated BST: ";
    obj.display();

    obj.showHeight();

    obj.findMin();

    cout << "\n Search Operation \n";
    obj.searchValue();

    cout << "\n Mirroring the tree \n";
    obj.mirrorTree();
    obj.display();
}

