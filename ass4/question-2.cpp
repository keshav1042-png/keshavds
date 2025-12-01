#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    vector<int> arr;
    int capacity;
    int frontIdx, rearIdx, count;
public:
    CircularQueue(int cap=10): capacity(cap), arr(cap), frontIdx(0), rearIdx(-1), count(0){}

    bool isEmpty(){ return count==0; }
    bool isFull(){ return count==capacity; }

    void enqueue(int x){
        if(isFull()){ cout<<"Queue full\n"; return; }
        rearIdx = (rearIdx+1) % capacity;
        arr[rearIdx] = x;
        count++;
    }
    int dequeue(){
        if(isEmpty()){ cout<<"Queue empty\n"; return INT_MIN; }
        int val = arr[frontIdx];
        frontIdx = (frontIdx+1) % capacity;
        count--;
        return val;
    }
    int peek(){
        if(isEmpty()){ cout<<"Queue empty\n"; return INT_MIN; }
        return arr[frontIdx];
    }
    void display(){
        if(isEmpty()){ cout<<"Queue empty\n"; return; }
        int idx = frontIdx;
        for(int i=0;i<count;i++){
            cout<<arr[idx]<<" ";
            idx = (idx+1)%capacity;
        }
        cout<<"\n";
    }
};

int main(){
    CircularQueue q(6);
    int ch,x;
    while(true){
        cout<<"\n1-enqueue 2-dequeue 3-peek 4-display 0-exit\n>";
        cin>>ch;
        if(ch==0) break;
        if(ch==1){ cin>>x; q.enqueue(x); }
        else if(ch==2){ int v=q.dequeue(); if(v!=INT_MIN) cout<<"Dequeued "<<v<<"\n"; }
        else if(ch==3){ int v=q.peek(); if(v!=INT_MIN) cout<<"Front "<<v<<"\n"; }
        else if(ch==4) q.display();
        else cout<<"Invalid\n";
    }
    return 0;
}
