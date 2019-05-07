/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_arena.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 21:45:39 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void		static_render_value(t_vis *vis, SDL_Rect rect,
				unsigned char value, unsigned int bg_color)
{
	char			*text;
	unsigned int	brightness;

	rect.x += 1;
	rect.y += 1;
	rect.h -= 2;
	rect.w -= 2;
	brightness = (unsigned int)((R(bg_color) + G(bg_color) + B(bg_color)) / 3);
	text = ft_uitoabase(HEX, value);
	if (value < 16)
		ft_strninject(&text, "0", 0, 1);
	if (brightness > 100)
		corewar_vis_render_rtext(vis, text, RGBA_VALUE_DARK, &rect);
	else
		corewar_vis_render_rtext(vis, text, RGBA_VALUE_LIGHT, &rect);
	ft_strdel(&text);
}

static void	static_render_shadow(t_vis *vis, SDL_Rect rect)
{
	rect.x -= SHADOW_SIZE;
	rect.y -= SHADOW_SIZE;
	rect.w += (SHADOW_SIZE * 2);
	rect.h += (SHADOW_SIZE * 2);
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
	B(RGBA_SHADOW), A(RGBA_SHADOW));
	SDL_RenderFillRect(vis->rend, &rect);
}

static void	static_render_bytes(t_vis *vis, t_data *data)
{
	unsigned int	i;
	SDL_Rect		rect;
	unsigned int	color;

	rect.h = BYTE_H;
	rect.w = BYTE_W;
	i = 0;
	while (i < ARENA_SIZE || (i % N_COLUMNS))
	{
		rect.y = (ROW_H * (i / N_COLUMNS)) + BYTE_Y_PADD;
		rect.x = (COLUMN_W * (i % N_COLUMNS)) + BYTE_X_PADD;
		static_render_shadow(vis, rect);
		if (i < ARENA_SIZE)
			color = vis->color[i];
		else
			color = RGBA_PLAYER0;
		SDL_SetRenderDrawColor(vis->rend, R(color), G(color), B(color),
		A(color));
		SDL_RenderFillRect(vis->rend, &rect);
		if (vis->buttons.values.state && i < ARENA_SIZE)
			static_render_value(vis, rect, data->arena[i], vis->color[i]);
		++i;
	}
}

static void	static_render_carrs(t_vis *vis, t_data *data)
{
	t_carriage	*carriage_tmp;
	SDL_Rect	rect;

	rect.w = BYTE_W + (SHADOW_SIZE * 2);
	rect.h = BYTE_H + (SHADOW_SIZE * 2);
	carriage_tmp = data->carr;
	while (carriage_tmp)
	{
		rect.x = ((carriage_tmp->pos % N_COLUMNS) * COLUMN_W) + BYTE_X_PADD
		- SHADOW_SIZE;
		rect.y = ((carriage_tmp->pos / N_COLUMNS) * ROW_H) + BYTE_Y_PADD
		- SHADOW_SIZE;
		if (vis->buttons.reverse.state)
			SDL_SetRenderDrawColor(vis->rend, R(RGBA_RCARR), G(RGBA_RCARR),
			B(RGBA_RCARR), A(RGBA_RCARR));
		else
			SDL_SetRenderDrawColor(vis->rend, R(RGBA_CARR), G(RGBA_CARR),
			B(RGBA_CARR), A(RGBA_CARR));
		SDL_RenderFillRect(vis->rend, &rect);
		carriage_tmp = carriage_tmp->next;
	}
}

void		corewar_vis_render_arena(t_vis *vis, t_data *data)
{
	static_render_bytes(vis, data);
	static_render_carrs(vis, data);
}
