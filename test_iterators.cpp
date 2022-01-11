//
// Created by neha2 on 07-01-2022.
//

#include "test_iterators.h"
#include <bits/stdc++.h>

#include <iterator>

using namespace std;

int main() {
    //Input iterator
    {
        istream_iterator<int> i(cin);
        istream_iterator<int> j;
        for (int c = 0; c < 3;) {
            int element1 = *i;
            int element1_copy = *i;
            j = i;
            cout << "you entered " << element1 << endl;
            int r = *j;
            cout << "random element is" << r << endl;
            if (i == j) {
                cout << "i equal to random empty j" << endl;
                j = i;
            }
            ++i;
            c++;
        }
        cin.clear();
    }
    //Output iterator
    {
        ostream_iterator<int> o(cout, "\n");
        *o = 1;
        o++;
        *o = 2;
        o++;
        *o = 3;
        o++;
        cout.clear();
//TODO: Note: The error in above stream ,sets the M_ok flag of istream iterator to false and that flag is reused. meaning it sognals the eof of stream and then the next istream iterator to read  into vector reads none, resultingina nempty vector.
//TODO: I am not abel to find out how to reset the flag or reinitialise the stream or to use the iterator again.
        vector<int> v;
        istream_iterator<int> k(cin);
        copy(k, istream_iterator<int>(), back_inserter(v));
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
        cout<<endl;
        //Op iterator s used at LHS and input iterator is used at RHS.
    }
    //Forward iterator
    {
        vector<int> v;
        replace(v.begin(), v.end(), 23, 1);
        replace_if(v.begin(), v.end(), [](double x) { return (x == 2.0) ? true : false; }, 1);
    }
    //Bidirectional iterator
    list<int> aList(1, 1);
    aList.push_back(2);
    aList.push_back(0);
    auto last = aList.end();
    aList.emplace_back(1);
    aList.emplace_back(5);
    auto first = aList.begin();
    while (last-- != first) {
        cout << *last << " ";
    }
    cout<<endl;
    auto e=aList.rbegin();
    auto b=aList.rend();
    while(e!=b){
        cout<<*e<<'\t';
        e++;
    }
    return 0;
}
