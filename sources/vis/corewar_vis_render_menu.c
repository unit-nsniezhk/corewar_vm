/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_menu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 22:22:46 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_status(t_vis *vis)
{
	static SDL_Color	color =
	{
			(RGB_RED >> 16) & 255,
			(RGB_RED >> 8) & 255,
			RGB_RED & 255,
			255
	};
	static SDL_Rect		box =
	{
			STATUS_X,
			STATUS_Y,
			STATUS_WIDTH,
			STATUS_HEIGHT
	};
	SDL_Surface			*surface;
	SDL_Texture			*texture;

	if (vis->run)
		surface = TTF_RenderText_Solid(vis->font_bold, "CoreWars", color);
	else
		surface = TTF_RenderText_Solid(vis->font_bold, "Pause", color);
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_RenderCopy(vis->rend, texture, NULL, &box);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

static void	static_render_controlers(t_vis *vis)
{
	static SDL_Color	color =
			{
					(RGB_YELLOW >> 16) & 255,
					(RGB_YELLOW >> 8) & 255,
					RGB_YELLOW & 255,
					255
			};
	static SDL_Rect		box =
			{
					CONTROLLERS_X,
					CONTROLLERS_Y,
					CONTROLLERS_WIDTH,
					CONTROLLERS_HEIGHT
			};
	SDL_Surface			*surface;
	SDL_Texture			*texture;

	surface = TTF_RenderText_Blended_Wrapped(vis->font, "Select carriages      Hold LALT key & press SPACE    \nSpeedUp               Hold LALT key & mousewheel up  \\n", color, 53);
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_RenderCopy(vis->rend, texture, NULL, &box);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}
//SlowDown              Hold LALT key & mousewheel down\nPause / UnPause                           Press SPACE\n                                          ESC to exit"
void		corewar_vis_render_menu(t_vis *vis, t_data *data)
{
	static SDL_Rect	rect =
	{
			ARENA_WIDTH,
			WIN_HEIGHT,
			WIN_WIDTH - ARENA_WIDTH,
			0
	};

	SDL_SetRenderDrawColor(vis->rend, (RGB_SHADOW >> 16) & 255,
	(RGB_SHADOW >> 8) & 255, RGB_SHADOW & 255, 255);
	SDL_RenderFillRect(vis->rend, &rect);
	static_render_status(vis);
	static_render_controlers(vis);
}


