/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:09:35 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/16 21:28:11 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkeo(char **argv, t_pipex *var)
{
	if (access(argv[1], R_OK) == -1)
		return (-1);
	if (!var->path || access(var->path, X_OK) != 0)
		return (-1);
	if (!var->path2 || access(var->path2, X_OK) != 0)
		return (-1);
	return (0);
}

int	cmdcall(t_pipex *var, char **cmd)
{
	if (!cmd)
		return (free_all(var), -1);
	if (pipe(var->fd) == -1)
		return (-1);
	var->pid = fork();
	if (var->pid == 0)
	{
		dup2(var->fdin, var->fd[READ_END]);
		close(var->fdin);
		dup2(var->fd[WRITE_END], STDOUT_FILENO);
		pipe_in(var->fd);
		if (execve(var->path, var->cmd, var->envp) == -1)
			return (-1);
	}
	else
	{
		close(var->fdin);
		return (cmdcall2(var, var->cmd2));
	}
	return (0);
}

int	cmdcall2(t_pipex *var, char **cmd)
{
	if (!cmd)
		return (-1);
	if (pipe(var->fd2) == -1)
		return (-1);
	var->pid = fork();
	if (var->pid == 0)
	{
		pipe_in(var->fd);
		pipe_op(var->fd2);
		if (execve(var->path2, cmd, var->envp) == -1)
			return (-1);
	}
	else
	{
		close(var->fd[WRITE_END]);
		close(var->fd[READ_END]);
		close(var->fd2[WRITE_END]);
		close(var->fdout);
		return (fdtofile(var, var->output), 0);
	}
	return (0);
}

void	fdtofile(t_pipex *var, char *filename)
{
	ssize_t p;
	
	p = 0;
	var->fdout = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	var->buf = get_next_line(var->fd2[READ_END]);
	while (var->buf && p != -1)
	{
		p = write(var->fdout, var->buf, ft_strlen(var->buf));
		free(var->buf);
		var->buf = get_next_line(var->fd2[READ_END]);
	}
	close(var->fdout);
	close(var->fd2[READ_END]);
}