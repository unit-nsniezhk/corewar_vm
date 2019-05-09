/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_arena.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 20:32:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void	static_render_value(t_vis *vis, SDL_Rect rect, unsigned char value,
			unsigned int bg_color)
{
	char			*text;
	unsigned int	brightness;

	rect.x += 1;
	rect.y += 1;
	rect.h = XS_CHAR_H;
	rect.w = XS_CHAR_W;
	brightness = (unsigned int)((R(bg_color) + G(bg_color) + B(bg_color)) / 3);
	text = ft_uitoabase(HEX, value);
	if (value < 16)
		ft_strninject(&text, "0", 0, 1);
	if (brightness > 100)
		corewar_vis_render_rtext(vis->rend, text, RGBA_VALUE_DARK, rect);
	else
		corewar_vis_render_rtext(vis->rend, text, RGBA_VALUE_LIGHT, rect);
	ft_strdel(&text);
}

static void	static_render_shadow(t_vis *vis, SDL_Rect rect)
{
	rect.x -= BYTE_SHADOW;
	rect.y -= BYTE_SHADOW;
	rect.w += (BYTE_SHADOW * 2);
	rect.h += (BYTE_SHADOW * 2);
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
	B(RGBA_SHADOW), A(RGBA_SHADOW));
	SDL_RenderFillRect(vis->rend, &rect);
}

void	corewar_vis_render_arena(t_vis *vis, t_data *data)
{
	unsigned int	i;
	SDL_Rect		rect;
	unsigned int	color;

	rect.h = BYTE_SIZE;
	rect.w = BYTE_SIZE;
	i = 0;
	while (i < ARENA_SIZE || (i % N_COLUMNS))
	{
		rect.y = ((BYTE_SIZE + PAD) * (i / N_COLUMNS)) + PAD;
		rect.x = ((BYTE_SIZE + PAD) * (i % N_COLUMNS)) + PAD;
		static_render_shadow(vis, rect);
		if (i < ARENA_SIZE)
			color = vis->color[i];
		else
			color = RGBA_PLAYER0;
		SDL_SetRenderDrawColor(vis->rend, R(color), G(color), B(color),
		A(color));
		SDL_RenderFillRect(vis->rend, &rect);
		if (vis->buttons.values.active && i < ARENA_SIZE)
			static_render_value(vis, rect, data->arena[i], vis->color[i]);
		++i;
	}
}
