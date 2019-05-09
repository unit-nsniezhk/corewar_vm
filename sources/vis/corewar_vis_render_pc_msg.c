/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_pc_msg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:10:09 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 19:06:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_op_def.h"
#include "libft.h"

void	corewar_vis_render_pc_id(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static int	w = 0;
	static char	*str = "Id";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->id);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_carry(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static int	w = 0;
	static char	*str = "Carry";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->carry);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_op(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static int	w = 0;
	static char	*str = "Operation";

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	if (carr->op > 0)
		corewar_vis_render_btext(rend, g_op_table[carr->op - 1].name,
		RGBA_TEXT2, (SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W,
		S_CHAR_H});
}

void	corewar_vis_render_pc_lastlive(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static int	w = 0;
	static char	*str = "Last live";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->last_live);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_timeout(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static int	w = 0;
	static char	*str = "Timeout";
	char		*value;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->timeout);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}


