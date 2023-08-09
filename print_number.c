#include "timer.h"

void print_number(t_data *data,int* f,int* s,int *t,int*fr)
{
    int i;
    int j;
    int k;
    int w_center;
    int h_center;
    int s1;

    data->counter++;
    i = 0;
    j = 0;
    k = 0;
    w_center = 0;
    s1 = 0;
    h_center = HEIGHT/2;
    char all[5][55] = {
        "0000011011000000000001110000000000000000000000000011111","0111011011111101111001110011110111111110011100111011101","0111011011000000000000000000000000011110000000000011111","0111011011011111111011110111100111011110011101111011101","0000011011000000000011110000000000011110000000000011111"};
    if(*f >= 0 && *f<= 5)
    {
        w_center = WIDTH/6;
        i = 0;
        while(i < 5)
        {
            j = 5* (*f);
            s1 = 0;
            while(s1 < 5)
            {
                k = -1;
                while(++k<64)
                {
                    if(all[i][j] != '1')
                    {
                        mlx_pixel_put(data->mlx, data->win, w_center + (s1*8) + k/8, h_center + (i*8)+k%8, 0x00FFFFFF);
                    }
                }
                s1++;
                j++;
            }
            i++;
        } 
    }
    if(*s >= 0 && *s<= 9)
    {
        w_center = WIDTH/3;
        i = 0;
        while(i < 5)
        {
            j = 5* (*s);
            s1 = 0;
            while(s1 < 5)
            {
                k = -1;
                while(++k<64)
                {
                    if(all[i][j] != '1')
                    {
                        mlx_pixel_put(data->mlx, data->win, w_center + (s1*8) + k/8, h_center + (i*8)+k%8, 0x00FFFFFF);
                    }
                }
                s1++;
                j++;
            }
            i++;
        }
    }
    w_center = WIDTH/2;
    i = 0;
    while(i < 5)
    {
        s1 = 0;
        j = 51;
        while(j < 55)
        {
            k = -1;
            while(++k<64)
            {
                if(all[i][j] != '1')
                {
                    mlx_pixel_put(data->mlx, data->win, w_center + (s1*8) + k/8, h_center + (i*8)+k%8, 0x00FFFFFF);
                }
            }
            s1++;
            j++;
        }
        i++;
    }
    if(*t >= 0 && *t <= 6)
    {
        w_center = WIDTH/2 + (WIDTH/6);
        i = 0;
        while(i < 5)
        {
            j = 5* (*t);
            s1 = 0;
            while(s1 < 5)
            {
                k = -1;
                while(++k<64)
                {
                    if(all[i][j] != '1')
                    {
                        mlx_pixel_put(data->mlx, data->win, w_center + (s1*8) + k/8, h_center + (i*8)+k%8, 0x00FFFFFF);
                    }
                }
                s1++;
                j++;
            }
            i++;
        }
    }
    if(*fr>=0 && *fr <= 9)
    {
        w_center = WIDTH/2 + (WIDTH/3);
        i = 0;
        while(i < 5)
        {
            j = 5* (*fr);
            s1 = 0;
            while(s1 < 5)
            {
                k = -1;
                while(++k<64)
                {
                    if(all[i][j] != '1')
                    {
                        mlx_pixel_put(data->mlx, data->win, w_center + (s1*8) + k/8, h_center + (i*8)+k%8, 0x00FFFFFF);
                    }
                }
                s1++;
                j++;
            }
            i++;
        }
    } 
   return ;
}