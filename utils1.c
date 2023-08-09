/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:14:23 by stunca            #+#    #+#             */
/*   Updated: 2023/08/09 13:32:04 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

void	black_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 12)
		close_window(data);
	return (0);
}

void	sleep_func(void)
{
	int	i;

	i = 0;
	while (i < 10000)
	{
		usleep(100);
		i++;
	}
}

void	*thread_func(void)
{
	system("afplay music/duck.mp3 &");
	return (NULL);
}
