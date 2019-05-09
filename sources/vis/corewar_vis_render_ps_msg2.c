/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_ps_msg2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:33:15 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 19:21:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_op_def.h"
#include "libft.h"

static void	static_render_rg_value(SDL_Renderer *rend, t_carriage *carr,
			SDL_Rect *box, unsigned int i)
{
	static int	w = 0;
	static char	*str = "rg";
	char		*value;
	int			w_tmp;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box->x, box->y, XS_CHAR_W, S_CHAR_H});
	value = ft_itoabase(DEC, i);
	corewar_vis_render_btext(rend, value, RGBA_TEXT,
	(SDL_Rect){box->x + (w * XS_CHAR_W), box->y, XS_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
	w_tmp = w + (Sint32)ft_nbrlen(i, 10);
	if (i <= 9)
		++w_tmp;
	value = ft_itoabase(DEC, carr->regs[i]);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box->x + (w_tmp * XS_CHAR_W) + PAD, box->y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_pc_regs(SDL_Renderer *rend, t_carriage *carr,
			SDL_Rect box)
{
	static int		w;
	static char		*str = "Registers:";
	unsigned int	i;

	if (!w)
		w = (int)ft_strlen(str);
	corewar_vis_render_btext(rend, str, RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	box.x += PAD;
	box.y += S_CHAR_H;
	i = 1;
	while (i <= N_REGS)
	{
		static_render_rg_value(rend, carr, &box, i);
		box.y += S_CHAR_H;
		++i;
	}
}
