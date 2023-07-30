/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:52:16 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/27 16:41:50 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(1, "\n", 1);
}
/*
int	main(void)
{
	int	fd = 1;
	char *s = "goodbye world";
	char *s1 = "";
	ft_putendl_fd(s, fd);
	ft_putendl_fd(s1, fd);
	return (0);
}*/
