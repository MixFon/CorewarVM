/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 08:55:02 by widraugr          #+#    #+#             */
/*   Updated: 2019/10/31 15:47:57 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	infill_num_pl(t_plyaer *pl, char *name, int num)
{
	static int i = 0;
	static int n = 1;

	if (i >= MAX_PLAYERS)
		sys_err("There are too many players.\n");
	if (num != 0)
		(pl[i]).num_pl = num;
	else
		(pl[i]).num_pl = n;
	n++;
	i++;
}

void	read_num_pl(t_plyaer *pl, int *i, int ac, char **av)
{
	int num;

	if (*i + 2 < ac)
	{
		num = ft_atoi(av[*i + 1]);
		if (num < 0 && num > 5)
			sys_err("The wrong number plyaer.\n");
		infill_num_pl(pl, av[*i + 2], num);
		ft_printf("num = {%d}\n", num);
	}
	else
		sys_err("The wrong flag -n.\n");
	*i += 2;
}

void	read_arg(t_vm *vm, int ac, char **av)
{
	int		i;
	int		index;
	char	*tmp;

	i = 0;
	index = 1;
	while(++i < ac)
	{
		if (!ft_strncmp(av[i], "-n", 2))
		{
			read_num_pl(vm->plyaers, &i, ac, av);
			continue;
		}
		if ((tmp = ft_strstr(av[i], ".cor")) && (av[i] - tmp) < 0)
			infill_num_pl(vm->plyaers, av[i], 0); 
		ft_putendl("HELLO");
		ft_printf("av = {%s}\n", av[i]);
	}
}

void	print_pl(t_plyaer *pl)
{
	int i = 4;

	while(--i >= 0)
		ft_printf("pl [%d] = [%d]\n", i, pl[i].num_pl);
}

void	init_pl(t_plyaer *pl)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		pl[i].num_pl = 0; 
		pl[i].name_pl = NULL;
		pl[i].massage_pl = NULL;
	}
}

void	init(t_vm *vm)
{
	init_pl(vm->plyaers);
}

int		main(int ac, char **av)
{
	t_vm	vm;

	init(&vm);
	read_arg(&vm, ac, av);
	print_pl(vm.plyaers);
	return (0);
}
