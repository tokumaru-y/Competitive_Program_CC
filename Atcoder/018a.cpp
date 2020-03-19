#include <bits/stdc++.h>
using namespace std;
int main () {
    int s[3];
    int pre[3];
    map<int, int> map;
    for(int i=0;i<3;i++){
        int p;scanf("%d",&p);
        s[i]=p;pre[i]=p;
    }
    sort(s,s+3,greater<>());
    for(int i=0;i<3;i++){
        map[s[i]] = i+1;
    }
    for(int i=0;i<3;i++){
        printf("%d\n",map[pre[i]]);
    }
}