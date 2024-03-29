/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoue <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:50:34 by monoue            #+#    #+#             */
/*   Updated: 2021/02/08 16:56:39 by monoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, const int c)
{
	const unsigned char	uc = (unsigned char)c;
	const int			s_len = (int)ft_strlen(s);
	int					index;

	if (s == NULL)
		return (NULL);
	index = s_len;
	while (index >= 0)
	{
		if (s[index] == uc)
			return ((char *)&s[index]);
		index--;
	}
	return (NULL);
}
