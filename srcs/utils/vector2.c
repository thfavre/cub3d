#include "vector2.h" // TODO where to put this file? // TODO delete this file (and functions in .h) if not used

t_vector2	fvector2_to_vector2(t_fvector2 fvector2)
{
	t_vector2	vector2;

	vector2.x = fvector2.x;
	vector2.y = fvector2.y;
	return (vector2);
}

t_fvector2	vector2_to_fvector2(t_vector2 vector2)
{
	t_fvector2	fvector2;

	fvector2.x = vector2.x;
	fvector2.y = vector2.y;
	return (fvector2);
}
