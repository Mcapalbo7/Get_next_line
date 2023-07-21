/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:19:41 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/19 18:24:57 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *res, char *temp);
char	*ft_scrivirest(char *res);
char	*ft_nuovorest(char *res);
char	*ft_leggirest(int fd, char *res);
#endif
