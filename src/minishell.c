#include "minishell.h"

void init_env(char **env, t_env **env_list)
{
    t_env   *new_node;
    int     i;
    char    *equal_pos;

    i = -1;
    while (env[++i])
    {
        new_node = malloc(sizeof(t_env));
        if (!new_node)
            return;
        equal_pos = ft_strchr(env[i], '=');
        if (equal_pos)
        {
            new_node->key = ft_substr(env[i], 0, equal_pos - env[i]);
            new_node->value = ft_strdup(equal_pos + 1);
        }
        else
        {
            new_node->key = ft_strdup(env[i]);
            new_node->value = NULL;
        }
        new_node->exported = 1;
        new_node->next = NULL;
        append_env(env_list, new_node);
    }
}


int main(int argc, char **argv, char **env)
{
	char	*input;
	char    **args;
	(void)argc;
	(void)argv;
	t_env    *env_list;
	env_list = NULL;
	init_env(env, &env_list);
	// input = ft_strdup(argv[1]);
	while (1)
	{
		input = readline("minishell> ");
		args = ft_split(input, ' ');
		built(args, input, &env_list);
		// pars(input, env);
		//execute
		ft_free_tab(args);
		free(input);
	}
	return (0);
}