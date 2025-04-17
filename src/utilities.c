/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 03:20:12 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 05:38:59 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_before(char *str, int *i, int *before_dot)
{
	if (str[*i] == 43 || str[*i] == 45)
		(*i)++;
	if (str[*i] == 46)
		return (0);
	while (str[*i] && str[*i] != 46)
	{
		if (str[*i] >= 48 && str[*i] <= 57)
			*before_dot = 1;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	ft_check_after(char *str, int *i)
{
	int	after_dot;

	after_dot = 0;
	if (str[*i] == 46)
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] >= 48 && str[*i] <= 57)
				after_dot = 1;
			else
				return (0);
			(*i)++;
		}
	}
	return (after_dot || str[*i - 1] != 46);
}

static double	ft_parse_decimal(const char *str, int *i)
{
	double	multiplier;
	double	decimal;

	decimal = 0.0;
	multiplier = 10.0;
	if (str[*i] == 46)
	{
		(*i)++;
		while (str[*i] >= 48 && str[*i] <= 57)
		{
			decimal = decimal + (str[*i] - 48) / multiplier;
			multiplier *= 10.0;
			(*i)++;
		}
	}
	return (decimal);
}

int	ft_is_number(char *str)
{
	int	i;
	int	before_dot;

	i = 0;
	before_dot = 0;
	if (!ft_check_before(str, &i, &before_dot))
		return (0);
	if (str[i] == 46 && !before_dot)
		return (0);
	if (str[i] == 46 && !ft_check_after(str, &i))
		return (0);
	return (before_dot || str[i - 1] != 46);
}

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10.0 + (str[i] - 48);
		i++;
	}
	decimal = ft_parse_decimal(str, &i);
	return (sign * (result + decimal));
}
