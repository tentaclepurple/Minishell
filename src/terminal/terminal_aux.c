/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:49:26 by josu              #+#    #+#             */
/*   Updated: 2023/10/31 13:11:08 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

int	ft_lines2(char *str, t_info *info, char ***res)
{
	str = ft_correct_str(str);
	if (!str)
		return (1);
	*res = ft_split_str(str, ' ');
	free (str);
	if (!(*res))
		return (2);
	if (ft_check_var(*res, info->envcp))
		return (ft_free_split(*res), 3);
	*res = ft_correc_special(*res, "<>|&");
	if (!(*res))
		return (3);
	return (0);
}

void	ft_open_outfiles(t_px *nodes)
{
	int	i;
	int	fd;

	i = 0;
	while (i < nodes->info->cmd_amount)
	{
		if (nodes[i].outfile)
		{
			fd = open(nodes[i].outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			close(fd);
		}
		i++;
	}
}
