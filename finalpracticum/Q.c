#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int c;
    scanf("%d ", &c);

    if(c==1){
        int count=0;
        char m[251];
        char *input;
        while((input=getchar()) != EOF){
            m[count]=input;
            ++count;
        }
        int length = strlen(m);
        for(int i=0;i<length;i++){
           int angka = m[i];
           for(int j=7;j>=0;j--){
                putchar(((angka>>j)&1)+'0');
            }
        }

    }
    else {
        int index=0; char c[8001];char h[251];
        scanf("%[^\n]s",c);
        int l=strlen(c); int result=0;int counter=0;
        for(int i=1;i<=l;i++){
            if(c[i-1] - '0'){
                result+=pow(2*(c[i-1]-'0'),7-counter);
                ++counter;
            }
            else{
                ++counter;
            }
            if(i % 8 ==0){
                h[index] = result;
                result=0;
                ++index;
                counter=0;
            }
        }
        h[index]='\0';
        printf("%s",h);
    }

    return 0;
}
