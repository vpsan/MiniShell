
#include "my_shell.h"
#include <printf.h>

void 	test_builtins_unset(t_main prmtrs)
{
	// adding A=0 to List_env and call env():
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("A=0", '='),1));
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	printf("-------------- ENV BEFORE UNSET -----------------\n");
	env(&prmtrs);

	// deleting A=0 from List_env and call env():
	char **cmnd_words;
	cmnd_words = (char **)malloc(sizeof(char *) * 3);
	cmnd_words[0] = ft_strdup("unset\0");
	cmnd_words[1] = ft_strdup("A\0");
//	cmnd_words[1] = NULL;
//	cmnd_words[1] = ft_strdup("a\0");
//	cmnd_words[1] = ft_strdup("a=1\0");
//	cmnd_words[1] = ft_strdup("1a\0");
//	cmnd_words[1] = ft_strdup("-a\0");
	cmnd_words[2] = ft_strdup("=\0");
	cmnd_words[3] = NULL;

	unset("unset A\0", cmnd_words, prmtrs.env_head);
	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	printf("-------------- ENV AFTER UNSET -----------------\n");
	env(&prmtrs);

	ft_free_str_arr(&cmnd_words);
	return ;
}