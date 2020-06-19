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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    vector<int> list(10);
    REP(i,10){
        int intmp;cin >> intmp;
        list[i]=intmp;
    }
    int n;cin >> n;
    vector<ll> num(n);
    REP(i,n)cin >> num[i];
    sort(ALL(num));
    REP(i,n){
        string tmp=to_string(num[i]);
        for(char a : tmp){
            int aa = a - '0';
            cout << list[aa];
        }
        cout << endl;
    }
}//https://atcoder.jp/contests/arc009/tasks/arc009_2