#include <stdio.h>
#include <math.h>

#define ull unsigned long long

int main()
{
    ull a, b;

    scanf("%llu %llu", &a, &b);

    ull max = a;
    ull min = b;

    if (a < b)
    {
        max = b;
        min = a;
    }
    if (max % min == 0)
    {
        printf("Rizz");
        if((a&b) ==0){
            printf("Wuzz");
        }
        else if((a&b)==b||(a&b)==a){
            printf("Buzz");
        }
    }
    else
    {
        printf("Not Rizz");
        if((a&b)==0){
            printf(", but Wuzz!");
        }
        else if((a&b)==b||(a&b)==a){
            printf(", but Buzz!");
        }
    }
    return 0;
}