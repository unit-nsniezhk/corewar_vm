/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_text.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:54:10 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_vis_render_btext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box)
{
	SDL_Surface		*surf;
	SDL_Texture		*txtr;
	static TTF_Font	*font = NULL;

	if (!font)
		font = TTF_OpenFont(FONT_BOLD, 60);
	box.w *= ft_strlen(msg);
	surf = TTF_RenderText_Blended(font, msg,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	txtr = SDL_CreateTextureFromSurface(rend, surf);
	SDL_RenderCopy(rend, txtr, NULL, &box);
	SDL_DestroyTexture(txtr);
	SDL_FreeSurface(surf);
}

void	corewar_vis_render_rtext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box)
{
	SDL_Surface		*surf;
	SDL_Texture		*txtr;
	static TTF_Font	*font = NULL;

	if (!font)
		font = TTF_OpenFont(FONT_REG, 30);
	box.w *= ft_strlen(msg);
	surf = TTF_RenderText_Blended(font, msg,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	txtr = SDL_CreateTextureFromSurface(rend, surf);
	SDL_RenderCopy(rend, txtr, NULL, &box);
	SDL_DestroyTexture(txtr);
	SDL_FreeSurface(surf);
}

