#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>


typedef struct s_env {
	char	*key;
	char	*value;
	int		exported;
	struct s_env *next;
} t_env;


// char	token_maker(char *input);
void	ft_free_tab(char **tab);
char	*pars(char *input, char **env);
int		ft_atoll(const char *str);
void	exit_error(char *arg, char *err_msg, char *type);
void	built(char **args, char *input, t_env **env);
int		array_len(char **args);
void	builtin_env(t_env *env_list);
void	builtin_export(char **args, t_env **env_list);
t_env	*find_env_node(t_env *env, const char *key);
void	append_env(t_env **env_list, t_env *new);
int		env_size(t_env *env);
t_env	**env_to_array(t_env *env);
void	sort_env_array(t_env **env);
int		ft_strcmp(const char *s1, const char *s2);
void	builtin_unset(const char *key, t_env **env_list);


#endif