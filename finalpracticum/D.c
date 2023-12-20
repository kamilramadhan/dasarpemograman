#include <stdio.h>
#include <math.h>

int main(){
    int wm,hm;
    int xr,yr;
    int wr,hr;
    int xu,yu;
    scanf("%d %d %d %d %d %d %d %d", &wm,&hm,&xr,&yr,&wr,&hr,&xu,&yu);
    
    if(xu >= (xr-wr/2) && xu <= (xr+wr/2) && yu >= (yr-hr/2) && yu <= (yr+hr/2)){
        printf("KAMU SUDAH SAMPAI");
    }
    else{
        int alas = xr-xu;
        int tinggi = yr-yu;
        double miring = sqrt(pow(alas,2) + pow(tinggi,2));
        printf("%.2f METER LAGI", miring);
    }
}