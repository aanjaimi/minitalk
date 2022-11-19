/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:57:03 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/21 01:15:56 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	reset(char *c, int *bits, int c_pid);
void	handler_sigusr(int signum, siginfo_t *info, void *context);
void	env_sig(char msg, int pid);
void	sendx(char *msg, int pid);
int		ft_atoi(const char *str);

#endif