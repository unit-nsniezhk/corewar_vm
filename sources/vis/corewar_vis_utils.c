/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:45:39 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 18:59:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void			corewar_vis_render_btext(t_vis *vis, const char *message,
				unsigned int color, SDL_Rect box)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = TTF_RenderText_Blended(vis->fonts.bold, message,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_RenderCopy(vis->rend, texture, NULL, &box);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void			corewar_vis_render_rtext(t_vis *vis, const char *message,
				unsigned int color, SDL_Rect *box)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = TTF_RenderText_Blended(vis->fonts.regular, message,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	texture = SDL_CreateTextureFromSurface(vis->rend, surface);
	SDL_RenderCopy(vis->rend, texture, NULL, box);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


static void		static_render_bg(t_vis *vis, t_button *button,
				unsigned int bg_color)
{
	if (button->bg)
	{
		SDL_SetRenderDrawColor(vis->rend, R(bg_color), G(bg_color),
		B(bg_color), A(bg_color));
		SDL_RenderFillRect(vis->rend, &button->button_rect);
	}
}

static void		static_render_text(t_vis *vis, t_data *data, t_button *button,
				unsigned int text_color)
{
	char	*text;

	if (!data->cycle && button->init_text)
		text = button->init_text;
	else if (button->state && button->alt_text)
		text = button->alt_text;
	else
		text = button->text;
	corewar_vis_render_btext(vis, text, text_color, button->button_rect);
}

void			corewar_vis_render_button(t_vis *vis, t_data *data,
				t_button *button)
{
	unsigned int	bg_color;
	unsigned int	text_color;

	if (button->press)
	{
		text_color = PRESS(RGBA_TEXT);
		bg_color = PRESS(RGBA_BUTTON);
	}
	else if (button->hower)
	{
		bg_color = HOWER(RGBA_BUTTON);
		text_color = HOWER(RGBA_TEXT);
	}
	else
	{
		bg_color = RGBA_BUTTON;
		text_color = RGBA_TEXT;
	}
	static_render_bg(vis, button, bg_color);
	static_render_text(vis, data, button, text_color);
}
