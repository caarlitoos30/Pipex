/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:05:48 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/04 22:17:22 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Ahora tenemos que recibir un archivo, un comando que se aplica sobre este y que el output lo
redireccione al input de la segunda parte del pipe, y que luego el output del segundo comando del pipe se redireccione,
a un output file que seleccionamos **Dudosa posibilidad del bonus debido a la futura minishell** */

/* ./pipex infile < grep -a | wc -c > outfile*/

/*Lógica de abiertos y de cerrados hecha, toca hacer la parte de ejecutar, crear la función de abrir todo para ahorrar líneas
y encontrar el path y variables de entorno 


    STDOUT_FILENO;
    STDIN_FILENO;
*/

/*

-esquema hijo
    dup del standar output al pipeFD 1,
    cerramos piopeFD 0,

    dup2(STDOUT_FILENO, pipe_fd[1])
    close(pipe_fd[0])
    
-equema padre
    dup del standar input al pipe FD 0
    cerramos el pipeFD 1

    dup2(STDIN_FILENO, pipe_fd[0]);
    close(pipe_fd[1]);

*/

int main(int argc, char **argv, char **env)
{
    int pipe_fd[2];
    int status;
    int pid;
    t_pipex *var;
    

    if(argc == 5)
    {
        pipe(pipe_fd);
    
        if(pid == 0)
        {
            dup2(pipe_fd[READ_END], STDIN_FILENO);
            close(pipe_fd[READ_END]);
            dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
            close(pipe_fd[WRITE_END]);
            /* if(execve(var->path, var->cmd, var->envp) == -1)*/
            
        }
    }
        
        
    
}
