// Creates a right-aligned pyramid of # (bricks)

#include <cs50.h>
#include <stdio.h>

void draw_right_pyramid(int height);
void draw_line(char c, int length);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Enter pyramid height (positive integer): ");
    }
    while (height < 1);

    draw_right_pyramid(height);
}

// Draws a right-aligned pyramid of height height
void draw_right_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_line(' ', height - i - 1);
        draw_line('#', i + 1);
        printf("\n");
    }
}

// Draws a line of characters c of length length
void draw_line(char c, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
}
