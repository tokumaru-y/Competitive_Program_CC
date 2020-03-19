#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int x,y,z;
    x = a - b; y = a + b ; z = a * b;
    if (x >= y && x >= z){
        cout << x << endl;
    } else if (y >= x && y >= z) {
        cout << y << endl;
    } else {
        cout << z << endl;
    }
}