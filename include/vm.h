/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 08:55:23 by widraugr          #+#    #+#             */
/*   Updated: 2019/10/31 15:47:58 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VM_H
# define	VM_H

#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "op.h"

typedef struct	s_plyaer
{
	int			num_pl;
	char		*name_pl;
	char		*massage_pl;
}				t_plyaer;

typedef struct	s_vm
{
	t_plyaer	plyaers[4];
}				t_vm;
#endif
