// Creates a right-aligned pyramid of # (bricks)

#include <cs50.h>
#include <stdio.h>

void draw_left_pyramid(int h);
void draw_line(int l);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Enter pyramid height (positive integer): ");
    }
    while (height <= 0);

    printf("Received pyramid height: %i\n", height);

    printf("Drawing pyramid ...\n");
    draw_left_pyramid(height);
}

// Draws a left-aligned pyramid of height h
void draw_left_pyramid(int h)
{
    for (int i = 0; i < h; i++)
    {
        draw_line(i+1);
    }
}

// Draws a line of # of length l
void draw_line(int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("#");
    }
    printf("\n");
}
