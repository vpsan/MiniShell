#include "my_shell.h"

void 	test_sort_unset(t_main prmtrs)
{
	env_lstadd_back(&prmtrs.env_head, env_lstnew(env_split("A=0"),1));
	printf("========================================= TEST 1\n\n");
	test_printf_all_env_lst(prmtrs.env_head);
	env_lstsort_bubble(prmtrs.env_head);
	printf("========================================= TEST 2\n\n");
	test_printf_all_env_lst(prmtrs.env_head);

	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 9);
	cmnd_words[0] = ft_strdup("unset\0");
	cmnd_words[1] = ft_strdup("A\0");
	cmnd_words[2] = ft_strdup("a\0");
	cmnd_words[3] = ft_strdup("a=1\0");
	cmnd_words[4] = ft_strdup("1a\0");
	cmnd_words[5] = ft_strdup("-a\0");
	cmnd_words[6] = ft_strdup("=\0");//doesnt work
	cmnd_words[7] = ft_strdup("B\0");
	cmnd_words[8] = NULL;

	printf("========================================= TEST 3\n\n");
	builtin_unset(cmnd_words, prmtrs.env_head);
	test_printf_all_env_lst(prmtrs.env_head);
	return ;
}