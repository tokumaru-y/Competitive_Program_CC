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
    int h,w;cin >> h >> w;
    vector<ll> needs;
    int limitH = h/2;int limitW=w/2;
    if(h%2==0)limitH--;if(w%2==0)limitW--;
    map<char,int> cnt;
    REP(i,h)REP(j,w){
        char tmp;cin >> tmp;
        cnt[tmp]++;
    }
    vector<ll> list;
    priority_queue<ll> que;
    for(auto c:cnt){
/*         que.push(c.second);
 */        list.push_back(c.second);
    }
    sort(ALL(list));
    for(int i=0;i<=limitH;i++){
        for(int j=0;j<=limitW;j++){
            if(list.empty()){
                cout << "No" << endl;return 0;
            }
            int needs=4;
            if((h%2==1 && i==limitH) && (w%2==1 && j==limitW)) {
                needs = 1;
            }
            else if((h%2==1 && i==limitH) || (w%2==1 && j==limitW)){
                needs=2;
            }
            auto itr = lower_bound(ALL(list),needs);
            if(itr==list.end()){
                cout << "No" << endl;return 0;
            }
            *itr-=needs;
            sort(ALL(list));
        }
    }
    cout << "Yes" << endl;
}//https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c