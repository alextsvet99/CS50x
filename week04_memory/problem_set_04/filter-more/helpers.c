#include <math.h>

#include "helpers.h"

// My prototypes
RGBTRIPLE local_avg(int i, int j, int height, int width, RGBTRIPLE data[height][width]);
RGBTRIPLE detect_edge(int i, int j, int height, int width, RGBTRIPLE data[height][width]);

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
                (float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);

            // Modify pixel colours
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            // Calculate new values
            image[i][j] = detect_edge(i, j, height, width, copy);
        }
    }
    return;
}

// Returns a new pixel value based on the Sobel operator
RGBTRIPLE detect_edge(int i, int j, int height, int width, RGBTRIPLE data[height][width])
{
    // Determine boundaries for integration
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

    // The Sobel kernels
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}};

    // Compute sums
    float red_x = 0, green_x = 0, blue_x = 0;
    float red_y = 0, green_y = 0, blue_y = 0;

    // Sizes of arrays data and Gx, Gy are different,
    // so two sets of loop variables are needed. Therefore:
    // m, n is used for locating pixels in an image (data);
    // p, q is used for locating corresponding Gx and Gy values.
    for (int m = t, p = 1 - (i - t); m < b; m++, p++)
    {
        for (int n = l, q = 1 - (j - l); n < r; n++, q++)
        {
            red_x += data[m][n].rgbtRed * Gx[p][q];
            green_x += data[m][n].rgbtGreen * Gx[p][q];
            blue_x += data[m][n].rgbtBlue * Gx[p][q];

            red_y += data[m][n].rgbtRed * Gy[p][q];
            green_y += data[m][n].rgbtGreen * Gy[p][q];
            blue_y += data[m][n].rgbtBlue * Gy[p][q];
        }
    }

    int red = round(sqrt(pow(red_x, 2) + pow(red_y, 2)));
    int green = round(sqrt(pow(green_x, 2) + pow(green_y, 2)));
    int blue = round(sqrt(pow(blue_x, 2) + pow(blue_y, 2)));

    RGBTRIPLE avg;
    avg.rgbtRed = (red > 255) ? 255 : red;
    avg.rgbtGreen = (green > 255) ? 255 : green;
    avg.rgbtBlue = (blue > 255) ? 255 : blue;

    return avg;
}
