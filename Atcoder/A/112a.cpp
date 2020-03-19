#include <stdio.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n==2){
        int ab[2];
        for(int i=0;i<2;i++){
            scanf("%d", &ab[i]);
        }
        printf("%d", ab[0] + ab[1]);
    } else {
        printf("%s", "Hello World");
    }
}