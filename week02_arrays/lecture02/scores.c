#include <cs50.h>
#include <stdio.h>

const int N = 3;

int main(void)
{
    // const int N = 3;
    // int scores[N] = {72, 73, 33};
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    printf("Avg: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
