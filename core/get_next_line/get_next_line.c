/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clone3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:22:39 by tbaker            #+#    #+#             */
/*   Updated: 2023/10/07 17:56:30 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_line_return(char **left, int nl)
{
	char	*line;
	char	*temp;

	line = NULL;
	if (!*left)
		return (NULL);
	line = strndup(*left, nl);
	if (!line)
		return (NULL);
	temp = ft_strndup(*left + nl, ft_strlen(*left) - (nl));
	free(*left);
	*left = temp;
	temp = NULL;
	return (line);
}

int	ft_read(int fd, char **buffer)
{
	int bytes;
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!*buffer)
		return (-1);
	bytes = read(fd, *buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (-1);
	(*buffer)[bytes] = '\0';
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*buffer;
	int			nl;
	int			bytes;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl = ft_find_nl(left);
	if (nl > 0)
		return (ft_line_return(&left, nl));
	while (1)
	{
		bytes = ft_read(fd, &buffer);
		if (bytes <= 0)
			break;
		if (!left)
			left = ft_strndup("", 1);
		left = ft_strjoin(left, buffer);
		nl = ft_find_nl(left); 
		if (nl > 0)
			return (ft_line_return(&left, nl));
	}
	if (left)
	{
		line = ft_strndup(left, ft_strlen(left));
		free (left);
		left = NULL;
	}
	free (buffer);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Why want this file open");
		return (1);
	}
	printf("test 1 = %s", get_next_line(fd));
	printf("test 2 = %s", get_next_line(fd));
	printf("test 3 = %s", get_next_line(fd));
	printf("test 4 = %s", get_next_line(fd));
	printf("test 5 = %s", get_next_line(fd));
	printf("test 6 = %s", get_next_line(fd));
	printf("test 7 = %s", get_next_line(fd));
	printf("test 8 = %s", get_next_line(fd));
	printf("test 9 = %s", get_next_line(fd));
	printf("test 10 = %s", get_next_line(fd));
	close(fd);
	return (0);
}*/
