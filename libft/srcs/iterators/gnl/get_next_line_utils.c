/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:39:25 by gabrfern          #+#    #+#             */
/*   Updated: 2024/01/24 22:20:42 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_gnl_strchr(char *s, int c)
{
	char	*strc;
	int		i;

	if (!s)
		return (0);
	strc = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&strc[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&strc[i]);
	return (0);
}

int	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && size > i + 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	ft_gnl_strcat(char *dst, char *src)
{
	int	i_dst;
	int	i_src;

	i_src = 0;
	i_dst = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (dst[i_dst] != '\0')
		i_dst++;
	while (src[i_src] != '\0')
		dst[i_dst++] = src[i_src++];
	dst[i_dst] = '\0';
	return (i_dst);
}

char	*ft_gnl_strdup(char *s, int size_buff)
{
	int		i;
	char	*ptr;

	if (size_buff <= 0)
		return (NULL);
	i = 0;
	if (!s)
		return (NULL);
	ptr = (char *)malloc((size_buff + 1) * sizeof(char));
	while (i < size_buff)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
