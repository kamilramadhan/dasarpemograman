#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int hasil=0;
    int hasil4[n];
        for(int i=0;i<n;i++){
            hasil4[i]=0;
        }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d",a[0]);
        return 0;
    }
    else if(n==2){
        hasil = a[n-1]-a[n-2];
        printf("%d",hasil+a[n-1]);
        return 0;
    }
    else if(n==3){
        for(int i=0;i<n-1;i++){
            hasil4[i] = a[i+1] - a[i];
        }
        int p=hasil4[1]-hasil4[0];
        printf("%d", a[2]+hasil4[1]+p);
    }
    else if(n==4){
        for(int i=0;i<n-1;i++){
            hasil4[i] = a[i+1] - a[i];
        }
        int p=hasil4[1]-hasil4[0];
        int q=hasil4[2]-hasil4[1];
        int r=q-p;
        printf("%d", a[3]+hasil4[2]+r+q);
    }
    else if(n==5){

        for(int i=0;i<n-1;i++){
            hasil4[i] = a[i+1] - a[i];
        }
        int p=hasil4[1]-hasil4[0];
        int q=hasil4[2]-hasil4[1];
        int r=hasil4[3]-hasil4[2];
        int pp=q-p;
        int qq=r-q;
        int pq=qq-pp;
        printf("%d", a[4]+hasil4[3]+r+qq+pq);

        return 0;
    }

}