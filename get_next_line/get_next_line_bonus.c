/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:52:28 by signacia          #+#    #+#             */
/*   Updated: 2021/05/09 12:42:55 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

/* This function search for matches inside buffer */
int	estimator(char **line, char *buf, size_t is_read)
{
	size_t	pnt;

	pnt = 0;
	while (pnt < is_read)
	{
		if (buf[pnt] == '\n')
		{
			*line = ft_strjoin(*line, ft_substr(buf, 0, pnt));
			ft_substr_buf(buf, pnt + 1, is_read - pnt - 1);
			return (1);
		}
		pnt++;
	}
	*line = ft_strjoin(*line, ft_substr(buf, 0, pnt));
	ft_substr_buf(buf, pnt + 1, is_read - pnt - 1);
	return (0);
}

/* Auxiliary function. Always returns zero. If (line) is NULL, line[0] = 0 */
static int	empty_buffer(char **line)
{
	if (!(*line))
	{
		*line = (char *)malloc(sizeof(char));
		*line[0] = 0;
	}
	return (0);
}

/* Major function. Returns value eof or not */
int	get_next_line(int fd, char **line)
{
	static t_list	lst[257];
	ssize_t			is_read;

	if (fd < 0 || fd > 256)
		return (-1);
	*line = 0;
	if (ft_strlen((lst[fd].buf)) > 0)
	{
		if (estimator(line, (lst[fd].buf), ft_strlen((lst[fd].buf))))
			return (1);
		if ((lst[fd].eof) == 1)
			return (0);
	}
	while (1)
	{
		is_read = read(fd, (lst[fd].buf), BUFFER_SIZE);
		if (is_read < 0)
			return (-1);
		if (is_read < BUFFER_SIZE)
			(lst[fd].eof) = 1;
		if (is_read == 0)
			return (empty_buffer(line));
		if (estimator(line, (lst[fd].buf), is_read))
			return (1);
	}
}
