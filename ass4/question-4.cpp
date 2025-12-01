#include <bits/stdc++.h>
using namespace std;

vector<int> firstNonRepeating(const string &s){
    vector<int> freq(256,0);
    queue<char> q;
    vector<int> result;
    for(char ch: s){
        freq[ch]++;
        q.push(ch);
        while(!q.empty() && freq[q.front()]>1) q.pop();
        if(q.empty()) result.push_back(-1);
        else result.push_back(q.front());
    }
    return result;
}

int main(){
    string s;
    cout<<"Enter stream (no spaces) e.g. aabc:\n";
    cin>>s;
    auto res = firstNonRepeating(s);
    for(int v: res){
        if(v==-1) cout<<-1<<" ";
        else cout<<char(v)<<" ";
    }
    cout<<"\n";
    return 0;
}
