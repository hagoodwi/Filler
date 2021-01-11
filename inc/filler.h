/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:13:02 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/11/15 15:13:23 by hagoodwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"
# include "limits.h"
# include <stdio.h>

typedef struct	s_board
{
	int			height;
	int			width;
	int			**heat_map;
}				t_board;

typedef struct	s_token
{
	int			height;
	int			width;
	char		**map;
}				t_token;

typedef struct	s_filler
{
	char		player_symbol;
	char		enemy_symbol;
	t_board		*board;
	t_token		*token;
	int			y;
	int			x;
}				t_filler;

t_filler		*init_filler(void);
t_board			*init_board(void);
int				**init_heat_map(int height, int width);
t_token			*init_token(void);
int				parse_player(t_filler *filler);
int				parse_board_size(t_board *board);
int				parse_board(t_board *board, t_filler *filler);
int				parse_token_size(t_token *token);
int				parse_token(t_token *token);
void			calc_heat_map(t_board *board);
void			calc_coords(t_board *board, t_token *token, t_filler *filler);
void			print_coords(t_filler *filler);
void			free_board(t_board **board);
void			free_token(t_token **token);
void			reset_coords(t_filler *filler);

#endif
