#include "../miniRT.h"

t_vec *ft_crnewvec(float x, float y, float z) // malloc
{
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vec *ft_vesubtruct(t_vec *vec1, t_vec *vec2) // malloc
{
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	new->x = vec1->x - vec2->x;
	new->y = vec1->y - vec2->y;
	new->z = vec1->z - vec2->z;
	return (new);
}

t_vec *ft_vecsum(t_vec *vec1, t_vec *vec2)
{
	t_vec *new;
	
	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);	
	new->x = vec1->x + vec2->x;
	new->y = vec1->y + vec2->y;
	new->z = vec1->z + vec2->z;
	return (new);
}

t_vec *ft_vecmultiply(t_vec *vec1, float t) // malloc
{	
	t_vec *new;
	
	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);	
	new->x = vec1->x * t;
	new->y = vec1->y * t;
	new->z = vec1->z * t;
	return (new);
}

float ft_modulvec(t_vec *vec)
{
	float result;

	result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (result);
}


t_vec *ft_dublvec (t_vec *old)
{
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);		
	new->x = old->x;
	new->y = old->y;
	new->z = old->z;
	return (new);
}

void ft_create (t_vec *dst, float x, float y, float z)
{
	dst->x = x;
	dst->y = y;
	dst->z = z;
}

void ft_inversevec(t_vec *vec)
{
	vec->x = (vec->x == 0) ? 0 : vec->x * (-1);
	vec->y = (vec->y == 0) ? 0 : vec->y * (-1);
	vec->z = (vec->z == 0) ? 0 : vec->z * (-1);
}

void ft_zerovec(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}

void ft_equalize(t_vec *dir, t_vec srs)
{
	dir->x = srs.x;
	dir->y = srs.y;
	dir->z = srs.z;
}
t_list *ft_crnewlst()
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->s = 0;
	new->next = 0;
	new->str = 0;
	new->resolx = -1;
	new->resoly = -1;
	new->r = -1;
	new->g = -1;
	new->b = -1;
	new->ratio = -1;
	new->countcams = -1;
	new->fow = -1;
	new->diameter = -1;
	new->height = -1;
	new->sidesize = -1;

	return (new);
}

int ft_hardstrlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}