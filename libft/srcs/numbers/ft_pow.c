/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:40:33 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/22 19:40:42 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double value, int pow)
{
	int		i;
	double	res;

	res = value;
	i = 1;
	while (i < pow)
	{
		res *= value;
		i++;
	}
	return (res);
}
