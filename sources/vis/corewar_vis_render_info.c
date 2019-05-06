/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:27:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 18:11:52 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_vis_render_inf_value(t_vis *vis, SDL_Rect value_box,
		unsigned int value, unsigned int delta_x)
{
	char	*text;
	size_t	value_len;

	value_len = ft_unbrlen(value, 10);
	value_box.w = (Uint32)(DIGIT_W * value_len);
	value_box.x += delta_x;
	text = ft_uitoabase(DEC, value);
	corewar_vis_render_btext(vis, text, RGBA_TEXT, &value_box);
	ft_strdel(&text);
}

static void	static_render_inf(t_vis *vis, t_data *data, SDL_Rect *text_box)
{
	corewar_vis_render_btext(vis, "Cycle          ", RGBA_TEXT2, text_box);
	corewar_vis_render_inf_value(vis, *text_box, data->cycle, 65);
	text_box->y += D_TOP_BAR;
	corewar_vis_render_btext(vis, "Processes     ", RGBA_TEXT2, text_box);
	corewar_vis_render_inf_value(vis, *text_box, data->n_carrs, 95);
	text_box->y += D_TOP_BAR;
	corewar_vis_render_btext(vis, "Next check in ", RGBA_TEXT2, text_box);
	corewar_vis_render_inf_value(vis, *text_box,
	(unsigned int)data->cycles_to_check, 115);
	text_box->y += D_TOP_BAR;
	corewar_vis_render_btext(vis, "Lives casted  ", RGBA_TEXT2, text_box);
	corewar_vis_render_inf_value(vis, *text_box, data->n_live, 110);
}


void	corewar_vis_render_info(t_vis *vis, t_data *data)
{
	SDL_Rect	text_box;

	text_box.y = TOP_BAR_Y;
	text_box.x = TOP_BAR_X;
	text_box.w = TOP_BAR_W;
	text_box.h = LOW_BAR_H;
	static_render_inf(vis, data, &text_box);
}
