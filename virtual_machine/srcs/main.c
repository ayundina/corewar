/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/11/12 22:27:36 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		declare_winner(t_vm *vm)
{
	int			i;
	int			winner;

	i = 0;
	winner = 0;
	while (i < vm->champion_count)
	{
		if (vm->champions[i].id == vm->game.last_alive_champ)
		{
			ft_putstr("* ");
			ft_printf("THE WINNER IS: name:    %s\n", vm->champions[i].name);
			ft_putstr("*                ");
			ft_printf("comment: \"%s\"\n", vm->champions[i].comment);
			ft_putstr("*                ");
			ft_printf("id:      %d\n", vm->champions[i].id);
			winner = 1;
		}
		i++;
	}
	if (!winner)
		ft_printf("\n* There was no winner!\n");
	return ;
}

int			main(int argc, char **argv)
{
	t_vm	vm;

	init_vm(&vm, argc, argv);
	check_arguments(&vm);
	init_champions(&vm);
	load_champs(&vm);
	init_cursors(&vm);
	introduce_champions(&vm, vm.champions);
	if (vm.visualizer)
		init_visuals(&vm);
	game(&vm, &vm.game);
	end_of_game(&vm);
	BASS_Free();
	declare_winner(&vm);
	return (1);
}
