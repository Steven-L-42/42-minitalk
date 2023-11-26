/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:41:14 by slippert          #+#    #+#             */
/*   Updated: 2023/10/11 17:20:33 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start_length;
	size_t	end_length;

	start_length = 0;
	while (s1[start_length] && ft_char_in_set(s1[start_length], set))
		start_length++;
	end_length = ft_strlen(s1);
	while (end_length > start_length && ft_char_in_set(s1[end_length - 1], set))
		end_length--;
	str = (char *)ft_calloc(1, (end_length - start_length) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start_length < end_length)
		str[i++] = s1[start_length++];
	str[i] = '\0';
	return (str);
}
