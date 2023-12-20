#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int w[], int n) {
   int i, j;
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (w[j] < w[j+1]) {
              swap(&w[j], &w[j+1]);
           }
       }
   }
}

int main(){
    int n,h;
    scanf("%d%d", &n, &h);
    int w[n];
    double sumw = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sumw+= w[i];
    }
    bubbleSort(w, n);
    for(int i=0;i<n;i++){
        printf("%d",w[i]);
    }
    /*
    double result = sumw/h;

    if((int)result<result){
        ++result;
    }

    int result2 = (int)result;

    int energy[h];
    for(int i=0;i<h;i++){
        energy[i]=0;
    }
    int index;
    int u =0;
    int temp =0;
    for(index=0;index<h;index++){
        while(energy[index]<result2){
            temp += w[u++];
            if(temp += w[u++ + 1]<result2){
                energy[index]+=w[u];
            }
        }

        printf("%d\n", energy[index]);
    }


    int finalresult =0;
    for(int i = 0;i<h;i++){
        if((energy[i] >= energy[i+1]) && (energy[i] <= (int)result)){
            finalresult = energy[i];
        }
    }
    printf("%d", finalresult);*/
}
