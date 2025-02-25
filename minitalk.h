/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:50:06 by hmouis            #+#    #+#             */
/*   Updated: 2025/02/19 09:51:21 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void send_bit(char *str, int pid);
int ft_atoi(char *str);
void minitalk(pid_t pid, char *str);

#endif
