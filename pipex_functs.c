/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:42:45 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/10 18:52:50 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(t_pipex *vars)
{
	freedoublepointer(vars->cmd);
	freedoublepointer(vars->cmd2);
	free(vars->path);
	free(vars->path2);
	free(vars);
}

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