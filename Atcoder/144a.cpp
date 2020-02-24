#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (a >= 10 || b >= 10){
        cout << -1 << endl; 
    } else {
        cout << a * b << endl;
    }
}