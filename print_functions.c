/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:24:49 by stunca            #+#    #+#             */
/*   Updated: 2023/07/30 22:36:57 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

void	print_pomodoro(t_data *data, char pomodoro_str[5][45])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 45 && j * 8 < WIDTH)
		{
			k = -1;
			while (++k < 64)
			{
				if (pomodoro_str[i][j] != '1')
				{
					mlx_pixel_put (data->mlx, data->win, \
					WIDTH / 8 + (j * 8) + k / 8, \
					HEIGHT / 5 + (i * 8) + k % 8, \
					0x00FFFFFF);
				}
			}
			j++;
		}
		i++;
	}
}

void	print_break(t_data *data, char break_str[5][25])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 25 && j * 8 < WIDTH)
		{
			k = -1;
			while (++k < 64)
			{
				if (break_str[i][j] != '1')
				{
					mlx_pixel_put(data->mlx, data->win, \
					WIDTH / 3 + (j * 8) + k / 8, \
					HEIGHT / 5 + (i * 8) + k % 8, \
					0x00FFFFFF);
				}
			}
			j++;
		}
		i++;
	}
}

void	print_digit(t_data *data)
{
	print_number(data, &data->ilk_digit, \
		&data->ikinci_digit, &data->ucuncu_digit, &data->dorduncu_digit);
	data->dorduncu_digit -= 1;
	if (data->dorduncu_digit == -1)
	{
		data->dorduncu_digit = 9;
		data->ucuncu_digit -= 1;
		if (data->ucuncu_digit == -1)
		{
			data->ucuncu_digit = 5;
			data->ikinci_digit -= 1;
			if (data->ikinci_digit == -1)
			{
				data->ikinci_digit = 9;
				data->ilk_digit -= 1;
				if (data->ilk_digit == -1)
					data->flag2++;
			}
		}
	}
}
