/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:57:01 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/19 19:54:40 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_leggirest(int fd, char *res)
{
	char	*temp;
	int		bytes;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(res, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		res = ft_strjoin(res, temp);
	}
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*res;
	char			*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = ft_leggirest(fd, res);
	if (!res)
		return (NULL);
	linea = ft_scrivirest(res);
	res = ft_nuovorest(res);
	return (linea);
}
