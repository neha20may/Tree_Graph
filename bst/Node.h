//
// Created by neha2 on 06-01-2022.
//

#ifndef COURSERA_PART2_NODE_H
#define COURSERA_PART2_NODE_H

#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

namespace xyz {
    template<class T>
    struct createPoint {
        T operator()() {
            T x = 1 + rand() % 10;
            return x;
        };
    };
}

template<class Container, class T>
Container generate_points(int N) {
    Container v(N);
    srand(time(0));
    xyz::createPoint<T> t;
    for (int i = 1; i <= N; i++) {
        v.insert(t());
    }
    return v;
};

class Node {
private:
    double key;
    Node *left;
    Node *right;
public:
    Node(double k, Node *l, Node *r);

    Node();

    Node(const Node &n);

    Node &operator=(const Node &n);

    Node(Node &&rhs);

    Node &operator=(Node &&n);

    double getKey();

    Node *getLeftPointer() const;

    Node *getRightPointer() const;

    void setLeft(Node *node);

    void setRight(Node *node);

    friend std::ostream &operator<<(std::ostream &o, const Node &n);

};

Node *makeTree(std::unordered_set<double> keys, Node *&root, std::vector<Node> &nodes);

void printTree(Node *root);

Node find_min(Node *&root);

int func(int *&x);

#endif //COURSERA_PART2_NODE_H
