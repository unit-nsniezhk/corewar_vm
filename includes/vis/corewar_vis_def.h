/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_def.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:41:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:03:54 by dderevyn         ###   ########.fr       */
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
# define RGB_GREY 8355711
# define RGB_SHADOW 4474186
# define RGB_YELLOW 10066176
# define RGB_ORANGE 1
# define RGB_BG 2829099
# define RGB_UNDEF RGB_WHITE
# define RGB_CARR RGB_WHITE
# define RGB_CARR_SELECT 12472383
# define RGB_DARK 1310740
# define RGB_LIGHT 15132390

# define STATUS_X (ARENA_WIDTH + 30)
# define STATUS_Y 20
# define STATUS_W (WIN_WIDTH - ARENA_WIDTH - 60)
# define STATUS_H 50

# define LOW_BAR_Y 815
# define D_LOW_BAR 35
# define LOB_BAR_GAP 50
# define LOW_BAR_X (ARENA_WIDTH + 10)
# define LOW_BAR_W (WIN_WIDTH - ARENA_WIDTH - 215)
# define LOW_BAR_X1 (LOW_BAR_X + LOW_BAR_W + 25)
# define LOW_BAR_W1 (WIN_WIDTH - LOW_BAR_X1 - 5)
# define LOW_BAR_H 20

# define INF_POS 0
# define INF_Y (LOW_BAR_Y + (D_LOW_BAR * INF_POS))

# define SPEEDUP_POS 1
# define SPEEDUP_Y (LOW_BAR_Y + (D_LOW_BAR * SPEEDUP_POS))

# define SLOWDOWN_POS 2
# define SLOWDOWN_Y (LOW_BAR_Y + (D_LOW_BAR * SLOWDOWN_POS))

# define VALUES_POS 3
# define VALUES_Y (LOW_BAR_Y + (D_LOW_BAR * VALUES_POS) + LOB_BAR_GAP)

# define REVERSE_POS 4
# define REVERSE_Y (LOW_BAR_Y + (D_LOW_BAR * REVERSE_POS) + LOB_BAR_GAP)

# define PAUSE_POS 5
# define PAUSE_Y (LOW_BAR_Y + (D_LOW_BAR * PAUSE_POS) + LOB_BAR_GAP)

# define EXIT_POS 6
# define EXIT_Y (LOW_BAR_Y + (D_LOW_BAR * EXIT_POS) + LOB_BAR_GAP)

# define BUTTON_W 10
# define BUTTON_H 5

# define D_PRESSED -50
# define D_HOWERED 50

# define CYCLE_LEN 50
# define MAX_CYCLE_LEN 100
# define DELTA_CYCLE_LEN 10

typedef struct		s_keydown
{
	unsigned int	esk : 1;
	unsigned int	space : 1;
	unsigned int	lalt : 1;
	unsigned int	f : 1;
	unsigned int	mbl : 1;
}					t_keydown;

typedef	struct		s_button
{
	unsigned int	press : 1;
	unsigned int	hower : 1;
	unsigned int	pressed : 1;
	char			*text;
	char			*alt_text;
	SDL_Rect		text_rect;
	unsigned int	bg : 1;
	SDL_Rect		button_rect;
}					t_button;

typedef struct		s_buttons
{
	t_button		status;
	t_button		speedup;
	t_button		slowdown;
	t_button		pause;
	t_button		exit;
	t_button		reverse;
	t_button		values;
}					t_buttons;

typedef struct		s_mods
{
	unsigned int	run : 1;
	unsigned int	quit : 1;
	unsigned int	reverse : 1;
	unsigned int	values : 1;
}					t_mods;

typedef struct		s_fonts
{
	TTF_Font		*bold;
	TTF_Font		*regular;
}					t_fonts;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	unsigned int	cycle_len;
	unsigned int	n_rows;
	unsigned int	color[ARENA_SIZE];
	t_buttons		buttons;
	t_mods			mods;
	t_keydown		keydown;
	t_fonts			fonts;
	SDL_Rect		*ptr;
}					t_vis;

static const unsigned int	g_color_table[MAX_PLAYERS] =
{
	RGB_YELLOW,
	RGB_GREEN,
	RGB_RED,
	RGB_ORANGE
};

static const SDL_Color		g_red =
		{
				(RGB_RED >> 16) & 255,
				(RGB_RED >> 8) & 255,
				RGB_RED & 255,
				255
		};

static const SDL_Color		g_yellow =
		{
				(RGB_YELLOW >> 16) & 255,
				(RGB_YELLOW >> 8) & 255,
				RGB_YELLOW & 255,
				255
		};

static const SDL_Color		g_dark =
		{
				(RGB_DARK >> 16) & 255,
				(RGB_DARK >> 8) & 255,
				RGB_DARK & 255,
				255
		};

static const SDL_Color		g_light =
		{
				(RGB_LIGHT >> 16) & 255,
				(RGB_LIGHT >> 8) & 255,
				RGB_LIGHT & 255,
				255
		};

static const SDL_Color		g_button_bg_color =
		{
				(RGB_GREY >> 16) & 255,
				(RGB_GREY >> 8) & 255,
				RGB_GREY & 255,
				100
		};

static const SDL_Color		g_button_text_color =
		{
				(RGB_RED >> 16) & 255,
				(RGB_RED >> 8) & 255,
				RGB_RED & 255,
				255
		};

#endif
