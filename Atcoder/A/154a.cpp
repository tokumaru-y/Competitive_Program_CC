#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string a,b;
    int x,y;
    unordered_map<string, int> ll;
    cin >> a >> b;
    cin >> x >> y;
    string tmp;
    cin >> tmp;
    ll[a] = x;
    ll[b] = y;
    ll[tmp] -= 1;
    cout << ll[a] << ' ' << ll[b] << endl;
}