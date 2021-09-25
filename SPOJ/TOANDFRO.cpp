#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 202
#define MAXC 22

int main(){
    int c;
    char a[MAXN], tmp[MAXC][MAXN>>1];
    while(1){
        scanf("%d", &c);
        if(!c) break;
        scanf("%s", a);

        int x = 0;
        for(int i = 0; i < strlen(a)/c; ++i){
            int j = i%2?c-1:0, d = i%2?-1:1;
            for(; j!=-1 && j!=c; j+=d) tmp[j][i] = a[x++];
        }
        for(int j = 0; j < c; ++j) {
            tmp[j][strlen(a)/c] = '\0';
            printf("%s", tmp[j]);
        }
        printf("\n");
    }
    return 0;
}
