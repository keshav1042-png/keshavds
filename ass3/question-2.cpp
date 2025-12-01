#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "DataStructure";
    stack<char> s;

    for (char c : str) s.push(c);

    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed string: " << rev << endl;
    return 0;
}
