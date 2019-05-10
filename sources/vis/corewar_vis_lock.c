/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_lock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:15:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 20:45:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"
#include "libft.h"

void	corewar_vis_gameover_lock(t_buttons *btns)
{
	btns->detail.active = false;
	btns->detail.hower = false;
	btns->detail.press = false;
	btns->reverse.active = false;
	btns->reverse.hower = false;
	btns->reverse.press = false;
	btns->next.active = false;
	btns->next.hower = false;
	btns->next.press = false;
	btns->run.active = false;
	btns->run.hower = false;
	btns->run.press = false;
	btns->speed_up.active = false;
	btns->speed_up.hower = false;
	btns->speed_up.press = false;
	btns->slow_down.active = false;
	btns->slow_down.hower = false;
	btns->slow_down.press = false;
	btns->status.active = true;
	btns->status.hower = false;
	btns->status.press = false;
}

void	corewar_vis_render_gameover(t_vis *vis, t_data *data)
{
	static Sint32	w = 0;
	Sint32			w2;
	static SDL_Rect	box;
	static SDL_Rect	box2;

	if (!w)
	{
		ft_strninject(&data->players[data->leader - 1].name, "Player ", 0, -1);
		ft_strninject(&data->players[data->leader - 1].name, " won !!!", -1,
		-1);
		w = (Sint32)ft_strlen(data->players[data->leader - 1].name);
		box.x = (ARENA_W / 2) - ((w * L_CHAR_W) / 2);
		box.y = (WIN_H / 3) - (L_CHAR_H / 2);
		box.w = L_CHAR_W;
		box.h = L_CHAR_H;
		w2 = (Sint32)ft_strlen(data->players[data->leader - 1].comment);
		box2.x = (ARENA_W / 2) - ((w2 * CHAR_W) / 2);
		box2.y = box.y + L_CHAR_H + (PAD * 10);
		box2.w = CHAR_W;
		box2.h = L_CHAR_H;
	}
	corewar_vis_render_btext(vis->rend, data->players[data->leader - 1].name,
	vis->color[data->leader - 1], box);
	corewar_vis_render_btext(vis->rend, data->players[data->leader - 1].comment,
	vis->color[data->leader - 1], box2);
}

static SDL_Rect	static_box(unsigned int i)
{
	if (i == 1)
		return ((SDL_Rect){200, 200, 0, 0});
	if (i == 2)
		return ((SDL_Rect){ARENA_W - 200, 200, 0, 0});
	if (i == 3)
		return ((SDL_Rect){200, WIN_H - 200, 0, 0});
	else
		return ((SDL_Rect){ARENA_W - 200, WIN_H - 200, 0, 0});
}

void			corewar_vis_render_gamestart(t_vis *vis, t_data *data)
{
	static Sint32	w = 0;
	SDL_Rect		box;
	unsigned int	i;
	Sint32			w_tmp;
	char			*str;

	if (!w)
		w = (Sint32)ft_strlen("Contestants");
	corewar_vis_render_btext(vis->rend, "Contestants", RGBA_TEXT,
	(SDL_Rect){(ARENA_W / 2) - ((w * L_CHAR_W) / 2),
	(WIN_H / 3) + (L_CHAR_H / 3), L_CHAR_W, L_CHAR_H});
	i = 1;
	while (i <= data->n_players)
	{
		w_tmp = (Sint32)ft_strlen(data->players[i - 1].name);
		box = static_box(i);
		corewar_vis_render_btext(vis->rend, data->players[i - 1].name,
		g_color[i], (SDL_Rect){box.x - (w_tmp * L_CHAR_W / 2),
		box.y - L_CHAR_H - (PAD * 5), L_CHAR_W, L_CHAR_H});
		str = ft_itoabase(DEC, data->players[i - 1].code_size);
		ft_strninject(&str, "Weight of ", 0, -1);
		w_tmp = (Sint32)ft_strlen(str);
		corewar_vis_render_btext(vis->rend, str, g_color[i],
		(SDL_Rect){box.x - (w_tmp * CHAR_W / 2), box.y ,
		CHAR_W, CHAR_H});
		ft_strdel(&str);
		++i;
	}
}
