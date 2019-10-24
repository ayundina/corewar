/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm       #+#    #+#                */
/*   Updated: 2019/10/24 21:25:39 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** INIT_WAIT_CYCLES
** Set all the wait cycles for the corresponding opcodes (-1).
*/

void		init_wait_cycles(t_vm *vm)
{
	vm->wait[0] = 10;
	vm->wait[1] = 5;
	vm->wait[2] = 5;
	vm->wait[3] = 10;
	vm->wait[4] = 10;
	vm->wait[5] = 6;
	vm->wait[6] = 6;
	vm->wait[7] = 6;
	vm->wait[8] = 20;
	vm->wait[9] = 25;
	vm->wait[10] = 25;
	vm->wait[11] = 800;
	vm->wait[12] = 10;
	vm->wait[13] = 50;
	vm->wait[14] = 1000;
	vm->wait[15] = 2;
	return ;
}

/*
** INIT_T_DIR
** Set all the t_dir sizes for the corresponding opcodes (-1).
*/

void		init_t_dir_and_n_flag(t_vm *vm)
{
	vm->t_dir[0] = 4;
	vm->t_dir[1] = 4;
	vm->t_dir[2] = 4;
	vm->t_dir[3] = 4;
	vm->t_dir[4] = 4;
	vm->t_dir[5] = 4;
	vm->t_dir[6] = 4;
	vm->t_dir[7] = 4;
	vm->t_dir[8] = 2;
	vm->t_dir[9] = 2;
	vm->t_dir[10] = 2;
	vm->t_dir[11] = 2;
	vm->t_dir[12] = 4;
	vm->t_dir[13] = 2;
	vm->t_dir[14] = 2;
	vm->t_dir[15] = 4;
	vm->n_flag[0] = 0;
	vm->n_flag[1] = 0;
	vm->n_flag[2] = 0;
	vm->n_flag[3] = 0;
	return ;
}

void		init_vm(t_vm *vm, int argc, char **argv)
{
	vm->memory = malloc(sizeof(unsigned char) * MEM_SIZE + 1);
	vm->champion_count = 0;
	vm->champions = NULL;
	vm->dump_flag = -1;
	vm->argc = argc;
	vm->argv = argv;
	vm->cursors = NULL;
	vm->game.cycles = 0;
	vm->game.check = 0;
	vm->game.cycles_to_die = CYCLE_TO_DIE;
	vm->game.nbr_live = 0;
	vm->game.last_alive_champ = 0;
	init_wait_cycles(vm);
	init_t_dir_and_n_flag(vm);
	return ;
}

/*
** can a player die? (?:AYU)
**	while (cursor)
**	{
**		if (cursor->live == 0)
**		{
**			delete_cursor
**		}
**	}
*/

int			main(int argc, char **argv)
{
	t_vm	vm;
	int		i;

	init_vm(&vm, argc, argv);
	check_arguments(&vm);
	init_champions(&vm);
	load_champs(&vm);
	init_cursors(&vm);
	i = 0;
	while (i < vm.champion_count)
	{
		ft_printf("id = %d, filename = %s\n",
		vm.champions[i].id, vm.champions[i].filename);
		i++;
	}
	game(&vm, &vm.game);
	if (dump_check(vm))
		dump_flag(vm.memory);
	return (1);
}