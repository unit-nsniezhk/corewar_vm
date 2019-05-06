/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_prop.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:43:40 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 22:03:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_PROP_H

# define COREWAR_VIS_PROP_H

# define ARENA_W 1505
# define N_COLUMNS 75
# define N_ROWS (ARENA_SIZE / N_COLUMNS)

# define BYTE_W 15
# define DIGIT_W 12
# define BYTE_H 15
# define BYTE_X_PADD 5
# define BYTE_Y_PADD 5
# define ROW_H (BYTE_H + BYTE_Y_PADD)
# define COLUMN_W (BYTE_W + BYTE_X_PADD)
# define SHADOW_SIZE 2

# define STATUS_X (ARENA_W + 30)
# define STATUS_Y 20
# define STATUS_W (WIN_WIDTH - ARENA_W - 60)
# define STATUS_H 50

# define LOW_BAR_Y 835
# define D_LOW_BAR 35
# define LOB_BAR_GAP 30
# define LOW_BAR_X (ARENA_W + 10)
# define LOW_BAR_W (WIN_WIDTH - ARENA_W - 215)
# define LOW_BAR_X1 (LOW_BAR_X + LOW_BAR_W + 15)
# define LOW_BAR_W1 (WIN_WIDTH - LOW_BAR_X1 - 5)
# define LOW_BAR_H 20

# define TOP_BAR_W (WIN_WIDTH - ARENA_W - 180)
# define TOP_BAR_X (ARENA_W + 5)
# define TOP_BAR_Y 100
# define TOP_BAR_X1 (TOP_BAR_X + TOP_BAR_W + 10)
# define D_TOP_BAR 30

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

#endif
