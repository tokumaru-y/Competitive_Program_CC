#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i < (n);i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define SCANF(i) int i;scanf("%d",&i)
using namespace std;
using P = pair<int,int>;
const long long INF = 1LL << 60;
const int IINF=100000000;
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
vector<int> dx={1,0,-1,0};vector<int> dy={0,-1,0,1};

signed main () {
    int n[4];
    REP(i,4){
        char s;cin >> s;
        n[i]=s-'0';
    }
    for(int i=0;i<(1<<3);i++){
        int tmp = n[0];
        for(int j=0;j<3;j++){
            if(i&(1<<j))tmp-= n[j+1];
            else tmp += n[j+1];
        }
        if(tmp == 7){
            for(int j=0;j<3;j++){
                if(i&(1<<j)){
                    cout << n[j] << '-';
                } else {
                    cout << n[j] << '+';
                }
            }
            cout << n[3] << "=7" << endl;
            exit(0);
        }
    }
}