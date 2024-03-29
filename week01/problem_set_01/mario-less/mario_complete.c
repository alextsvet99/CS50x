// Creates a pyramid of # (bricks)

#include <cs50.h>
#include <stdio.h>

void draw_left_pyramid(int height);
void draw_right_pyramid(int height);
void draw_double_pyramid(int height);
void draw_line(char c, int length);

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Enter pyramid height (positive integer): ");
    }
    while (height < 1);

    printf("Received pyramid height: %i\n", height);

    printf("Drawing left pyramid ...\n");
    draw_left_pyramid(height);

    printf("Drawing right pyramid ...\n");
    draw_right_pyramid(height);

    printf("Drawing double pyramid ...\n");
    draw_double_pyramid(height);
}

// Draws a left-aligned pyramid of height height
void draw_left_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_line('#', i+1);
        printf("\n");
    }
}

// Draws a right-aligned pyramid of height height
void draw_right_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_line(' ', height-i-1);
        draw_line('#', i+1);
        printf("\n");
    }
}

// Draws a double-pyramid of height height
void draw_double_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_line(' ', height-i-1);
        draw_line('#', i+1);
        draw_line(' ', 1);
        draw_line('#', i+1);
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
