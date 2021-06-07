#include "my_shell.h"

//void	cd_test_without_parametrs(void)
//{
//	/* TEST 1 */
//	t_list 	*env_var = NULL;
//	char	*cmnd_words[1];
//
//	cmnd_words[0] = "echo\n";
//	cmnd_words[1] = "..\n";
//
//	cd(cmnd_words, env_var);
//}
//
//int		cd(char **cmnd_words, t_list *env_var)
//{
//	char	*final_path;
//
//	if (cmnd_words[1] == NULL)
//	{
//		final_path = get_env(env_var, "HOME");
//		if (final_path == NULL)
//			return (ERROR);//NO HOME in ENV
//	}
//	else
//		final_path = cmnd_words[1];
//	if (chdir(final_path) == -1)
//		return (ERROR);//NOT CORRECT final_path
//	return (0);
//}
