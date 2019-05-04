/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_def.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:41:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 22:06:58 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_DEF_H

# define COREWAR_VIS_DEF_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "corewar_settings.h"

# define WIN_NAME "CoreWars"
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1105

# define ARENA_WIDTH 1505
# define N_COLUMNS 75
# define BYTE_WIDTH 15
# define BYTE_HEIGHT 15
# define BYTE_X_PADD 5
# define BYTE_Y_PADD 5
# define ROW_HEIGHT (BYTE_HEIGHT + BYTE_Y_PADD)
# define COLUMN_WIDTH (BYTE_WIDTH + BYTE_X_PADD)
# define SHADOW_SIZE 1

# define A_CARR 100
# define RGB_WHITE 16777215
# define RGB_RED 9972992
# define RGB_GREEN 7910443
# define RGB_BLUE 48569
# define RGB_GREY 6515312
# define RGB_SHADOW 4474186
# define RGB_YELLOW 10066176
# define RGB_ORANGE 1
# define RGB_BG 2829099
# define RGB_UNDEF RGB_WHITE
# define RGB_CARR RGB_WHITE
# define RGB_CARR_SELECT 12472383

# define STATUS_X (ARENA_WIDTH + 30)
# define STATUS_Y 20
# define STATUS_WIDTH (WIN_WIDTH - ARENA_WIDTH - 60)
# define STATUS_HEIGHT 50

# define CONTROLLERS_X (ARENA_WIDTH + 30)
# define CONTROLLERS_HEIGHT 150
# define CONTROLLERS_Y (WIN_HEIGHT - CONTROLLERS_HEIGHT - 5)
# define CONTROLLERS_WIDTH (WIN_WIDTH - ARENA_WIDTH - 30)

# define CYCLE_LEN 50
# define MAX_CYCLE_LEN 100
# define DELTA_CYCLE_LEN 10

typedef struct		s_keydown
{
	unsigned int	esk : 1;
	unsigned int	space : 1;
	unsigned int	lalt : 1;
}					t_keydown;

typedef struct		s_vis
{
	unsigned int	run : 1;
	unsigned int	quit : 1;
	unsigned int	select : 1;
	unsigned int	cycle_len;
	t_keydown		keydown;
	TTF_Font		*font;
	TTF_Font		*font_bold;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	unsigned int	n_rows;
	unsigned int	color[ARENA_SIZE];
}					t_vis;

static const unsigned int	g_color_table[MAX_PLAYERS] =
{
	RGB_YELLOW,
	RGB_GREEN,
	RGB_RED,
	RGB_ORANGE
};

#endif
