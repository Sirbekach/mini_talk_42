/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:36:26 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/25 14:59:36 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

int		g_i = 0;

void	handle_signal(int sig, siginfo_t *info, void *param)
{
	static int	pro_id;
	static long	g_res;

	(void)param;
	if (pro_id != info->si_pid)
	{
		g_i = 0;
		g_res = 0;
	}
	if (sig == SIGUSR1)
		g_res = 2 * g_res + 0;
	else if (sig == SIGUSR2)
		g_res = 2 * g_res + 1;
	g_i++;
	if (g_i == 8)
	{
		ft_putchar_fd(g_res, 1);
		g_res = 0;
		g_i = 0;
	}
	pro_id = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
