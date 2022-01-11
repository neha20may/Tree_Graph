//
// Created by neha2 on 06-01-2022.
//

#include <unordered_set>
#include "Node.h"
#include <iostream>

/**
 * The questions that need to be answered:
 * 1. does tree work as expected or the local variable disappearance act happen any where?
 * @param key
 * @param root
 * @return
 */

Node::Node(double k, Node *l, Node *r) : key(k), left(l), right(l) {};

Node::Node() : key(0.0), left(nullptr), right(nullptr) {}

Node::Node(const Node &n) {
    this->key = n.key;
    this->left = n.left;
    this->right = n.right;
    std::cout<<"copy constructor"<<std::endl;
}
Node& Node::operator=(const Node &n) {
    this->key=n.key;
    this->left=n.left;
    this->right=right;
    std::cout<<"copy assignment"<<std::endl;
    return *this; //for chaining

}
Node::Node(Node &&n){
    key=std::exchange(n.key,0.0);
    left=std::move(n.left);
    right=std::exchange(n.right, nullptr);
    std::cout<<"move constructor of Point"<<std::endl;

}

Node &Node::operator=(Node &&n){
    key=std::exchange(n.key,0.0);
    left=std::move(n.left);
    right=std::exchange(n.right, nullptr);
    std::cout<<"move assignment operator of Point"<<std::endl;
    return *this;

}
double Node::getKey() {
    return key;
}

Node *Node::getLeftPointer() const {
    return left;
}

Node *Node::getRightPointer() const {
    return right;
}

void Node::setLeft(Node *node) {
    left = node;
}

void Node::setRight(Node *node) {
    right = node;
}

std::ostream &operator<<(std::ostream &o, const Node &n) {
    std::cout << n.key << " ";
}

Node *findPos(double key, Node *root) {
    if (root == nullptr)
        return nullptr;
    Node *current = root;
    if (key < current->getKey()) {
        if (current->getLeftPointer() == 0)
            return current;
        else {
            current = current->getLeftPointer();
            findPos(key, current);
        }

    } else {
        if (current->getRightPointer() == 0)
            return current;
        else {
            current = current->getRightPointer();
            findPos(key, current);
        }
    }
}

void printTree(Node *root) {
    if (root == nullptr)
        return;
    std::cout << *root;
    printTree(root->getLeftPointer());
    printTree(root->getRightPointer());
}

Node *makeTree(std::unordered_set<double> keys, Node *&root, std::vector<Node> &nodes) {
//    Node *root;
//    std::vector<Node> nodes;
    for (auto k: keys) {
        nodes.push_back(Node(k, nullptr, nullptr));
    }
    for (auto k = nodes.begin(); k < nodes.end(); k++) {
        if (root == nullptr) {
            root = k.base();
            //simpy root =&node is wrong, the node is local variable and it gets instantiated in each for loop at the same location, while root maintains the old address.
        } else {
            auto position_node = findPos(k->getKey(), root);
            if (position_node->getKey() > k->getKey()) {
                //Question: does this local instantiation of node works for outer scope?
                //call by value dictates a copy of object is passed to the function and that copy is referenced in the left and right pointer, now the
                //question is this copy which is passed to set function, does that work outside of this function?
                //If this way doesnt work then main needs to pass the vector of nodes  than keys.
                position_node->setLeft(k.base());
            } else {
                position_node->setRight(k.base());
            }
        }
    }
    return root;
};

Node find_min(Node *&root) {
    if (root->getLeftPointer() == nullptr) {
        return *root; }
    else {
        auto l = root->getLeftPointer();
        auto min=find_min(l);
        return min; //this return happens using move constructor .!Phew!
    }
};

int func(int *&x) {
    return *x;
}