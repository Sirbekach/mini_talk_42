/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:16 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/25 15:14:14 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_signals(int pid, char *argv)
{
	int		i;
	int		j;
	int		c;

	j = 0;
	while (argv[j])
	{
		i = 7;
		while (i >= 0)
		{
			c = argv[j];
			if (((c >> i) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((c >> i) & 1) == 1)
				kill(pid, SIGUSR2);
			i--;
			usleep(300);
		}
		j++;
	}
}

int	ft_get_pid(char *word)
{
	int		i;

	i = 0;
	while (word[i])
	{
		if (!ft_isdigit(word[i]))
			return (0);
		i++;
	}
	return (ft_atoi(word));
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("ERROR!! NOT ENOUGH ARGS\n", 2);
		return (1);
	}
	(void)argc;
	pid = ft_get_pid(argv[1]);
	if (pid <= 1)
	{
		ft_putstr_fd("Invalid pid\n", 2);
		return (1);
	}
	send_signals(pid, argv[2]);
	return (0);
}
