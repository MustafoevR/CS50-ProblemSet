#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int newRed, newGreen, newBlue;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            // Algorithm
            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);
            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Transformation
    for(int i = 0; i < height; i++)
    {
        int cur_pos = 0;
        for(int j = width - 1; j >= 0; j--)
        {
            temp[i][cur_pos] = image[i][j];
            cur_pos++;
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int count = 0;
            float maxR = 0, maxG = 0, maxB = 0;
            int xCoor[] = {row - 1, row, row + 1};
            int yCoor[] = {col - 1, col, col + 1};

            for(int n = 0; n < 3; n++)
            {
                for(int k = 0; k < 3; k++)
                {
                    int cur_row = xCoor[n];
                    int cur_col = yCoor[k];

                    if(cur_row >= 0 && cur_row < height && cur_col >= 0 && cur_col < width)
                    {
                            RGBTRIPLE pixel = image[cur_row][cur_col];
                            maxR += pixel.rgbtRed;
                            maxG += pixel.rgbtGreen;
                            maxB += pixel.rgbtBlue;
                            count++;
                    }

                }
            }
            temp[row][col].rgbtRed = round(maxR / count);
            temp[row][col].rgbtGreen = round(maxG / count);
            temp[row][col].rgbtBlue = round(maxB / count);
        }
     }



    // Copying modified pixels into actual 2D array
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
