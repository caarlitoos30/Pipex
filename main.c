/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:05:48 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/03 23:48:05 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*Ahora tenemos que recibir un archivo, un comando que se aplica sobre este y que el output lo
redireccione al input de la segunda parte del pipe, y que luego el output del segundo comando del pipe se redireccione,
a un output file que seleccionamos **Dudosa posibilidad del bonus debido a la futura minishell** */
int main(int argc, char **argv, char **env)
{
    int p_fd[2];
    pid_t pid;

    if (argc != 5)
        exit_handler(1);

}
