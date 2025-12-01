#include <bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int>&q){
    int n = q.size();
    if(n%2==1){ cout<<"Need even number of elements\n"; return; }
    int half = n/2;
    queue<int> first;
    for(int i=0;i<half;i++){
        first.push(q.front()); q.pop();
    }
    // interleave using first and q (q now has second half in original order)
    while(!first.empty()){
        q.push(first.front()); first.pop();
        q.push(q.front()); q.pop();
    }
}

int main(){
    queue<int> q;
    int x;
    cout<<"Enter numbers (space separated), end with -1:\n";
    while(cin>>x && x!=-1) q.push(x);
    interleaveQueue(q);
    cout<<"Result: ";
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); }
    cout<<"\n";
    return 0;
}
