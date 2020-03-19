#include <iostream>
#include <string>
using namespace std;

int main() {
    string a,b;
    int ans = 0;
    cin >> a;
    cin >> b;
    for(int i = 0 ;i <= 2 ; i++){
        if (a[i] == b[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}