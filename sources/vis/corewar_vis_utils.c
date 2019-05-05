/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:45:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:01:13 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void			corewar_vis_render_text(t_vis *vis, const char *text,
				SDL_Color color, TTF_Font *font)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = TTF_RenderText_Blended(font, text, color);
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_RenderCopy(vis->rend, texture, NULL, vis->ptr);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void			corewar_vis_render_value(t_vis *vis, SDL_Rect rect,
				unsigned char value, unsigned int bg_color)
{
	char			*text;
	unsigned int	brightness;

	rect.x += 1;
	rect.y += 1;
	rect.h -= 1;
	rect.w -= 1;
	vis->ptr = &rect;
	text = ft_uitoabase(HEX, value);
	if (value < 16)
		ft_strninject(&text, "0", 0, 1);
	brightness = (((bg_color >> 16) & 255) + ((bg_color >> 8) & 255)
	+ (bg_color & 255)) / 3;
	if (brightness > 127)
		corewar_vis_render_text(vis, text, g_dark, vis->fonts.regular);
	else
		corewar_vis_render_text(vis, text, g_light, vis->fonts.regular);
	ft_strdel(&text);
}

static Uint8	static_c(Uint8 color, int mod)
{
	Uint8	result;

	if (color + mod > 255)
		result = 255;
	else if (color + mod < 0)
		result = 0;
	else
		result = (Uint8)(color + mod);
	return (result);
}

void			corewar_vis_render_button(t_vis *vis, t_button *button)
{
	vis->ptr = &button->text_rect;
	if (button->bg)
	{
		if (button->press)
			SDL_SetRenderDrawColor(vis->rend,
			static_c(g_button_bg_color.r, D_PRESSED),
			static_c(g_button_bg_color.g, D_PRESSED),
			static_c(g_button_bg_color.b, D_PRESSED),
			g_button_bg_color.a);
		else if (button->hower)
			SDL_SetRenderDrawColor(vis->rend,
			static_c(g_button_bg_color.r, D_HOWERED),
			static_c(g_button_bg_color.g, D_HOWERED),
			static_c(g_button_bg_color.b, D_HOWERED), g_button_bg_color.a);
		else
			SDL_SetRenderDrawColor(vis->rend, g_button_bg_color.r,
			g_button_bg_color.g, g_button_bg_color.b, g_button_bg_color.a);
		SDL_RenderFillRect(vis->rend, &button->button_rect);
	}
	if (!button->pressed || !button->alt_text)
		corewar_vis_render_text(vis, button->text, g_button_text_color,
		vis->fonts.bold);
	else
		corewar_vis_render_text(vis, button->alt_text, g_button_text_color,
		vis->fonts.bold);
}
