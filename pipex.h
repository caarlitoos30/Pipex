/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calguaci <calguaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:06:05 by calguaci          #+#    #+#             */
/*   Updated: 2025/02/03 23:11:06 by calguaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>

# define ERROR_MESSAGE "Introduce el ejecutable y mandelbrot o julia con dos"

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

int			ft_strncmp(char *s1, char *s2, int n);


#endif
