#include "helpers.h"
#include <math.h>
int Gx[]={-1,0,1,-2,0,2,-1,0,1};
int Gy[]={-1,-2,-1,0,0,0,1,2,1};
BYTE limit(int sum)
{
    return (sum>255)? 255: (sum<0? 0:sum);
}
BYTE patrat(int e1,int e2)
{
    return limit(round(sqrt((e1*e1)+(e2*e2))));
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i=0;i<height;++i){
        for(int j=0;j<width;++j)
        {
            copy[i][j]=image[i][j];
        }
    }
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<width;++j)
        {
            int k=0;
            int Gxr=0,Gyr=0,Gxb=0,Gyb=0,Gxg=0,Gyg=0;
            for(int di=-1;di<=1;++di)
            {
                for(int dj=-1;dj<=1;++dj)
                {
                   int ni=di+i;
                   int nj=dj+j;
                   if(ni>=0 && ni<height && nj>=0 && nj<width)
                   {
                    Gxr+=Gx[k]*copy[ni][nj].rgbtRed;
                    Gyr+=Gy[k]*copy[ni][nj].rgbtRed;
                    Gxb+=Gx[k]*copy[ni][nj].rgbtBlue;
                    Gyb+=Gy[k]*copy[ni][nj].rgbtBlue;
                    Gxg+=Gx[k]*copy[ni][nj].rgbtGreen;
                    Gyg+=Gy[k]*copy[ni][nj].rgbtGreen;
                   }
                   k++;

                }
            }
            image[i][j].rgbtRed=patrat(Gxr,Gyr);
            image[i][j].rgbtGreen=patrat(Gxg,Gyg);
            image[i][j].rgbtBlue=patrat(Gxb,Gyb);
        }
    }
    return;
}
