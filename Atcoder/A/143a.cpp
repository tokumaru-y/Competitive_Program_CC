#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int ans = a - b*2;
    if (ans <= 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}