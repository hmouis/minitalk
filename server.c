/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:32:00 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/28 20:11:29 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		i = i * 2;
		n--;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	get_bit(int sig, siginfo_t *info, void *c_info)
{
	static int				i = 8;
	static unsigned char	c;
	static int				c_pid;

	(void)c_info;
	if (c_pid != info->si_pid)
	{
		i = 8;
		c = 0;
		c_pid = info->si_pid;
	}
	i--;
	if (sig == SIGUSR1)
		c = c + 0;
	else
		c = c + power(i);
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 8;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_sigaction = get_bit;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_putnbr(pid);
	while (1)
		pause();
}
