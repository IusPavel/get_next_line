/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:58:33 by signacia          #+#    #+#             */
/*   Updated: 2021/05/07 20:19:30 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*point;
	size_t	i;

	point = (char *)malloc(ft_strlen(s1) + 1);
	if (!point)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(point + i) = *(s1 + i);
		i++;
	}
	*(point + i) = '\0';
	return (point);
}

/* This function builds new "line" from buffer */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		length;
	int		index;

	if (!s1 && !s2)
		return (0);
	if (!s1 || ft_strlen(s1) == 0)
		return (s2);
	length = 0;
	index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (result == 0)
		return (0);
	while (*(s1 + length))
		result[index++] = s1[length++];
	length = 0;
	while (*(s2 + length))
		result[index++] = s2[length++];
	result[index] = '\0';
	free(s1);
	free(s2);
	return (result);
}

/* This function builds s2 for "ft_strjoin" */
char	*ft_substr(char const *s, int start, int len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (substr);
	while (len-- > 0)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/* This function trims buffer */
void	ft_substr_buf(char *s, int start, int len)
{
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		s[0] = '\0';
		return ;
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	while (len-- > 0)
	{
		s[i] = s[i + start];
		i++;
	}
	s[i] = '\0';
}
