/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:58:50 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/09 09:36:24 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*function to find path inside the envp by checking each possible path
and return the correct path*/
char	*path_finder(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*command;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		command = ft_strjoin(path, cmd);
		if (access(command, F_OK) == 0)
			return (command);
		i++;
	}
	return (0);
}

void	execute(char *argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = path_finder(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		printf("Error");
	}
	if (execve(path, cmd, envp) == -1)
		printf("Error");
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char *cmd;

// 	scanf("%s", cmd);
// 	char *path = path_finder(cmd, envp);

// 	printf("%s", path);
// }
