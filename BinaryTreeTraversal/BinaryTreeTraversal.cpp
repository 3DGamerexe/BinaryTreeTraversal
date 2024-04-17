/* Homework #5, Aaliyah Madison */

#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

class BTNode {
public:
    //class DFT;

    BTNode* left;
    BTNode* right;
    int value;

    BTNode(int info, BTNode* l = nullptr, BTNode* r = nullptr) {
        value = info;
        left = l;
        right = r;
    }
};

void visit(BTNode* node) {
    cout << node->value << " ";
}

BTNode* insert(BTNode* root, int val) {
    if (!root) {
        return new BTNode(val);
    }
    if (val < root->value) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

BTNode* createTree(vector<int>& seq) {
    BTNode* root = nullptr;
    for (int i : seq) {
        root = insert(root, i);
    }
    return root;
}


void breadthFirst(BTNode* root) {
    if (!root) {
        return;
    }

    std::queue<BTNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        BTNode* curr = queue.front();
        queue.pop();
        visit(curr);

        if (curr->left) {
            queue.push(curr->left);
        }
        if (curr->right) {
            queue.push(curr->right);
        }
    }
}

bool searchTree(BTNode* p, const int& el) {
    bool valuePresent = false;
    while (p != nullptr) { //while the tree is not empty
        if (el == p->value) {
            valuePresent = true;
            cout << p->value;
            break;
        }
        else if (el < p->value)
            p = p->left;
        else
            p = p->right;
    }
    if (valuePresent == false) {
        cout << "There is no such node in the tree!" << endl; 
    }
    return valuePresent;
}

class DFT {
public:
    void preorder(BTNode* p) {
        if (p != 0) {
            visit(p);
            preorder(p->left);
            preorder(p->right);
        }
    }

    void inorder(BTNode* p) {
        if (p != 0) {
            inorder(p->left);
            visit(p);
            inorder(p->right);
        }
    }

    void postorder(BTNode* p) {
        if (p != 0) {
            postorder(p->left);
            postorder(p->right);
            visit(p);
        }
    }
};

void Menu() {
    std::cout << endl;
    std::cout << std::setw(25) << "M E N U" << endl;
    std::cout << "Create (0), Search (1), Breadth-First Traversal (2)" << endl;
    std::cout << "Depth-First Traversal: preorder (3), inorder (4), postorder (5)" << endl << endl;
    std::cout << "Exit Program(6)" << endl << endl;
}

int main()
{
    int menuValue;
    int userValues;
    vector<int> sequence; //allows max 6 values
    BTNode* root = nullptr;
    DFT depthTraversal;

    do {
        Menu();
        std::cout << std::setw(20) << "Choose? ";
        std::cin >> menuValue;

        if (menuValue < 0 || menuValue > 6 || cin.fail()) {
            std::cout << "Invalid. Enter a valid number provided in the Menu." << endl;
        }
        else {
            switch (menuValue) {
            case 0: {
                int i = 0;
                while (i < 6) {
                    cin >> userValues;
                    sequence.push_back(userValues);
                    i++;
                }
                root = createTree(sequence);
                break;
            }
            case 1:
                cin >> userValues;
                searchTree(root, userValues);
                break;

            case 2:
                if (root != nullptr)
                    breadthFirst(root);
                else
                    cout << "Oops! Tree does not exist yet. Try creating one first." << endl;
                break;
            case 3:
                if (root != nullptr) {
                    depthTraversal.preorder(root);
                }
                else
                    cout << "Oops! Tree does not exist yet. Try creating one first." << endl;
                break;
            case 4:
                if (root != nullptr) {
                    depthTraversal.inorder(root);
                }
                else 
                    cout << "Oops! Tree does not exist yet. Try creating one first." << endl;
                break;
            case 5:
                if (root != nullptr) {
                    depthTraversal.postorder(root);
                }
                else 
                    cout << "Oops! Tree does not exist yet. Try creating one first." << endl;
                break;
            }
        }
        if (menuValue == 6) {
            std::cout << "Thank you! Have a nice day!" << endl;
        }

    } while (menuValue != 6);
}