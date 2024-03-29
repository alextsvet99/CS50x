// Creates a double-pyramid of # (bricks)

#include <cs50.h>
#include <stdio.h>

void draw_double_pyramid(int height);
void draw_line(char c, int length);

int main(void)
{
    // Prompt user for pyramid height
    int height = 0;
    do
    {
        height = get_int("Enter pyramid height (positive integer, no greater than 8): ");
    }
    while ((height < 1) || (height > 8));

    // Draw the pyramid
    draw_double_pyramid(height);
}

// Draws a double-pyramid of height height
void draw_double_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_line(' ', height - i - 1);
        draw_line('#', i + 1);
        draw_line(' ', 2);
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
