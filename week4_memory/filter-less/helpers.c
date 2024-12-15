#include "helpers.h"
#include <math.h>

// Prototype to my function that rounds and caps sepia RGB values
int cap_and_round (float number);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = cap_and_round(average);
            image[i][j].rgbtGreen = cap_and_round(average);
            image[i][j].rgbtRed = cap_and_round(average);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepia_blue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);
            float sepia_green = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
            float sepia_red = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = cap_and_round(sepia_blue);
            image[i][j].rgbtGreen = cap_and_round(sepia_green);
            image[i][j].rgbtRed = cap_and_round(sepia_red);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temporary = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temporary;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create copy of the original image
    RGBTRIPLE copy[height][width];
    
    // Copies each pixel to the new copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Go through each pixel of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Setting up some variables to calculate the average of each color
            int sumBlue = 0, sumGreen = 0, sumRed = 0;
            int count = 0;
            
            // Goes through each neighbour pixel (including the central pixel itself). di represents the rows and dj the columns.
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Verifies if the neighbour is inside the bounds of the image.
                    int ni = i + di;
                    int nj = j + dj;
                    
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumBlue += copy[ni][nj].rgbtBlue;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumRed += copy[ni][nj].rgbtRed;
                        count++;
                    }
                }
            }

            // Calculate the average for each color.
            image[i][j].rgbtBlue = round((float)sumBlue / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtRed = round((float)sumRed / count);
        }
    }
}


// Caps value of each color for sepia function to ensure it stays < 255.
int cap_and_round (float number)
{
    if (number > 255)
    {
        return 255;
    }
    else
    {
        return round(number);
    }
} 