/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:28:37 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/02/16 22:44:36 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_leggirest(int fd, char *res)
{
	char		*temp;
	int			bytes;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr (res, "\n") && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		res = ft_strjoin(res, temp);
	}
	free (temp);
	rreturn (res);
}

char	*get_next_line(int fd)
{
	static char	*res[5];
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res[fd] = ft_leggirest(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	linea = ft_scrivirest(res[fd]);
	res[fd] = ft_nuovorest(res[fd]);
	return (linea);
}
