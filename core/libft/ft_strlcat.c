/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:16:22 by tbaker            #+#    #+#             */
/*   Updated: 2023/07/26 17:16:28 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	size--;
	while (src[j] != '\0' && i + j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int	main(void)
{
	char dest1[] = "i";
	char src1[] = "iii";
	char dest2[] = "i";
	char src2[] = "iii";
	size_t r1;
	size_t r2;
	size_t size = 5;
	char buffer1[size];
	char buffer2[size];

	strcpy (buffer1, dest1);
	r1 = ft_strlcat(buffer1, src1, size);

	puts(buffer1);
	printf("value returned: %lu\n", r1);
	if (r1 > size)
		puts("String Truncated for test1");
	else
		puts("String was fully copied for test1");


	strcpy (buffer2, dest2);
	r2 = strlcat(buffer2, src2, size);

	puts(buffer2);
	printf("value returned: %lu\n", r2);
	if (r2 > size)
		puts("String Truncated for test2");
	else
		puts("String was fully copied for test2");
	return (0);
}*/
