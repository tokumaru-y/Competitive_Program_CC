#include <iostream>
using namespace std;

int main() {
    char a;
    cin >> a ;
    for (char b = 'a'; b <= 'z'; b++) {
        if (a == b) {
            cout << ++b << endl;
            break;
        }
    }
}