/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:05:48 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/04 08:46:26 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Ahora tenemos que recibir un archivo, un comando que se aplica sobre este y que el output lo
redireccione al input de la segunda parte del pipe, y que luego el output del segundo comando del pipe se redireccione,
a un output file que seleccionamos **Dudosa posibilidad del bonus debido a la futura minishell** */

/* ./pipex infile < grep -a | wc -c > outfile*/

/*Lógica de abiertos y de cerrados hecha, toca hacer la parte de ejecutar, crear la función de abrir todo para ahorrar líneas
y encontrar el path y variables de entorno */

void	child(char **argv, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(argv[2], env);
}

void parent(char **argv, int *p_fd, char **env)
{
    int fd;

    fd = open_file(argv[4], 1);
    dup2(fd, 1);
    dup2(p_fd[0], 0);
    close(p_fd[1]);
    exec(argv[3], env);
}

int main(int argc, char **argv, char **env)
{
    int p_fd[2];
    pid_t pid;

    if (argc != 5)
        exit_handler(1);
    if (pipe(p_fd) == -1)
        exit(-1);

    

}
