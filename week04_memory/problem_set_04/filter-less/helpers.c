#include <math.h>

#include "helpers.h"

// Prototypes
int modify_colour(RGBTRIPLE pixel, float r_coef, float g_coef, float b_coef);
RGBTRIPLE local_avg(int i, int j, int height, int width, RGBTRIPLE data[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find the average intensity of colour
            avg = round(
                (float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Modify pixel colours
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Modify pixel colours
            red = modify_colour(image[i][j], 0.393, 0.769, 0.189);
            green = modify_colour(image[i][j], 0.349, 0.686, 0.168);
            blue = modify_colour(image[i][j], 0.272, 0.534, 0.131);

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Returns new colour for the given pixel
int modify_colour(RGBTRIPLE pixel, float r_coef, float g_coef, float b_coef)
{
    // Calculate new colour
    float new_colour = r_coef * pixel.rgbtRed + g_coef * pixel.rgbtGreen + b_coef * pixel.rgbtBlue;

    // Check if it exceeds 255
    if (new_colour > 255)
    {
        new_colour = 255;
    }

    return round(new_colour);
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    // Loop over pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, w = width / 2; j < w; j++)
        {
            // Swap pixels
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average
            image[i][j] = local_avg(i, j, height, width, copy);
        }
    }
    return;
}

// Returns the local average
RGBTRIPLE local_avg(int i, int j, int height, int width, RGBTRIPLE data[height][width])
{
    int t, b, l, r;

    // Sum values:
    // from top t ...
    if ((t = i - 1) < 0)
    {
        t++;
    }

    // ... to bottom b
    if ((b = i + 2) > height)
    {
        b--;
    }

    // from left l ...
    if ((l = j - 1) < 0)
    {
        l++;
    }

    // ... to right r
    if ((r = j + 2) > width)
    {
        r--;
    }

    float avg_red = 0, avg_green = 0, avg_blue = 0, n_points = 0;

    for (int m = t; m < b; m++)
    {
        for (int n = l; n < r; n++)
        {
            avg_red += data[m][n].rgbtRed;
            avg_green += data[m][n].rgbtGreen;
            avg_blue += data[m][n].rgbtBlue;
            n_points++;
        }
    }

    RGBTRIPLE avg;
    avg.rgbtRed = round(avg_red / n_points);
    avg.rgbtGreen = round(avg_green / n_points);
    avg.rgbtBlue = round(avg_blue / n_points);

    return avg;
}
