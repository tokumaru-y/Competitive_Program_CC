#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;

signed main () {
    string s;cin >> s ;
    int l = s.length();
    bool flag = true;
    for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i] != s[j]){
            flag = false;
        }
    }
    for(int i=0, j=(l-3)/2;i<=j;i++,j--){
        if(s[i] != s[j]){
            flag=false;
        }
    }
    for(int i=(l+1)/2, j=l-1;i<=j;i++,j--){
        if(s[i] != s[j]){
            flag = false;
        }
    }
    if(flag){
        printf("Yes");
    } else {
        printf("No");
    }
}