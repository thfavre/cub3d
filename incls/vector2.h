#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_fvector2
{
	float	x;
	float	y;
}	t_fvector2;

t_vector2	fvector2_to_vector2(t_fvector2 fvector2);
t_fvector2	vector2_to_fvector2(t_vector2 vector2);


#endif
