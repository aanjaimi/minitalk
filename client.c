/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:10:51 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/03/02 16:21:01 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	msg_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}

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
	else if (str[i] == '-')
	{
		signe = -1 ;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		msg_error("Correct the format of the PID\n");
	return (n * signe);
}

void	env_sig(char *msg, int pid)
{
	int	i;
	int	shift;

	i = 0;
	while (msg[i])
	{
		shift = -1;
		while (++shift < 8)
		{
			if (msg[i] & (128 >> shift))
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
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
	{
		write(1, "client: invalid\n", 17);
		msg_error("Correct the format [./%s PID MSG]\n");
	}
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
		msg_error("Invalid PID\n");
	env_sig(av[2], pid);
	return (0);
}
