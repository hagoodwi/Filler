/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:00:27 by jirwin            #+#    #+#             */
/*   Updated: 2020/11/15 15:13:46 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(t_filler *filler)
{
	ft_putnbr(filler->y);
	ft_putchar(' ');
	ft_putnbr(filler->x);
	ft_putchar('\n');
}

int		main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler()) || parse_player(filler) != 0)
		return (1);
	while ((filler->board = init_board())
	&& parse_board_size(filler->board) == 0
		&& (filler->board->heat_map = init_heat_map(filler->board->height,
														filler->board->width))
		&& parse_board(filler->board, filler) == 0 &&
		(filler->token = init_token()) && parse_token_size(filler->token) == 0
		&& parse_token(filler->token) == 0)
	{
		calc_heat_map(filler->board);
		calc_coords(filler->board, filler->token, filler);
		print_coords(filler);
		free_board(&(filler->board));
		free_token(&(filler->token));
		reset_coords(filler);
	}
	if (filler->board)
		free_board(&(filler->board));
	if (filler->token)
		free_token(&(filler->token));
	free(filler);
	return (1);
}
