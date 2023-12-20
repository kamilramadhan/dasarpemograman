#include <stdio.h>

int cekdigit(int x){
    int digit=0;
    while(x!=0){
        x /= 10;
        ++digit;
    }

    if(digit % 2 == 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int x;
    int y;  
    scanf("%d", &x);
    scanf("%d", &y);
    int digit = 0;
    int min;
        if(x>y){
            min = y;
        }
        else{
            min = x; 
        }
    if(x%y == 0|| y%x ==0){
        digit = cekdigit(min);
    }
    else{
        for(int i=min; i>=1;i--){
            if(x%i == 0 && y%i == 0){
                digit = cekdigit(i);
                break;
            }
        }
    }

    if(digit){
        printf("Yey brankas berhasil dibuka :D");
    }
    else{
        printf("Yah gagal :(");
    }
    return 0;
    
}