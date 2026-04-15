/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwin <mwin@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:41:43 by mwin              #+#    #+#             */
/*   Updated: 2025/05/23 12:28:08 by mwin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring_s;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		len = s_len - start;
	substring_s = (char *)malloc((len + 1) * sizeof (char));
	if (substring_s == NULL)
		return (NULL);
	while (i < len)
	{
		substring_s[i] = s[start + i];
		i++;
	}
	substring_s[i] = '\0';
	return (substring_s);
}
