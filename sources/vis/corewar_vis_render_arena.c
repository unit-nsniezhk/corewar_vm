/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_arena.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 21:13:48 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void	static_render_value(t_vis *vis, SDL_Rect rect,
			unsigned char value, unsigned int bg_color)
{
	char			*text;
	unsigned int	brightness;

	rect.x += 1;
	rect.y += 1;
	rect.h = XS_CHAR_H - 1;
	rect.w = XS_CHAR_W - 1;
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

static void	static_render_bytes(t_vis *vis, t_data *data)
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
		if (vis->buttons.values.state && i < ARENA_SIZE)
			static_render_value(vis, rect, data->arena[i], vis->color[i]);
		++i;
	}
}

static void	static_render_carrs(t_vis *vis, t_data *data)
{
	t_carriage	*carr_tmp;
	SDL_Rect	rect;

	rect.w = BYTE_SIZE + (BYTE_SHADOW * 2);
	rect.h = BYTE_SIZE + (BYTE_SHADOW * 2);
	carr_tmp = data->carr;
	while (carr_tmp)
	{
		rect.x = ((carr_tmp->pos % N_COLUMNS) * (BYTE_SIZE + PAD)) + PAD
		- BYTE_SHADOW;
		rect.y = ((carr_tmp->pos / N_COLUMNS) * (BYTE_SIZE + PAD)) + PAD
		- BYTE_SHADOW;
		if (vis->buttons.reverse.state)
			SDL_SetRenderDrawColor(vis->rend, R(RGBA_RCARR), G(RGBA_RCARR),
			B(RGBA_RCARR), A(RGBA_RCARR));
		else
			SDL_SetRenderDrawColor(vis->rend, R(RGBA_CARR), G(RGBA_CARR),
			B(RGBA_CARR), A(RGBA_CARR));
		SDL_RenderFillRect(vis->rend, &rect);
		carr_tmp = carr_tmp->next;
	}
}

void		corewar_vis_render_arena(t_vis *vis, t_data *data)
{
	static_render_bytes(vis, data);
	static_render_carrs(vis, data);
}
