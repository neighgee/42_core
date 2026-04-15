/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:04:53 by smariapp          #+#    #+#             */
/*   Updated: 2025/05/14 21:44:30 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	while (n > 0)
	{
		uc1 = (unsigned char)*s1;
		uc2 = (unsigned char)*s2;
		if (uc1 != uc2)
			return (uc1 - uc2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/* #include <stdio.h>
int main()
{
	char s1[9] = "12345678";
	char s2[11] = "1234567899";

	printf("diff s1,s2: %d\n",ft_strncmp(s1, s2, 20));
} */
