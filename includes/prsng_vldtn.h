/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:56:31 by bhatches          #+#    #+#             */
/*   Updated: 2021/05/29 14:28:53 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRSNG_VLDTN_H
# define PRSNG_VLDTN_H

# include "libft.h"
# include <stdio.h>

typedef	struct	s_prsng
{
    char    *str;
}				t_prsng;

typedef struct  s_shell
{
    t_prsng	prsng;
}				t_shell;

void	prsng_vldtn(t_shell *prmtrs);
void	ft_find_n(t_shell *prmtrs, char *buf);

/*
**      other functions goes here
*/

#endif
