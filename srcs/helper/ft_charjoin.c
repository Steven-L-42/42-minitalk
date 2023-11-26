/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:38:52 by slippert          #+#    #+#             */
/*   Updated: 2023/11/05 10:59:46 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minitalk.h"

char	*ft_charjoin(char const *s1, char const c2)
{
	char	*s3;
	char	*temp_s3;
	size_t	s1_length;

	s1_length = ft_strlen(s1);
	s3 = (char *)malloc(s1_length + 1);
	if (!s3)
		return (NULL);
	temp_s3 = s3;
	while (*s1)
		*s3++ = *s1++;
	*s3++ = c2;
	return (temp_s3);
}
