/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:44:54 by nmustach          #+#    #+#             */
/*   Updated: 2019/09/19 14:58:41 by nmustach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
