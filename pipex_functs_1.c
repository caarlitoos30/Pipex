/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:42:45 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/16 21:07:17 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	vardefs(t_pipex *vars, char **argv)
{
	vars->cmd = ft_split(argv[2], ' ');
	vars->cmd2 = ft_split(argv[3], ' ');
	vars->output = argv[4];
	vars->path = pathseek(vars->cmd, vars);
	if (!vars->path)
		return (ft_printf("Command not found: %s\n", vars->cmd[0]), -1);
	vars->path[ft_strlen(vars->path) - 1] = '\0';
	vars->fdin = open(argv[1], O_RDONLY);
	if (vars->fdin == -1)
		return (ft_printf("No such file or directory: %s\n", argv[1]), -1);
	vars->path2 = pathseek(vars->cmd2, vars);
	if (!vars->path2)
		return (ft_printf("Command not found: %s\n", vars->cmd2[0]), -1);
	vars->path2[ft_strlen(vars->path2) - 1] = '\0';
	return (0);
}

char	*pathseek(char **args, t_pipex *var)
{
	int			fd[2];
	int			pid;
	char		*temporal;
	char const	*argv[] = {"which", args[0], NULL};

	if (pipe(fd) == -1)
		return (NULL);
	pid = fork();
	if (pid == -1)
		return (NULL);
	if (pid == 0)
	{
		pipe_op(fd);
		if (execve("/usr/bin/which", argv, var->envp) == -1)
			return (NULL);
	}
	else
	{
		close(fd[WRITE_END]);
		waitpid(pid, NULL, 0);
		temporal = get_next_line(fd[READ_END]);
		return (close(fd[READ_END]), temporal);
	}
	return (NULL);
}

void	pipe_op(int fd[2])
{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
}

void	pipe_in(int fd[2])
{
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
}

void	free_all(t_pipex *vars)
{
	freedoublepointer(vars->cmd);
	freedoublepointer(vars->cmd2);
	free(vars->path);
	free(vars->path2);
	free(vars);
}
