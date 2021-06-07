/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:03:58 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 20:04:16 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

 void    unset_delete_lst_element(char *s, t_list *env_head)
 {
     t_list *tmp;
     t_list	*previous;

     tmp = env_head;
     while (tmp != NULL)
     {
         if (ft_strcmp(s, tmp->env_arr[0]) == 0)
		 {
			 previous->next = tmp->next;
			 ft_lstdelone(tmp, ft_free_str_arr);
			 break ;
		 }
		 previous = tmp;
		 tmp = tmp->next;
     }
     return ;
 }

 int     check_word(char *s)
 {
     int i;

     if (ft_isdigit(s[0]) == TRUE)
         return (ERROR);
     i = 0;
     while (s[i] != '\0')
     {
         if (s[i] == '-' ||//если s_i равна '-' или если s_i не буква и не цфр
				 (ft_isalpha(s[i]) == FALSE
				 && ft_isdigit(s[i]) == FALSE))
             return (ERROR);
         i++;
     }
     return (0);
 }

 int     unset(char *cmnd_str, char **cmnd_words, t_list *env_head)
 {
     t_list *tmp;
     int     i;

     tmp = env_head;
     i = 1;
     while (cmnd_words[i] != NULL)
     {
         if (check_word(cmnd_words[i]) == ERROR)
         {
         	ft_putstr_fd("my_shell: unset: '", 2);
 			ft_putstr_fd(cmnd_words[i], 2);
 			ft_putstr_fd("': not a valid identifier\n", 2);
             // ТУТ У ПАРНЕЙ ОБЫЧНО EXIT_SATUS прописывается
         }
         else
             unset_delete_lst_element(cmnd_words[i], env_head);
         i++;
     }
     return (0);
 }
