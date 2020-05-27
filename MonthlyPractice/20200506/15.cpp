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
    //BXXXA
    int a=0;
    //XXXXA
    int b=0;
    //BXXXXx
    int c=0;
    int ans=0;
    REP(i,n){
        string tmp;cin >> tmp;
        REP(i,tmp.length()-1){
            if(tmp[i]=='A' && tmp[i+1]=='B')ans++;
        }
        if(tmp[0]=='B'){
            if(tmp[tmp.length()-1]=='A'){
                a++;
            } else {
                c++;
            }
        } else if(tmp[tmp.length()-1]=='A'){
            b++;
        }
    }
    if(a==0){
        ans += min(b,c);
    } else {
        if(b+c==0)ans+=a-1;
        else ans+=a+min(b,c);
    }
    cout << ans << endl;
}//https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c