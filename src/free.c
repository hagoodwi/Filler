/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:00:18 by jirwin            #+#    #+#             */
/*   Updated: 2020/11/15 15:13:33 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_board(t_board **board)
{
	int	y;

	y = 0;
	while (y < (*board)->height)
	{
		free((*board)->heat_map[y]);
		y++;
	}
	free((*board)->heat_map);
	free((*board));
	(*board) = NULL;
}

void	free_token(t_token **token)
{
	int	y;

	y = 0;
	while (y < (*token)->height)
	{
		free((*token)->map[y]);
		y++;
	}
	free((*token)->map);
	free((*token));
	(*token) = NULL;
}

void	reset_coords(t_filler *filler)
{
	filler->y = 0;
	filler->x = 0;
}
