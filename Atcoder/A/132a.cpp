#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/* int main() {
    unordered_map<string , int > ll;
    string a ;
    cin >> a ;
    for (int i = 0; i <=3 ;i++) {
        int itr = ll.count(a[i]);
        if (itr != ll.end()) {
            ll[a[i]] += 1;
        } else {}
    }
} */
int main() {
    vector<char>s(4);
    for(int i = 0 ; i <=3 ; i++) {
        cin >> s.at(i);
    }
    sort(s.begin(),s.end());
    if (s.at(0) == s.at(1) && s.at(1) != s.at(2) && s.at(2) == s.at(3)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}