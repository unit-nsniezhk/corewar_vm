/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_arena.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 21:44:33 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_byte(t_vis *vis, SDL_Rect *rect, unsigned int i)
{
	rect->x -= SHADOW_SIZE;
	rect->y -= SHADOW_SIZE;
	rect->w += SHADOW_SIZE * 2;
	rect->h += SHADOW_SIZE * 2;
	SDL_SetRenderDrawColor(vis->rend, (RGB_SHADOW >> 16) & 255,
	(RGB_SHADOW >> 8) & 255, RGB_SHADOW & 255, 255);
	SDL_RenderFillRect(vis->rend, rect);
	rect->x += SHADOW_SIZE;
	rect->y += SHADOW_SIZE;
	rect->w -= SHADOW_SIZE * 2;
	rect->h -= SHADOW_SIZE * 2;
	SDL_SetRenderDrawColor(vis->rend, (Uint8)((vis->color[i] >> 16) & 255),
	(Uint8)((vis->color[i] >> 8) & 255), (Uint8)(vis->color[i] & 255), 255);
	SDL_RenderFillRect(vis->rend, rect);
}

static void	static_render_bytes(t_vis *vis)
{
	unsigned int	row;
	unsigned int	column;
	unsigned int	i;
	SDL_Rect		rect;

	rect.h = BYTE_HEIGHT;
	rect.w = BYTE_WIDTH;
	row = 0;
	i = 0;
	while (i < ARENA_SIZE)
	{
		column = 0;
		rect.y = (ROW_HEIGHT * row) + BYTE_Y_PADD;
		while (column < N_COLUMNS)
		{
			rect.x = (COLUMN_WIDTH * column) + BYTE_X_PADD;
			static_render_byte(vis, &rect, i);
			++column;
			++i;
		}
		++row;
	}
}

static void	static_render_carr(t_vis *vis, SDL_Rect *rect, unsigned int color)
{
	rect->x -= SHADOW_SIZE;
	rect->y -= SHADOW_SIZE;
	rect->w += SHADOW_SIZE * 2;
	rect->h += SHADOW_SIZE * 2;
	SDL_SetRenderDrawColor(vis->rend, (Uint8)((color >> 16) & 255),
	(Uint8)((color >> 8) & 255), (Uint8)(color & 255), A_CARR);
	SDL_RenderFillRect(vis->rend, rect);
	rect->x += SHADOW_SIZE;
	rect->y += SHADOW_SIZE;
	rect->w -= SHADOW_SIZE * 2;
	rect->h -= SHADOW_SIZE * 2;
	SDL_SetRenderDrawColor(vis->rend, (Uint8)((RGB_CARR >> 16) & 255),
	(Uint8)((color >> 8) & 255), (Uint8)(color & 255), A_CARR);
	SDL_RenderFillRect(vis->rend, rect);
}

static void	static_render_carrs(t_vis *vis, t_data *data)
{
	t_carriage		*carriage_tmp;
	SDL_Rect		rect;
	unsigned int	color;

	rect.w = BYTE_WIDTH;
	rect.h = BYTE_HEIGHT;
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	carriage_tmp = data->carr;
	if (vis->select)
		color = RGB_CARR_SELECT;
	else
		color = RGB_CARR;
	while (carriage_tmp)
	{
		rect.x = ((carriage_tmp->pos % N_COLUMNS) * COLUMN_WIDTH) + BYTE_X_PADD;
		rect.y = ((carriage_tmp->pos / vis->n_rows) * ROW_HEIGHT) + BYTE_Y_PADD;
		static_render_carr(vis, &rect, color);
		carriage_tmp = carriage_tmp->next;
	}
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_NONE);
}

void		corewar_vis_render_arena(t_vis *vis, t_data *data)
{
	static_render_bytes(vis);
	static_render_carrs(vis, data);
}