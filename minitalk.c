/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:08:09 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/20 13:19:55 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;

	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void send_bit(char *str, int pid)
{
	unsigned char c;
	int i;
	int arr[8];
	int j;
	j = 0;
	while (str[j])
	{
		c = str[j];
		i = 0;
		while (i < 8)
		{
			arr[i] = c % 2;
			c /= 2;
			i++;
		}
		while (i > 0)
		{
			i--;
			if (arr[i] == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
		}
		j++;
	}
}

int main(int ac, char **av)
{
	pid_t pid;

	if (ac == 3) 
	{
		pid = ft_atoi(av[1]);
		send_bit(av[2], pid);
	}

	return (0);
}
