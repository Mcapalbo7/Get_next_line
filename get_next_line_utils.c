/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:02:49 by mcapalbo          #+#    #+#             */
/*   Updated: 2023/07/21 22:43:32 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char	*str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *res, char *temp)
{
	char	*str;
	int		i;
	int		j;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !temp)
		return (NULL);
	i = -1;
	j = 0;
	str = malloc((ft_strlen(res) + ft_strlen(temp) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (res[++i])
		str[i] = res[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	str[ft_strlen(res) + ft_strlen(temp)] = '\0';
	free (res);
	return (str);
}

char	*ft_scrivirest(char *res)
{
	char	*linea;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	linea = (char *)malloc(sizeof(char) * (i + 2));
	if (!linea)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		linea[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		linea[i] = res[i];
		i++;
	}
	linea[i] = '\0';
	return (linea);
}

char	*ft_nuovorest(char *res)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free (res);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(res) -i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (res[i])
		str[j++] = res[i++];
	str[j] = '\0';
	free (res);
	return (str);
}
