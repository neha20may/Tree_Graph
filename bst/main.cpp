#include <iostream>
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

int main() {
    int x=100;
    int *z=&x;
    int y= func(z);
    cout<<y<<endl;
    auto keys= generate_points<unordered_set<double>, double>(2);
    Node* root= nullptr;
    vector<Node> nodes;
    root=makeTree(keys, root, nodes);
//    for (auto n:nodes)
//        cout<<n;

    copy(nodes.begin(), nodes.end(), ostream_iterator<Node>(cout," "));
    cout<<endl;
    cout<<"Binary search tree is "<<endl;
    printTree(root);
    cout<<endl;
    Node min= find_min(root);
    cout<<"min is "<<min;
    return 0;
}
