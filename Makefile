NAME =		corewar
OBJS_PATH =	.object/
SRCS_PATH =	source/
INCS_PATH =	include/
CC =		clang
CFLAGS =	-Wall -Wextra -Werror -Ofast
RM =		rm -rf

COREWAR_INCS_PATH =	$(INCS_PATH)
COREWAR_INCS =		corewar.h \
					corewar_config.h \
					corewar_def.h
COREWAR_SRCS_PATH =	$(SRCS_PATH)
COREWAR_SRCS =		corewar.c \
					corewar_cycles.c \
					corewar_utils.c \
					corewar_vm.c
COREWAR_OBJS_PATH =	$(OBJS_PATH)
COREWAR_OBJS =		$(LIBFT_SRCS:%.c=$(LIBFT_OBJS_PATH)%.o)

VIS_INCS_PATH =	$(INCS_PATH)vis/
VIS_INCS =		corewar_vis.h \
				corewar_vis_color.h \
				corewar_vis_content.h \
				corewar_vis_def.h \
				corewar_vis_prop.h
VIS_SRCS_PATH =	$(SRCS_PATH)vis/
VIS_SRCS =		corewar_vis.c \
				corewar_vis_handle_utils.c \
				corewar_vis_handle_wheel.c \
				corewar_vis_init.c \
				corewar_vis_key_handle.c \
				corewar_vis_lock.c \
				corewar_vis_mods.c \
				corewar_vis_mods2.c \
				corewar_vis_motion_handle.c \
				corewar_vis_mouse_handle.c \
				corewar_vis_render_arena.c \
				corewar_vis_render_btmb.c \
				corewar_vis_render_mdlb.c \
				corewar_vis_render_pc.c \
				corewar_vis_render_pc_msg.c \
				corewar_vis_render_topb.c \
				corewar_vis_render_topb2.c \
				corewar_vis_render_utils.c
VIS_OBJS_PATH =	$(OBJS_PATH)vis/
VIS_OBJS =		$(LIBFT_SRCS:%.c=$(LIBFT_OBJS_PATH)%.o)