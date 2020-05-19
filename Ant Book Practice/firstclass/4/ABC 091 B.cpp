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
    int n,m;cin >> n;
    map<string,int> cards;
    REP(i,n){
        string tmp;cin >> tmp;
        if(cards.find(tmp)!=cards.end()){
            cards[tmp]+=1;
        } else {
            cards[tmp]=1;
        }
    }
    cin >> m;
    REP(i,m){
        string tmp;cin >> tmp;
        if(cards.find(tmp)!=cards.end()){
            cards[tmp]-=1;
        }
    }
    int ans=0;
    auto itr = cards.begin();
    ans = itr->second;
    REP(i,cards.size()-1){
        itr++;
        ans = max(ans,itr->second);
    }
    if(ans<0)ans = 0;
    cout << ans << endl;
}