#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> ll(4);
    for(int i = 0 ;i<=3 ; i++) {
        cin >> ll.at(i);
    }
    for(int i = 1 ; i <=3 ;i++){
        if (ll.at(i-1) == ll.at(i)) {
            cout << "Bad" << endl;
            exit(0);
        }
    }
    cout << "Good" << endl;
}