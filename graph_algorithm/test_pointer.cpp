//
// Created by neha2 on 17-01-2022.
//
using namespace  std;
#include <bits/stdc++.h>
struct Point_test{
    int x, y;
    Point_test(int a, int b):x(a), y(b){}
    Point_test()=delete;
    //Cant write it without frined here
    friend ostream& operator<<(ostream &o, const Point_test &p){
        cout<<p.x<<p.y<<endl;
        return o;
    }
};
/**
 * https://onedrive.live.com/view.aspx?resid=B71DD6F7FC1E1489%212926&id=documents&wd=target%28Constructors.one%7C4A20AB78-FB05-4E8B-B8AE-231DCB4BBCF5%2FMove%20semantics%7C9137A182-472B-4C3F-94A9-A0DC704302A1%2F%29
onenote:https://d.docs.live.net/b71dd6f7fc1e1489/Documents/Notes/CPP/Constructors.one#Move%20semantics&section-id={4A20AB78-FB05-4E8B-B8AE-231DCB4BBCF5}&page-id={9137A182-472B-4C3F-94A9-A0DC704302A1}&end
 * @return
 */
int main(){
    Point_test* p=new Point_test(1, 2);
    set<pair<int, int>> pq;
    pq.insert(make_pair(10, 1));
    pq.insert(make_pair(10, 2));
    for(auto p:pq){
        cout<<p.first<<" "<<p.second<<endl;
    }

    Point_test r(1,2);
    vector<Point_test> v;
//    v.push_back(*p);
//    v[0]=p;
    v.push_back(r);
    Point_test q=v.front();
    cout<<p<<" " <<q<<" "<<&q<<" "<<&v[0]<<endl;
    cout<<"r "<<endl;
    cout<<&r<<" "<<v[1]<<" "<<&v[1]<<endl;
}
