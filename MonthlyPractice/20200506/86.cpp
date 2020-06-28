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
    int n;cin >> n;
    string s ;cin >> s;
    int ans = 0;
    for(char i='0';i<='9';i++){
        for(char j='0';j<='9';j++){
            for(char k='0';k<='9';k++){
                bool iflag = false;
                bool jflag = false;
                bool kflag = false;
                for(char tm : s){
                    if(!iflag){
                        if(tm==i)iflag=true;
                    } else if(!jflag){
                        if(tm==j)jflag=true;
                    } else if(!kflag){
                        if(tm==k)kflag=true;
                    }
                }
                if(iflag && jflag && kflag)ans++;
            }
        }
    }
    cout << ans << endl;
}