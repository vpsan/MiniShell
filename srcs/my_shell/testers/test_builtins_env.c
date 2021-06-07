
#include "my_shell.h"
#include <printf.h>

void 	test_builtins_env(t_main prmtrs)
{
	// printf list without adding elements in env:
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n");
	printf("-------------- ENV ORIGINAL -----------------\n\n");
	env(&prmtrs);

	// printf list with adding elements in env:
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("A=0", '='),1));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("a=1", '='),1));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("b=1", '='),1));
	ft_lstadd_back(&prmtrs.env_head, ft_lstnew(ft_split("c=2", '='),1));
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n");
	printf("-------------- ENV WITH ADDING ---------------\n\n");
	env(&prmtrs);
	return ;
}