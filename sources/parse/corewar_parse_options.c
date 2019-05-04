/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse_options.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:02:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 22:20:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar_parse.h"

static int	static_option_n(t_parse *parse, const char *value)
{
	unsigned int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
		{
			ft_printf("[redError:~] %s [yellow%c~]\n",
			"Invalid symbol in -n's value", value[i]);
			return (0);
		}
		++i;
	}
	parse->pos = (unsigned int)ft_atouibase(DEC, value);
	if (parse->pos < MIN_CHAMPIONS || parse->pos > MAX_CHAMPIONS)
	{
		ft_printf("[redError:~] Invalid value of -n [yellowValue %u~]\n",
		parse->dump);
		return (0);
	}
	return (1);
}

static int	static_option_dump(t_parse *parse, const char *value)
{
	unsigned int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
		{
			ft_printf("[redError:~] %s [yellow%c~]\n",
			"Invalid symbol in -dump's value", value[i]);
			return (0);
		}
		++i;
	}
	if ((parse->dump = (unsigned int)ft_atouibase(DEC, value)) == 0)
	{
		ft_printf("[redError:~] Invalid value of -dump [yellowValue %u~]\n",
		parse->dump);
		return (0);
	}
	return (1);
}

static int	static_parse_options2(t_parse *parse, const char **argv,
			unsigned int *i)
{
	if (argv[*i][1] == 'v' && !argv[*i][2])
	{
		if (parse->vis)
		{
			ft_printf("[redError:~] %s [yellow%s~]\n",
			"Multiple specifications of the option", argv[*i]);
			return (0);
		}
		parse->vis = 1;
		--(*i);
	}
	else
	{
		ft_printf("[redError:~] %s [yellow%s~]\n",
		"Non existent option", argv[*i]);
		return (0);
	}
	return (1);
}

int			corewar_parse_options(t_parse *parse, const char **argv,
			unsigned int *i)
{
	if (argv[*i][1] == 'n' && !argv[*i][2])
	{
		if (parse->pos)
		{
			ft_printf("[redError:~] %s [yellow%u~]\n",
			"Player's number is already specified to", parse->pos);
			return (0);
		}
		if (!static_option_n(parse, argv[*i + 1]))
			return (0);
	}
	else if (ft_strncmp(&(argv[*i][1]), "dump", 5))
	{
		if (parse->dump)
		{
			ft_printf("[redError:~] %s [yellow%u~]\n",
			"-dump is already specified to", parse->dump);
			return (0);
		}
		if (!static_option_dump(parse, argv[*i + 1]))
			return (0);
	}
	else
		return (static_parse_options2(parse, argv, i));
	return (1);
}
