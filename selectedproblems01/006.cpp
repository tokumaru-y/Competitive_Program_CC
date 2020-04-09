#include <bits/stdc++.h>
#include <iostream>
#define FOR(i,a,b) for(int i= (a); i<(b); i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
using namespace std;

const long long INF = 1LL << 60;
const int MOD = (int)1e9 + 7;
typedef long long ll;
//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

signed main () {
    int n;scanf("%d",&n);
    string s; cin >> s;
    char list[] = {'0','1','2','3','4','5','6','7','8','9'};
    int ans=0;
    for(char i : list){
        for(char j : list){
            for(char k : list){
                int flag = 0;
                for(char t : s){
                    if(flag == 0){
                        if(i==t){
                            flag = 1;
                        }
                    } else if (flag == 1){
                        if(j==t){
                            flag = 2;
                        }
                    } else if (flag == 2){
                        if(k==t){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d",ans);
}