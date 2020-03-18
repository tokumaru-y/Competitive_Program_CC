#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    cin >> s;
    int a;scanf("%d",&a);
    int cnt =0;
    for(int i=0;i<s.length();i++){
        for(int j=0;j<s.length();j++){
            cnt++;
            if(cnt==a){
                cout << s[i] << s[j] << endl;
                break;
            }
        }
    }
}