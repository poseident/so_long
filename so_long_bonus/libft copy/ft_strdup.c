/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:08:10 by bschweit          #+#    #+#             */
/*   Updated: 2022/03/02 16:43:43 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	length;
	size_t	index;

	index = 0;
	length = 0;
	if (!s1)
		return (NULL);
	while (s1[length] != '\0')
	{
		length++;
	}
	length++;
	copy = malloc(length * sizeof(char));
	while (s1[index] != '\0')
	{
		copy[index] = s1[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
