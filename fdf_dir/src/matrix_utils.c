/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:47:30 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/09 19:47:35 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

double	**matrix_convert(double mat_li[4][4], double **mat)
{
	mat[0][0] = mat_li[0][0];
	mat[0][1] = mat_li[0][1];
	mat[0][2] = mat_li[0][2];
	mat[0][3] = mat_li[0][3];
	mat[1][0] = mat_li[1][0];
	mat[1][1] = mat_li[1][1];
	mat[1][2] = mat_li[1][2];
	mat[1][3] = mat_li[1][3];
	mat[2][0] = mat_li[2][0];
	mat[2][1] = mat_li[2][1];
	mat[2][2] = mat_li[2][2];
	mat[2][3] = mat_li[2][3];
	mat[3][0] = mat_li[3][0];
	mat[3][1] = mat_li[3][1];
	mat[3][2] = mat_li[3][2];
	mat[3][3] = mat_li[3][3];
	return (mat);
}

double	**matrix_unitize(double **mat)
{
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;
	mat[1][3] = 0;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
	return (mat);
}


void	matrix_copy(double mat_li[4][4], double **mat)
{
	mat_li[0][0] = mat[0][0];
	mat_li[0][1] = mat[0][1];
	mat_li[0][2] = mat[0][2];
	mat_li[0][3] = mat[0][3];
	mat_li[1][0] = mat[1][0];
	mat_li[1][1] = mat[1][1];
	mat_li[1][2] = mat[1][2];
	mat_li[1][3] = mat[1][3];
	mat_li[2][0] = mat[2][0];
	mat_li[2][1] = mat[2][1];
	mat_li[2][2] = mat[2][2];
	mat_li[2][3] = mat[2][3];
	mat_li[3][0] = mat[3][0];
	mat_li[3][1] = mat[3][1];
	mat_li[3][2] = mat[3][2];
	mat_li[3][3] = mat[3][3];
}

double	**make_matrix(void)
{
	double	**re;
	int		i;

	re = (double **)malloc(sizeof(double *) * 5);
	if (re == NULL)
		return (NULL);
	i = 0;
	re[4] = NULL;
	while (i++ < 4)
	{
		re[i - 1] = (double *)malloc(sizeof(double) * 4);
		if (re[i - 1] == NULL)
		{
			while (i-- < 0)
				free(re[i - 1]);
			return (NULL);
		}
	}
	return (re);
}

void	clear_matrix(double **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		free(mat[i++]);
	free(mat);
}
