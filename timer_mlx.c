/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:34:28 by stunca            #+#    #+#             */
/*   Updated: 2023/08/09 14:03:57 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

void	update_digit(t_data *data, int a, int b, int f2)
{
	data->ilk_digit = a;
	data->ikinci_digit = b;
	data->ucuncu_digit = 0;
	data->dorduncu_digit = 0;
	data->counter = 0;
	data->flag2 = f2;
}

void	print_things(t_data *data, char pomodoro_str[5][45], \
	char break_str[5][25])
{
	if (data->counter < 1500 && data->flag2 == 0)
	{
		print_pomodoro(data, pomodoro_str);
		print_digit(data);
	}
	if (data->counter < 600 && data->flag2 == 1)
	{
		print_break(data, break_str);
		print_digit(data);
	}
}

void	print_data(t_data *data, char pomodoro_str[5][45], \
	char break_str[5][25])
{
	print_things(data, pomodoro_str, break_str);
	if (data->flag2 % 2 == 1 && data->ilk_digit == 0 && \
		data->ikinci_digit == 0 && data->ucuncu_digit == 0 \
		&& data->dorduncu_digit == 0)
	{
		update_digit(data, data->study_time / 10, data->study_time % 10, 0);
		data->clock_flag = 1;
	}
	if (data->flag2 % 2 == 0 && data->ilk_digit == 0 && \
		data->ikinci_digit == 0 && data->ucuncu_digit == 0 \
		&& data->dorduncu_digit == 0)
	{
		data->pomodoro_time -= 1;
		if (data->pomodoro_time == 0)
			close_window(data);
		update_digit(data, 1, 0, 1);
		data->clock_flag = 1;
	}
	if (data->clock_flag == 1)
	{
		data->clock_flag = 0;
		pthread_create(&data->thread, NULL, &thread_func, data);
	}
}

int	lp(t_data *data)
{
	time_t current_time;
	struct tm *local_time;
	char time_str[100];
	char pomodoro_str[5][45] = {
        "000001000001011101000001000011000001000100000",     
		"011101011101001001011101011101011101010101110", 
		"000001011101010101011101011101011101000101110", 
		"011111011101011101011101011101011101001101110", 
		"011111000001011101000001000011000001010100000"};
	char break_str[5][25] = {
        "0000110001000001000001010",     
        "0111010101011111011101001", 
        "0000110001000001000001011", 
        "0111010011011111011101001", 
        "0000110101000001011101010"};
	current_time = time(NULL);
	local_time = localtime(&current_time);
	if(data->flag1)
		sleep_func();
	data->flag1 = 1;
	strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local_time);
	black_screen(data);
	mlx_string_put(data->mlx, data->win,  WIDTH - (WIDTH/100*30), 10, 0x00FFFFFF, time_str);
	print_data(data, pomodoro_str, break_str);
	return (0);
}

void init_struct(t_data *data)
{
    data->ilk_digit = data->study_time / 10;
    data->ikinci_digit = data->study_time % 10;
    data->ucuncu_digit = 0;
    data->dorduncu_digit = 0;
    data->counter = 0;
    data->counter2 = 0;
    data->flag1 = 0;
    data->flag2 = 0;
    data->clock_flag = 0;
    data->mlx = mlx_init();
}

int main()
{
    t_data data;

    printf("Welcome to pomodoro timer\n");
    printf("How many times do you want to do pomodoro? : ");
    scanf("%d",&data.pomodoro_time);
    if(data.pomodoro_time < 1)
    {
        printf("You can't enter negative number or 0\n");
        return (0);
    }
	printf("How many minutes do you want to study?(Example:25/(between 1-59)):");
	scanf("%d",&data.study_time);
	if(data.study_time < 1 || data.study_time > 59)
	{
		printf("You can't enter negative number or 0 or more than 99\n");
		return (0);
	}
    init_struct(&data);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "timer_mlx");
    mlx_loop_hook(data.mlx, lp, &data);
    mlx_hook(data.win,2,0, key_press, &data);
    mlx_hook(data.win,17,0,close_window, &data);
    mlx_loop(data.mlx);
    return (0);

}
