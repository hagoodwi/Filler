/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:00:21 by jirwin            #+#    #+#             */
/*   Updated: 2020/11/15 15:13:42 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init_filler(void)
{
	t_filler	*filler;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->player_symbol = 0;
		filler->enemy_symbol = 0;
		filler->board = NULL;
		filler->token = NULL;
	}
	return (filler);
}

t_board		*init_board(void)
{
	t_board	*board;

	if ((board = (t_board *)ft_memalloc(sizeof(t_board))))
	{
		board->height = 0;
		board->width = 0;
		board->heat_map = NULL;
	}
	return (board);
}

int			**init_heat_map(int height, int width)
{
	int	**heat_map;
	int	y;

	y = 0;
	if ((heat_map = (int **)ft_memalloc(sizeof(int *) * height)))
	{
		while (y < height)
		{
			if (!(heat_map[y] = (int *)ft_memalloc(sizeof(int) * width)))
			{
				while (--y >= 0)
					free(heat_map[y]);
				free(heat_map);
				return (NULL);
			}
			y++;
		}
	}
	return (heat_map);
}

t_token		*init_token(void)
{
	t_token	*token;

	if ((token = (t_token *)ft_memalloc(sizeof(t_token))))
	{
		token->height = 0;
		token->width = 0;
		token->map = NULL;
	}
	return (token);
}
