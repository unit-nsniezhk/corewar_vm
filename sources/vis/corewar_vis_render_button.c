/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_button.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:45:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 19:52:37 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void		static_color(t_button *btn, unsigned int *msg_color,
			unsigned int *bg_color)
{
	int	mod;

	*msg_color = RGBA_TEXT;
	*bg_color = RGBA_BUTTON;
	if (btn->press)
		mod = PRESS;
	else if (btn->hower)
		mod = HOWER;
	else
		return ;
	*msg_color = A(*msg_color) << 24
	| (Uint8)((R(*msg_color) + mod) & 255) << 16
	| (Uint8)((G(*msg_color) + mod) & 255) << 8
	| (Uint8)((B(*msg_color) + mod) & 255);
	*bg_color = A(*bg_color) << 24
	| (Uint8)((R(*bg_color) + mod) & 255) << 16
	| (Uint8)((G(*bg_color) + mod) & 255) << 8
	| (Uint8)((B(*bg_color) + mod) & 255);
}

void		corewar_vis_render_button(SDL_Renderer *rend, t_button *btn,
			bool init)
{
	char			*msg;
	SDL_Rect		box;
	unsigned int	msg_color;
	unsigned int	bg_color;

	static_color(btn, &msg_color, &bg_color);
	if (btn->bg_shown)
	{
		SDL_SetRenderDrawColor(rend, R(bg_color), G(bg_color),
		B(bg_color), A(bg_color));
		SDL_RenderFillRect(rend, &btn->bg);
	}
	if (init && btn->init_msg)
		msg = btn->init_msg;
	else if (btn->active && btn->alt_msg)
		msg = btn->alt_msg;
	else
		msg = btn->msg;
	box.w = MESSAGE_W(btn->bg.h);
	box.h = MESSAGE_H(btn->bg.h);
	box.x = btn->bg.x + BUTTON_MSG_X(btn->bg.w, box.w * (Sint32)ft_strlen(msg));
	box.y = btn->bg.y + BUTTON_MSG_Y(btn->bg.h, box.h);
	corewar_vis_render_btext(rend, msg, msg_color, box);
}
