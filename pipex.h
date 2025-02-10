/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:06:05 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/10 17:26:25 by calguaci         ###   ########.fr       */
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
    int pid;
    int fd[2];
    int fd2[2];
    int fdout;
    int fdin;
    char *path;
    char *path2;
    char *output;
    char *buf;
    char **envp;
    char **cmd;
    char **cmd2;
}   t_pipex;

#endif
