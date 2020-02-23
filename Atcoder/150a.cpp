#include <iostream>
using namespace std;

int main() {
    int k,x ;
    cin >> k >> x;
    int sum = k * 500;
    if (sum >= x) {
        puts("Yes");
    } else {
        puts("No");
    }
}