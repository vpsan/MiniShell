/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_shell_terminal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:55:37 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	setup_terminal(void)
{
	struct termios	term;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_handler);
	if (tcgetattr(0, &term) != 0)
		return (1);
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &term) != 0)
		return (1);
	return (0);
}
