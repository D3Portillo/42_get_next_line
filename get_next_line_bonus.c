/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:34:47 by dcerrito          #+#    #+#             */
/*   Updated: 2022/04/17 03:49:16 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	fetches_content(int fd, long *total_read, char **container)
{
	char	*result;
	char	read_content[BUFFER_SIZE];
	long	merge_size;
	long	read_size;
	long	total_size;

	read_size = read(fd, read_content, BUFFER_SIZE);
	if (read_size < 1)
		return (0);
	merge_size = ft_strlen(*container);
	total_size = merge_size + read_size + 1;
	result = malloc(total_size);
	if (!result)
		return (0);
	*total_read += read_size;
	ft_strcpy(result, *container, merge_size);
	ft_strlcat(result, merge_size, read_content, total_size);
	free(*container);
	return (*container = result, read_size);
}

static char	*ft_sanitize(char **cont_ref, char *to_return, char *new_cont)
{
	free(*cont_ref);
	return (*cont_ref = new_cont, to_return);
}

static char	*ft_get_line(char **cont_ref, int idx)
{
	char	*result;

	result = ft_substr(*cont_ref, 0, idx);
	return (
		ft_sanitize(
			cont_ref, result, ft_substr(*cont_ref, idx, ft_strlen(*cont_ref)))
	);
}

static char	*handle_parse(int fd, char **content, long total_read, long i)
{
	fetches_content(fd, &total_read, content);
	while (*content)
	{
		i = -1;
		while ((*content)[++i])
			if ((*content)[i] == '\n')
				return (ft_get_line(content, i + 1));
		if (fetches_content(fd, &total_read, content) == 0)
		{
			if (i == 0)
				return (ft_sanitize(content, NULL, NULL));
			return (ft_sanitize(content, ft_strdup(*content), NULL));
		}
	}
	return (*content);
}

char	*get_next_line(int fd)
{
	static char	*content_arr[1024];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1023)
		return (NULL);
	return (handle_parse(fd, &content_arr[fd], 0, 0));
}
