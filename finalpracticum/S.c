#include <stdio.h>
#include <string.h>

int main() { int n; scanf("%d", &n);

int hp[1005];
float att[1005];
char gender[1005][3];
char nama[1005][105];

for (int i = 0; i < n; i++){
    scanf("%d %f %c %[^\n]", &hp[i], &att[i], gender[i], nama[i]);
}

int palindrom = 1;
for (int i = 0; i < n / 2; i++)
{
    int j = n - i - 1;

    int count = 0;
    if (hp[i] == hp[j])count++;
    if (att[i] == att[j])count++;
    if (gender[i][0] == gender[j][0])count++;
    if (strcmp(nama[i], nama[j]) == 0)count++;
    if (count >= 2){
        continue;
    }
    else{
        palindrom = 0;
        break;
    }
}

if (palindrom){
    printf("Siap perang, Dewi Shita!\n");
}
else{
    printf("Sebentar Dewi Shita, belum palindrom nih.\n");

    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;

        int count = 0;
        if (hp[i] == hp[j])
            count++;
        if (att[i] == att[j])
            count++;
        if (gender[i][0] == gender[j][0])
            count++;
        if (strcmp(nama[i], nama[j]) == 0)
            count++;

        if (count < 2)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

return 0;
}