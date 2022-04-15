/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 04:22:28 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/15 02:13:00 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str && str[size])
		++size;
	return (size);
}

char	*ft_substr(char const *src, unsigned int start, size_t size)
{
	char	*result;
	int		i;

	if (!src)
		return (NULL);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i, i < (int)size)
		result[i] = src[start + i];
	result[size] = '\0';
	return (result);
}

void	ft_strcpy(char *dest, char *src, int limit)
{	
	int	i;

	i = -1;
	while (++i, src && src[i] && i < limit)
		dest[i] = src[i];
}

void	ft_strlcat(char *dest, int dest_size, char *src, int limit)
{
	int	j;

	j = 0;
	while (src[j] && (dest_size + 1) < limit)
		dest[dest_size++] = src[j++];
	dest[dest_size] = '\0';
}

char	*ft_strdup(char *source)
{
	int		size;
	char	*dest;

	size = ft_strlen(source);
	dest = malloc(size + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, source, size);
	dest[size] = '\0';
	return (dest);
}
