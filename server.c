/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:32:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/20 13:34:10 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int power(int n)
{
	int i;

	i = 1;
	while (n > 0)
	{
		i = i * 2;
		n--;
	}
	return (i);
}

void get_bit(int sig)
{
	static int i = 8;
	static unsigned char c;

	i--;
	if (sig == SIGUSR1)
		c = c + 0;
	else
		c = c + power(i);
	if (i == 0)
	{
		write (1, &c, 1);
		c = 0;
		i = 8;
	}
}

int main()
{
	int pid = getpid();
	printf("%d\n", pid);
	signal (SIGUSR1, get_bit);
	signal (SIGUSR2, get_bit);
	while (1)
		pause();
}
