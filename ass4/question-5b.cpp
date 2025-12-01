#include <bits/stdc++.h>
using namespace std;

class StackOneQueue {
    queue<int> q;
public:
    void push(int x){
        q.push(x);
        int sz = q.size();
        for(int i=0;i<sz-1;i++){
            q.push(q.front()); q.pop();
        }
    }
    int pop(){
        if(q.empty()) return INT_MIN;
        int v=q.front(); q.pop(); return v;
    }
    int top(){ return q.empty()?INT_MIN:q.front(); }
    bool empty(){ return q.empty(); }
};

int main(){
    StackOneQueue s;
    s.push(5); s.push(10); s.push(15);
    cout<<s.top()<<"\n"; //15
    cout<<s.pop()<<"\n"; //15
    cout<<s.pop()<<"\n"; //10
}
