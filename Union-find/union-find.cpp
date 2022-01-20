//
// Created by neha2 on 11-01-2022.
//

#include "union-find.h"
/**
* at times, I think why didnt I do it before? There is so much to do and why didnt I? :(
*/
#include <bits/stdc++.h>

using namespace std;
static int i = 0;
enum class command : int {
    UNION, IS_CON
};

void union_points(int &p, int &q, vector<int> &v, vector<int> &);

bool is_conn(int &p, int &q, vector<int> &vector1);

void print(int &a) {
    cout << a << " ";
}

void element(int &a) {
    a = i;
    i++;
}

int main() {

    vector<int> v(10);
    vector<int> sz(10, 1);
//    transform(v.begin(), v.end(),v.begin(),i++);
    for_each(v.begin(), v.end(), element);

    for_each(v.begin(), v.end(), print);
    cout << endl;
    int cmd;
    while (cin >> cmd) {
        switch (static_cast<command>(cmd)) {
            case command::UNION: {
                cout << "for UNION, please enter two numbers p and q" << endl;
                int p, q;
                cin >> p >> q;
                union_points(p, q, v, sz);
                break;
            }
            case command::IS_CON: {
                cout << "for IS_CON, please enter p and q" << endl;
                int p, q;
                cin >> p >> q;
                if (is_conn(p, q, v))
                    cout << "connected" << endl;
                else
                    cout << "not connected" << endl;
                break;
            }
            default:
                cout << "no such command" << endl;
        }
    }
    return 0;
}


int get_id(int &i, const vector<int> &v) {
    return v[i];
}

void set_id(int &i, int &id, vector<int> &v) {
    v[i] = id;
}

int root(int &i, vector<int> &v) {
    int j = i;
    while (get_id(j, v) != j)
    {//quick union and weighted quick union
//        j = get_id(j, v);
        //path compression union
        int pr_j=get_id(j,v);
        int grand_prt= get_id(pr_j,v);
        //grand parent connect than pointing to root (so basically you just cut the length of the path by half)!
//        set_id(pr_j, grand_prt, v);
        j=grand_prt;
    }
    //second way is to write a loop that connects to root of p
    int root=j;
    while(get_id(j,v)!=j){
        int prnt=get_id(j,v);
        j=get_id(prnt,v);//grand parent connect
        set_id(prnt,root,v);//set them to root.
    }
    return root;
}

void union_points(int &p, int &q, vector<int> &v, vector<int> &sz) {
    // Quick find
//    int r_p= get_id(p,v);
//    int r_q=get_id(q,v);
//    for (int i = 0; i < v.size(); i++) {
//        if (get_id(i, v) == r_p) set_id(i, r_q, v);
//    }
//is conn just becomes get_id(p)==get_id(q)
//quick union
//If you have the root info then just connect, root can be traversed.
    int r_p = root(p, v);
    int r_q = root(q, v);
//    set_id(r_p, r_q, v);
    //weighted quick union
    if (sz[r_p] < sz[r_q]) {
        set_id(r_p, r_q, v);
        sz[r_q] = sz[r_q] + sz[r_p];
    } else {
        set_id(r_q, r_p, v);
        sz[r_p] = sz[r_p] + sz[r_q];
    }
    //path compression



}

bool is_conn(int &p, int &q, vector<int> &v) {
    return (root(p, v) == root(q, v)) ? true : false;
}
