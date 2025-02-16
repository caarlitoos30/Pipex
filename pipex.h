/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:06:05 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/16 21:27:17 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft-full/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

# define READ_END 0
# define WRITE_END 1

typedef struct pipex
{
	int		pid;
	int		fd[2];
	int		fd2[2];
	int		fdout;
	int		fdin;
	char	*path;
	char	*path2;
	char	*output;
	char	*buf;
	char	**envp;
	char	**cmd;
	char	**cmd2;
}	t_pipex;

int		vardefs(t_pipex *vars, char **argv);
char	*pathseek(char **cmd, t_pipex *vars);
void	pipe_op(int fd[2]);
void	pipe_in(int fd[2]);
int		cmdcall(t_pipex *vars, char **cmd);
int		checkeo(char **argv, t_pipex *vars);
void	freepipex(t_pipex *vars);
void	free_all(t_pipex *vars);
void	fdtofile(t_pipex *var, char *filename);
int		cmdcall2(t_pipex *var, char **cmd);


#endif
