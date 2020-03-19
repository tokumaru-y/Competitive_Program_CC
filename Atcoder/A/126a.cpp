#include <stdio.h>
using namespace std;

int main() {
    int n,k;
    scanf("%d %d", &n,&k);
    char s[n];
    scanf("%s", s);
    for(int i = 0; i <n;i++){
        
        if(i == k-1) {
            printf("%c", s[i]+32);
        }else{
            printf("%c", s[i]);
        }
    }
    printf("\n");
} 