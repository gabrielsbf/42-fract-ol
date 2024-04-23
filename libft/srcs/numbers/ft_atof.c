/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:46 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 19:40:47 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

float	dec_part(char *nptr)
{
	float	dec;
	int		i;

	dec = 0;
	i = 1;
	if (*nptr != '.')
		return (0);
	while (*(nptr + i) != '\0')
	{
		dec = dec + ((float)(*(nptr + i) - 48)
				/ (float)ft_pow((double)10, i));
		i++;
	}
	return (dec);
}

float	ft_atof(char *nptr)
{
	int		minus;
	int		i;
	float	result;

	minus = 0;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		minus = (nptr[i] == 45);
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result = result * 10 + (float)(nptr[i] - 48);
		i++;
	}
	result += dec_part(nptr + i);
	if (minus != 0)
		result *= -1;
	return (result);
}
