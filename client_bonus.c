/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:57:20 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/03/03 01:42:16 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char	*str)
{
	int	i ;
	int	signe;
	int	n ;

	n = 0 ;
	i = 0 ;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' )
		i++;
	else if (str[i] == '-' )
	{
		signe = -1 ;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * signe);
}

void	env_sig(char msg, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (msg & (128 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(900);
	}
}

void	sendx(char *msg, int pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		env_sig(msg[i], pid);
	env_sig(0, pid);
}

void	handler(int signum)
{
	(void)signum;
	write(1, "Done\n", 6);
}

int	main(int ac, char *av[])
{
	int	pid;

	signal(SIGUSR1, handler);
	if (ac != 3)
	{
		write(1, "client: invalid\n", 17);
		write(1, "Correct the format [./%s PID MSG]\n", 35);
		exit(0);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
	{
		write(1, "Invalid PID\n", 14);
		exit(0);
	}
	sendx(av[2], pid);
	return (0);
}
