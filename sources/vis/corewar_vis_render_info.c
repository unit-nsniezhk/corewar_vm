/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:27:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 21:15:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_vis_render_inf_value(t_vis *vis, unsigned int value,
		unsigned int color, SDL_Rect box)
{
	char	*text;
	size_t	value_len;

	value_len = ft_unbrlen(value, 10);
	box.w = (Uint32)(CHAR_W * value_len);
	text = ft_uitoabase(DEC, value);
	corewar_vis_render_btext(vis, text, color, box);
	ft_strdel(&text);
}

static void	static_render_inf2(t_vis *vis, t_data *data)
{
	int	tmp;
	int tmp2;

	if (data->n_live < MIN_LIVE)
		tmp = RGBA_TEXT3;
	else
		tmp = RGBA_TEXTS;
	tmp2 = (int)ft_unbrlen(data->n_live, 10);
	corewar_vis_render_inf_value(vis, data->n_live, (unsigned int)tmp,
	(SDL_Rect){TOP_BAR_X + 125 + BAR_PADD,
	TOP_BAR_EL_Y(2), tmp2 * CHAR_W, BAR_H});
	corewar_vis_render_btext(vis, "/", RGBA_TEXT2,
	(SDL_Rect){TOP_BAR_X + 125 + (BAR_PADD * 2) + (CHAR_W * tmp2),
	TOP_BAR_EL_Y(2), CHAR_W, BAR_H});
	tmp = (int)ft_unbrlen(MIN_LIVE, 10);
	corewar_vis_render_inf_value(vis, MIN_LIVE, RGBA_TEXT3,
	(SDL_Rect){TOP_BAR_X + 125 + (BAR_PADD * 3) + (CHAR_W * (tmp2 + 1)),
	TOP_BAR_EL_Y(2), (CHAR_W * tmp), BAR_H});
	corewar_vis_render_btext(vis, "Processes", RGBA_TEXT2,
	(SDL_Rect){TOP_BAR_X, TOP_BAR_EL_Y(3), 90, BAR_H});
	tmp = (int)ft_unbrlen(data->n_carrs, 10);
	corewar_vis_render_inf_value(vis, data->n_carrs, RGBA_TEXT3,
	(SDL_Rect){TOP_BAR_X + 90 + BAR_PADD, TOP_BAR_EL_Y(3), (CHAR_W * tmp),
	BAR_H});
}

static void	static_render_inf(t_vis *vis, t_data *data)
{
	int	tmp;

	corewar_vis_render_btext(vis, "Cycle", RGBA_TEXT2,
	(SDL_Rect){TOP_BAR_X, TOP_BAR_EL_Y(0), 60, BAR_H});
	corewar_vis_render_inf_value(vis, data->cycle, RGBA_TEXT3,
	(SDL_Rect){TOP_BAR_X + 70 + BAR_PADD, TOP_BAR_EL_Y(0), 100, BAR_H});
	corewar_vis_render_btext(vis, "Next check in", RGBA_TEXT2,
	(SDL_Rect){TOP_BAR_X, TOP_BAR_EL_Y(1), 130, BAR_H});
	tmp = (int)ft_unbrlen(data->ctc - (data->cycle % data->ctc), 10);
	corewar_vis_render_inf_value(vis, data->ctc - (data->cycle % data->ctc),
	RGBA_TEXT3, (SDL_Rect){TOP_BAR_X + 130 + BAR_PADD, TOP_BAR_EL_Y(1),
	(CHAR_W * tmp), BAR_H});
	corewar_vis_render_btext(vis, "Lives casted", RGBA_TEXT2,
	(SDL_Rect){TOP_BAR_X, TOP_BAR_EL_Y(2), 125, BAR_H});
}

static double	static_pct(int min, int max, int curr)
{
	double	pos;
	double	pct;
	double	dist;

	dist = max - min;
	pos = curr - min;
	if (dist == 0)
		pct = 1.0;
	else
		pct = pos / dist;
	return (pct);
}

static void	static_domination_bar(t_vis *vis, unsigned int player, SDL_Rect box)
{
	unsigned int	curr;
	unsigned int	i;

	SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
	B(RGBA_SHADOW), A_PB);
	SDL_RenderFillRect(vis->rend, &box);
	curr = 0;
	i = 0;
	while (i < ARENA_SIZE)
	{
		if (vis->color[i] == g_color[player])
			++curr;
		++i;
	}
	box.x += PDB_SHADOW_W;
	box.y += PDB_SHADOW_W;
	box.h -= (PDB_SHADOW_W * 2);
	box.w -= (PDB_SHADOW_W * 2);
	SDL_SetRenderDrawColor(vis->rend, R(g_color[0]), G(g_color[0]),
	B(g_color[0]), A_PB);
	SDL_RenderFillRect(vis->rend, &box);
	box.w = (Sint32)(box.w * static_pct(0, ARENA_SIZE, curr));
	SDL_SetRenderDrawColor(vis->rend, R(g_color[player]), G(g_color[player]),
	B(g_color[player]), A_PB);
	SDL_RenderFillRect(vis->rend, &box);
}

static void	static_render_player(t_vis *vis, t_data *data, unsigned int i)
{
	char	*text;
	int		tmp;

	corewar_vis_render_btext(vis, "Player", RGBA_TEXT2,
	(SDL_Rect){MID_BAR_X, MID_BAR_EL_Y(i, 0), 80, MID_BAR_H});
	tmp = (int)ft_strlen(data->players[i].name);
	corewar_vis_render_btext(vis, data->players[i].name, g_color[i + 1],
	(SDL_Rect){MID_BAR_X + 80 + BAR_PADD, MID_BAR_EL_Y(i, 0), CHAR_W * tmp,
	MID_BAR_H});
	corewar_vis_render_btext(vis, "Last casted live", g_color[i + 1],
	(SDL_Rect){MID_BAR_X, MID_BAR_EL_Y(i, 1), 110, BAR_H});
	if (data->players[i].last_live)
	{
		tmp = (int)ft_unbrlen(data->players[i].last_live, 10);
		text = ft_uitoabase(DEC, data->players[i].last_live);
		corewar_vis_render_btext(vis, text, RGBA_TEXT3, (SDL_Rect){MID_BAR_X
		+ 110 + BAR_PADD, MID_BAR_EL_Y(i, 1), CHAR_W * tmp, BAR_H});
		ft_strdel(&text);
	}
	corewar_vis_render_btext(vis, "Current lives", g_color[i + 1],
	(SDL_Rect){MID_BAR_X, MID_BAR_EL_Y(i, 2), 90, BAR_H});
	text = ft_uitoabase(DEC, data->players[i].n_lives);
	tmp = (int)ft_unbrlen(data->players[i].n_lives, 10);
	corewar_vis_render_btext(vis, text, RGBA_TEXT3,
	(SDL_Rect){MID_BAR_X + 90 + BAR_PADD, MID_BAR_EL_Y(i, 2), CHAR_W * tmp,
	BAR_H});
	ft_strdel(&text);
}

static void	static_render_players(t_vis *vis, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_players)
	{
		static_render_player(vis, data, i);
		static_domination_bar(vis, i + 1,
		(SDL_Rect){MID_BAR_X, MID_BAR_EL_Y(i, 3), BAR_W, MID_BAR_H});
		++i;
	}
}

void		corewar_vis_render_info(t_vis *vis, t_data *data)
{
	static_render_inf(vis, data);
	static_render_inf2(vis, data);
	static_render_players(vis, data);
}
