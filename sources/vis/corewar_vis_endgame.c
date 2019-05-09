/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_endgame.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:15:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 20:41:39 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void		corewar_vis_endgame_set(t_buttons *btns)
{
	btns->values.active = false;
	btns->values.hower = false;
	btns->values.press = false;
	btns->reverse.active = false;
	btns->reverse.hower = false;
	btns->reverse.press = false;
	btns->nxt.active = false;
	btns->nxt.hower = false;
	btns->nxt.press = false;
	btns->run.active = false;
	btns->run.hower = false;
	btns->run.press = false;
	btns->speedup.active = false;
	btns->speedup.hower = false;
	btns->speedup.press = false;
	btns->slowdown.active = false;
	btns->slowdown.hower = false;
	btns->slowdown.press = false;
	btns->status.active = true;
	btns->status.hower = false;
	btns->status.press = false;
}

void		corewar_vis_render_endgame(t_vis *vis, t_data *data)
{
	SDL_Rect	box;
	char		*str;
	char		*nbr;
	int			w;

	str = ft_strndup("Winner - Player ", -1);
	nbr = ft_itoabase(DEC, data->leader);
	ft_strninject(&str, nbr, -1, -1);
	ft_strdel(&nbr);
	w = (int)ft_strlen(str);
	box = (SDL_Rect){(ARENA_W / 2) - (w / 2), (WIN_H / 2) - (CHAR_H / 2),
	w + 200, CHAR_H * 2 + CHAR_H / 2};
	corewar_vis_render_btext(vis->rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, CHAR_W, CHAR_H});
	ft_strdel(&str);
	str = data->players[data->leader - 1].name;
	corewar_vis_render_btext(vis->rend, str, vis->color[data->leader],
	(SDL_Rect){box.x, box.y + CHAR_H + PAD, CHAR_W, CHAR_H});
}
