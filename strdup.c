/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvelasco <cvelasco@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:25:17 by cvelasco          #+#    #+#             */
/*   Updated: 2022/12/28 16:57:02 by cvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*des;

	des = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!des)
		return (NULL);
	i = 0;
	while (s[i])
	{
		des[i] = s[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
