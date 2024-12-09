#include <iostream>
#include <string>
using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() {
        return this->name;
    }
};

class Node {
private:
    Squirrel* squirrel;
    Node* leftChild;
    Node* rightChild;

public:
    Node(Squirrel* squirrel) {
        this->squirrel = squirrel;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    void set_left(Node* node) {
        this->leftChild = node;
    }

    void set_right(Node* node) {
        this->rightChild = node;
    }

    Node* left() {
        return this->leftChild;
    }

    Node* right() {
        return this->rightChild;
    }

    void display() {
        if (squirrel) {
            cout << squirrel->get_name();
        }
        else {
            cout << "No squirrel";
        }
    }
};

void traverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    traverse(node->left());
    node->display();
    cout << " ";
    traverse(node->right());
}

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    cout << "Left child of root: ";
    if (node_one.left()) {
        node_one.left()->display();
    }
    else {
        cout << "None";
    }
    cout << endl;

    cout << "Right child of root: ";
    if (node_one.right()) {
        node_one.right()->display();
    }
    else {
        cout << "None";
    }
    cout << endl;

    cout << "In-order traversal of the tree: ";
    traverse(&node_one);
    cout << endl;

    return 0;
}
