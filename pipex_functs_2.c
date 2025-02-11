/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:09:35 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/11 17:27:49 by calguaci         ###   ########.fr       */
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
		pipex_in(var->fd);
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