#include <iostream>
using namespace std;

int main () {
    int n,a,b;
    cin >> n >> a >> b;
    int x = a * n; int y = b;
    if (x >= y) {
        cout << y << endl;
    } else {
        cout << x << endl;
    }
}