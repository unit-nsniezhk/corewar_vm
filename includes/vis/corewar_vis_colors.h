/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_colors.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:41:31 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 21:51:10 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_COLORS_H

# define COREWAR_VIS_COLORS_H

# include "SDL.h"

# define D_PRESS -20
# define D_HOWER 20

# define A(RGBA) (Uint8)((RGBA >> 24) & 255)
# define R(RGBA) (Uint8)((RGBA >> 16) & 255)
# define G(RGBA) (Uint8)((RGBA >> 8) & 255)
# define B(RGBA) (Uint8)(RGBA & 255)
# define P(COLOR) (Uint8)(abs(COLOR + D_PRESS) & 255)
# define H(COLOR) (Uint8)(abs(COLOR + D_HOWER) & 255)

# define HOWER(CLR) A(CLR) << 24 | H(R(CLR)) << 16 | H(G(CLR)) << 8 | H(B(CLR))
# define PRESS(CLR) A(CLR) << 24 | P(R(CLR)) << 16 | P(G(CLR)) << 8 | P(B(CLR))

# define RGBA_TEXT 0xFFC85A00
# define RGBA_TEXT2 0xFF5E5D5C

# define RGBA_BUTTON 0xAA3a3a3a

# define A_CARR 0x9F
# define RGBA_CARR (0x00B4B4B4 | (A_CARR << 24))
# define RGBA_RCARR (0x00AA4628 | (A_CARR << 24))

# define RGBA_BG 0xFF2B2B2B
# define RGBA_SHADOW 0xFF44454A

# define RGBA_VALUE_LIGHT 0xFFD2B4B4
# define RGBA_VALUE_DARK 0xFF141414

# define RGBA_PLAYER0 0xFF65655C
# define RGBA_PLAYER 0xFF78B42B
# define RGBA_PLAYER2 0xFF982D00
# define RGBA_PLAYER3 0xFF999900
# define RGBA_PLAYER4 0

static const unsigned int	g_color_table[MAX_PLAYERS + 1] =
{
	RGBA_PLAYER0,
	RGBA_PLAYER,
	RGBA_PLAYER2,
	RGBA_PLAYER3,
	RGBA_PLAYER4
};

#endif
