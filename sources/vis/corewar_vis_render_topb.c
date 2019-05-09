/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_topb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:13:07 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 20:57:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void	static_render_cycle(SDL_Renderer *rend, int cycle)
{
	static int	w = 0;
	static char *str = "Cycle";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TOP_BAR_Y(1), S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, cycle);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TOP_BAR_Y(1), S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_nci(SDL_Renderer *rend, int cycle, int ctc)
{
	static int	w = 0;
	static char *str = "Next check in";
	char		*value;
	int 		nci;

	nci = (ctc - (cycle % ctc));
	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TOP_BAR_Y(2), S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, nci);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TOP_BAR_Y(2), S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_lc(SDL_Renderer *rend, int n_live)
{
	static int	w = 0;
	static char *str = "Lives casted";
	char		*value;
	int			tmp;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, n_live);
	tmp = (n_live < MIN_LIVE ? RGBA_TEXT3 : RGBA_TEXTS);
	corewar_vis_render_btext(rend, value, (unsigned int)tmp,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
	tmp = (int)ft_nbrlen(n_live, 10);
	corewar_vis_render_btext(rend, "/", RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2) + (S_CHAR_W * tmp),
	TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, MIN_LIVE);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 3) + (S_CHAR_W * (tmp + 1)),
	TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_pcs(SDL_Renderer *rend, int n_carrs)
{
	static int	w = 0;
	static char *str = "Processes";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TOP_BAR_Y(4), S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, n_carrs);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TOP_BAR_Y(4), S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_topb(SDL_Renderer *rend, t_button *status,
			t_data *data, bool init)
{
	corewar_vis_render_button(rend, status, init);
	static_render_cycle(rend, data->cycle);
	static_render_nci(rend, data->cycle, data->ctc);
	static_render_lc(rend, data->n_live);
	static_render_pcs(rend, data->n_carrs);
}
