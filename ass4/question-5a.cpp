#include <bits/stdc++.h>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){ q2.push(q1.front()); q1.pop(); }
        swap(q1,q2);
    }
    int pop(){
        if(q1.empty()) return INT_MIN;
        int val = q1.front(); q1.pop(); return val;
    }
    int top(){ return q1.empty()?INT_MIN:q1.front(); }
    bool empty(){ return q1.empty(); }
};

int main(){
    StackTwoQueues s;
    s.push(10); s.push(20); s.push(30);
    cout<<s.top()<<"\n"; // 30
    cout<<s.pop()<<"\n"; // 30
    cout<<s.pop()<<"\n"; // 20
}
