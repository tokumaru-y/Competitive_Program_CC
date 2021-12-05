// https://atcoder.jp/contests/abc079/tasks/abc079_c
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
typedef long long ll;
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
const int MOD = (int)1e9 + 7;
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    string a;cin >> a;
    for(int bit=0;bit<(1<<3);bit++){
        int pro_num = a[0] - '0';
        REP(j,3){
            if (bit & (1<<j)){
                pro_num -= a[j+1] - '0';
            } else {
                pro_num += a[j+1] - '0';
            }
        }
        if (pro_num == 7) {
            cout << a[0];
            REP(j,3){
                if (bit & (1<<j)){
                    cout << "-";
                } else {
                    cout << "+";
                }
                cout << a[j+1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}