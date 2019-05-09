/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_topb2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:03:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 21:06:58 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

//static void	static_render_cycle(SDL_Renderer *rend, int cycle)
//{
//	static int	w = 0;
//	static char *str = "Forced check";
//	char		*value;
//	int			tmp;
//
//	if (!w)
//		w = (int)ft_strlen(str);
//	corewar_vis_render_btext(rend, str, RGBA_TEXT2,
//	(SDL_Rect){BAR_X, TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
//	value = ft_itoabase(DEC, n_live);
//	tmp = (n_live < MIN_LIVE ? RGBA_TEXT3 : RGBA_TEXTS);
//	corewar_vis_render_btext(rend, value, (unsigned int)tmp,
//	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
//	ft_strdel(&value);
//	tmp = (int)ft_nbrlen(n_live, 10);
//	corewar_vis_render_btext(rend, "/", RGBA_TEXT2,
//	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2) + (S_CHAR_W * tmp),
//	TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
//	value = ft_itoabase(DEC, MIN_LIVE);
//	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
//	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 3) + (S_CHAR_W * (tmp + 1)),
//	TOP_BAR_Y(3), S_CHAR_W, M_CHAR_H});
//	ft_strdel(&value);
//}
