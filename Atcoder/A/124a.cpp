#include <stdio.h>
using namespace std;

int main() {
    int a,b;
    int ans(0);
    scanf("%d %d", &a,&b);
    for(int i =0;i <2;i++){
        if(a<=b){
            ans += b;
            b--;
        } else {
            ans += a;
            a--;
        }
    }
    printf("%d", ans);
}