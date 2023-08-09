#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
# include "mlx/mlx.h"
# include <time.h>
#include <pthread.h>

#define WIDTH 500
#define HEIGHT 400

typedef struct s_data
{
    void	*mlx;
    void	*img;
    void    *win;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    int     ilk_digit;
    int     ikinci_digit;
    int     ucuncu_digit;
    int     dorduncu_digit;
    int     flag1;
    int     flag2;
    int     counter;
    int     counter2;
    int     pomodoro_time;
    int     clock_flag;
    int     study_time;
    pthread_t thread;
}	t_data;

void    black_screen(t_data *data);
int     close_window(t_data *data);
int     key_press(int keycode, t_data *data);
void    print_pomodoro(t_data *data, char pomodoro_str[5][45]);
void    print_break(t_data *data, char break_str[5][25]);
void    print_number(t_data *data,int* f,int* s,int *t,int*fr);
void    print_digit(t_data *data);
void    sleep_func();
void    *thread_func();
int     lp(t_data *data);
void    init_struct(t_data *data);

#endif