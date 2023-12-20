#include <stdio.h>

void nextposition(int t, int n, int k)
{
    int temp[n+1];

    for (int i = 0; i < n; i++) temp[i] = i+1;

    int remainder = n, next = 0;
    int position = -2, counter = 0;

    while (k != counter) {
        position += 2;
        if (position > 0 && position <= remainder) {
            temp[next] = temp[position - 1];
            next++;
        }
        if (position >= remainder) {
            position -= remainder;
            remainder = next;
            next = position;
            if (position >= remainder) {
                position = remainder - 1;
            }
        }
        counter++;
    }
    printf("%d\n", temp[position]);
}

int main()
{
    int t, n, k;

    scanf("%i", &t);

    while (t--) {
        scanf("%i %i", &n, &k);
        nextposition(t, n, k);
    }
    return 0;
}