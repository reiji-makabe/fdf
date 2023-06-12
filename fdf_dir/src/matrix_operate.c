/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:56:25 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/11 13:23:55 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

double	**zoom_matrix(double **mat, double magnifi_x, double magnifi_y)
{
	mat[0][0] *= magnifi_x;
	mat[0][1] *= magnifi_x;
	mat[0][2] *= magnifi_x;
	mat[0][3] *= magnifi_x;
	mat[1][0] *= magnifi_y;
	mat[1][1] *= magnifi_y;
	mat[1][2] *= magnifi_y;
	mat[1][3] *= magnifi_y;
	return (mat);
}

/* mat = {{1, 0, 0, x},
		  {0, 1, 0, y},
		  {0, 0, 1, 0},
		  {0, 0, 0, 1}}; */
double	**move_matrix(double **mat, double x, double y)
{
	mat[0][3] = mat[0][0] * x + mat[0][1] * y + mat[0][3];
	mat[1][3] = mat[1][0] * x + mat[1][1] * y + mat[1][3];
	mat[2][3] = mat[2][0] * x + mat[2][1] * y + mat[2][3];
	mat[3][3] = mat[3][0] * x + mat[3][1] * y + mat[3][3];
	return (mat);
}

/* mat = {cos(rad), -sin(rad), 0, 0}
 * 		 {sin(rad),  cos(rad), 0, 0}
 * 		 {		 0,			0, 1, 0}
 * 		 {		 0,			0, 0, 1} */
double	**z_rotate_matrix(double **mat, int degree)
{
	double	rad;
	double	mat_c[4][4];

	matrix_copy(mat_c, mat);
	rad = degree * (M_PI / 180);
	mat[0][0] = mat_c[0][0] * cos(rad) + mat_c[0][1] * sin(rad);
	mat[0][1] = mat_c[0][0] * -sin(rad) + mat_c[0][1] * cos(rad);
	mat[1][0] = mat_c[1][0] * cos(rad) + mat_c[1][1] * sin(rad);
	mat[1][1] = mat_c[1][0] * -sin(rad) + mat_c[1][1] * cos(rad);
	mat[2][0] = mat_c[2][0] * cos(rad) + mat_c[2][1] * sin(rad);
	mat[2][1] = mat_c[2][0] * -sin(rad) + mat_c[2][1] * cos(rad);
	mat[3][0] = mat_c[3][0] * cos(rad) + mat_c[3][1] * sin(rad);
	mat[3][1] = mat_c[3][0] * -sin(rad) + mat_c[3][1] * cos(rad);
	return (mat);
}
