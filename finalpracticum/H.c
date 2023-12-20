#include <stdio.h>

struct barang{
    int id, kualitas, harga;
    char item[100];
};


int main(){
    int n;
    scanf("%d",&n);
    struct barang barang[n];

    for(int i = 0; i<n;i++){
        scanf("%d",&barang[i].id);
        scanf("%s",barang[i].item);
        scanf("%d%d",&barang[i].harga, &barang[i].kualitas);
    }

    for(int i =0;i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(barang[j].harga > barang[j+1].harga){
                struct barang temp = barang[j];
                barang[j]=barang[j+1];
                barang[j+1] = temp;
            }
            else if(barang[j].harga == barang[j+1].harga){
                if(barang[j].id > barang[j+1].id){
                    struct barang temp = barang[j];
                barang[j]=barang[j+1];
                barang[j+1] = temp;
                }
            }
        }
    }
    printf("Best item for price is: %d %s %d %d\n", barang[0].id, barang[0].item, barang[0].harga, barang[0].kualitas);

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1; j++){
            if(barang[j].kualitas < barang[j+1].kualitas){
                struct barang temp =barang[j];
                barang[j]=barang[j+1];
                barang[j+1]=temp;
            }
            else if(barang[j].kualitas == barang[j+1].kualitas){
                if(barang[j].id > barang[j+1].id){
                struct barang temp = barang[j];
                barang[j]=barang[j+1];
                barang[j+1] = temp;
                }
            }
        }
    }
    printf("Best item for quality is : %d %s %d %d\n", barang[0].id, barang[0].item, barang[0].harga, barang[0].kualitas);


    return 0;
}