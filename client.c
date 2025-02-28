/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:08:09 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/28 20:11:02 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		return (-1);
	return (result);
}

void	send_str(char *str, int pid)
{
	unsigned char	c;
	int				arr[8];

	int (i), (j);
	j = 0;
	while (str[j])
	{
		c = str[j];
		i = 0;
		while (i++ < 8)
		{
			arr[i] = c % 2;
			c /= 2;
		}
		while (--i > 0)
		{
			if (arr[i] == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (av[2][0] == '\0' || pid == -1 || kill(pid, 0) == -1)
			return (1);
		send_str(av[2], pid);
	}
	return (0);
}
