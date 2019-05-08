/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_mdlb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:06:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 21:03:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void	static_domination_bar(SDL_Renderer *rend, const unsigned int *arena,
			unsigned int player, SDL_Rect box)
{
	unsigned int	pct;
	unsigned int	i;

	SDL_SetRenderDrawColor(rend, R(RGBA_SHADOW), G(RGBA_SHADOW), B(RGBA_SHADOW),
	A_PB);
	SDL_RenderFillRect(rend, &box);
	pct = 0;
	i = 0;
	while (i < ARENA_SIZE)
	{
		if (arena[i] == g_color[player])
			++pct;
		++i;
	}
	box.x += PDB_SHADOW;
	box.y += PDB_SHADOW;
	box.h -= (PDB_SHADOW * 2);
	box.w -= (PDB_SHADOW * 2);
	SDL_SetRenderDrawColor(rend, R(g_color[0]), G(g_color[0]),
	B(g_color[0]), A_PB);
	SDL_RenderFillRect(rend, &box);
	box.w = (Sint32)(box.w * corewar_vis_pct(0, ARENA_SIZE, pct));
	SDL_SetRenderDrawColor(rend, R(g_color[player]), G(g_color[player]),
	B(g_color[player]), A_PB);
	SDL_RenderFillRect(rend, &box);
}

static void	static_render_name(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static int	w = 0;
	static char	*str = "Player";

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
	(SDL_Rect){BAR_X, MID_BAR_Y(i, 0), S_CHAR_W, MID_BAR_H});
	corewar_vis_render_btext(rend, data->players[i].name, g_color[i + 1],
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2), MID_BAR_Y(i, 0), S_CHAR_W,
	MID_BAR_H});
}

static void	static_render_lcl(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static int	w = 0;
	static char	*str = "Last casted live";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, g_color[i + 1],
	(SDL_Rect){BAR_X, MID_BAR_Y(i, 1), XS_CHAR_W, S_CHAR_H});
	if (data->players[i].last_live)
	{
		value = ft_uitoabase(DEC, data->players[i].last_live);
		corewar_vis_render_btext(rend, value, RGBA_TEXT2,
		(SDL_Rect){BAR_X + (w * XS_CHAR_W) + PAD, MID_BAR_Y(i, 1), XS_CHAR_W,
		S_CHAR_H});
		ft_strdel(&value);
	}
}

static void	static_render_cl(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static int	w = 0;
	static char	*str = "Current lives";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, g_color[i + 1],
	(SDL_Rect){BAR_X, MID_BAR_Y(i, 2), XS_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, data->players[i].n_lives);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * XS_CHAR_W) + PAD, MID_BAR_Y(i, 2), S_CHAR_W,
	S_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_mdlb(SDL_Renderer *rend,
			const unsigned int *arena, t_data *data)
{
	unsigned int	i;
	static SDL_Rect	bg = {BAR_X, 0, BAR_W, 75};

	i = 0;
	while (i < data->n_players)
	{
		SDL_SetRenderDrawColor(rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
		B(RGBA_SHADOW), 0xAA);
		bg.y =  MID_BAR_Y(i, 0);
		SDL_RenderFillRect(rend, &bg);
		static_render_name(rend, data, i);
		static_render_lcl(rend, data, i);
		static_render_cl(rend, data, i);
		static_domination_bar(rend, arena, i + 1,
		(SDL_Rect){BAR_X, MID_BAR_Y(i, 3), BAR_W, MID_BAR_H});
		++i;
	}
}
