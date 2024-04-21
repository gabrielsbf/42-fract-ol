/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:34:25 by gabrfern          #+#    #+#             */
/*   Updated: 2024/04/13 13:34:27 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_has_space(char	*str, int i)
{
	if (((str[i] >= 7 && str[i] <= 13) || str[i] == 32))
		return (1);
	else
		return (0);
}
