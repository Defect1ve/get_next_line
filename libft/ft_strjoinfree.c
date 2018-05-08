/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:08:37 by ikotvits          #+#    #+#             */
/*   Updated: 2018/03/26 20:08:38 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	j = 0;
	if (s2)
		j = ft_strlen(s2);
	if ((!s1 && !s2) || !(str = (char *)malloc(i + j + 1)))
		return (0);
	i = -1;
	while (s1 && s1[++i] != '\0')
		str[i] = s1[i];
	str[i + j] = '\0';
	while (s2 && j > 0)
	{
		str[i + j - 1] = s2[j - 1];
		j--;
	}
	free(s1);
	free(s2);
	return (str);
}
