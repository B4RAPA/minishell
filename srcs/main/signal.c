/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macrespo <macrespo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:04:10 by macrespo          #+#    #+#             */
/*   Updated: 2020/07/31 16:43:51 by macrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigInt(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_printf("\b\b  ");
		ft_printf("\n");
		ft_printf("\033[0;36mminishell > \033[0m");
		g_sig.exit_status = 1;
	}
	else
	{
		ft_printf("\n");
		g_sig.exit_status = 130;
	}
	g_sig.pid = 0;
	g_sig.sigint = 1;
	signal(SIGINT, &sigInt);
}

void    sigQuit(int code)
{
    (void)code;
    g_sig.exit_status = 131;
    g_sig.sigquit = 1;
    signal(SIGQUIT, &sigQuit);
}