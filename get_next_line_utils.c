/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 04:22:28 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/14 07:01:21 by dcerrito         ###   ########.fr       */
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

void	ft_strlcpy(char *dest, char *src, int limit)
{	
	int	i;

	i = -1;
	while (++i, src && src[i] && (i + 1) < limit)
		dest[i] = src[i];
	if (src && limit > 0)
		dest[i] = '\0';
}

void	ft_strlcat(char *dest, char *src, int limit)
{
	int	i;
	int	j;
	int	dest_size;

	j = 0;
	i = ((dest_size = ft_strlen(dest)));
	while (src[j] && (i + 1) < limit)
		dest[i++] = src[j++];
	if (limit > 0 && dest_size <= limit)
		dest[i] = '\0';
}

char	*ft_strdup(char *source)
{
	int		size;
	char	*dest;

	size = 1 + ft_strlen(source);
	dest = malloc(size);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, source, size);
	return (dest);
}
