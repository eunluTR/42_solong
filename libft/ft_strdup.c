/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:10:35 by eunlu             #+#    #+#             */
/*   Updated: 2025/03/19 21:27:26 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		len;
	char	*p1;
	int		i;

	len = ft_strlen(s1);
	p1 = malloc(len + 1);
	if (!p1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p1[i] = s1[i];
		++i;
	}
	p1[len] = '\0';
	return (p1);
}
