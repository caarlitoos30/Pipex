/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:05:48 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/10 18:52:42 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char	*pathseek(char **cmd, char **envp)
{
	int			fd[2];
	int			pid;
	char		*temporal;
	char const	*argv[] = {"which, args[0], NULL"};

	if (pipe(fd) == -1)
		return (NULL);
	pid = fork();
	if (pid == -1)
		return (NULL);
	if (pid == 0)
	{
		pipe_op(fd);
		if (execve("/usr/bin/which", argv, envp) == -1)
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

int	checks(char **argv, t_pipex *var)
{
	if (access(argv[1], R_OK) == -1)
		return (-1);
	if (!var->path || access(var->path, X_OK) != 0)
		return (-1);
	if (!var->path || access(var->path2, X_OK) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*var;

	var = ft_calloc(1, sizeof(t_pipex));
	var->envp = envp;
	if (argc != 5)
		return (free(var), 2);
	if (argc == 5)
	{
		pipe(var->fd);
		if (var->pid == 0)
		{
			dup2(var->fd[READ_END], STDIN_FILENO);
			close(var->fd[READ_END]);
			dup2(var->fd[WRITE_END], STDOUT_FILENO);
			close(var->fd[WRITE_END]);
		}
	}
}
