/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:05:48 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/11 17:13:48 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*vars;

	vars = ft_calloc(1, sizeof(t_pipex));
	vars->envp = envp;
	if (argc != 5)
		return (free(vars), 2);
	if (vardefs(vars, argv) != 0)
		return (free_all(vars), 2);
	if (checkeo(argv, vars) != 0)
		return (free_all(vars), 2);
	if (cmdcall(vars, vars->cmd) != 0)
		return (free_all(vars), 2);
	wait(NULL);
	wait(NULL);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	free_all(vars);
	return (0);
}
