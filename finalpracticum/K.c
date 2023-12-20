#include <stdio.h>
#include <string.h>

int main(){
    char S[101];
    scanf("%s", S);
    int K;
    scanf("%d", &K);
    int len = strlen(S);

    for(int i = 0; i< len;i++){
        if(S[i] >= 'a' && S[i] <= 'z'){
            S[i] = 'a' + (S[i] - 'a' + K) %26;
        }
        
        printf("%c", S[i]);
    }
}   