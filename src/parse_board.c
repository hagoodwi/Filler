/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:01:10 by jirwin            #+#    #+#             */
/*   Updated: 2020/11/15 15:13:56 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	parse_board_line(char *board_line, int *heat_map_line,
								t_board *board, t_filler *filler)
{
	int	i;

	i = 0;
	while (i < board->width)
	{
		if (board_line[i] == '.')
			heat_map_line[i] = 0;
		else if (ft_toupper(board_line[i]) == filler->player_symbol)
			heat_map_line[i] = -1;
		else if (ft_toupper(board_line[i]) == filler->enemy_symbol)
			heat_map_line[i] = -2;
		else
			return (1);
		i++;
	}
	return (0);
}

int			fill_board(t_board *board, t_filler *filler)
{
	char	*line;
	int		y;

	line = 0;
	y = 0;
	while (y < board->height)
	{
		if (get_next_line(0, &line) != 1
		|| parse_board_line(&line[4], board->heat_map[y], board, filler) != 0)
		{
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
		y++;
	}
	return (0);
}

int			parse_board(t_board *board, t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) != 1
		|| (int)ft_strlen(line) != board->width + 4)
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	if (fill_board(board, filler))
		return (1);
	return (0);
}
