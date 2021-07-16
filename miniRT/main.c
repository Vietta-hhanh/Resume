#include "miniRT.h"

int ft_errormanage(int code)
{
	if (code == -1)
		write(1, WRONGSAVE, sizeof(WRONGSAVE));
	if (code == -2)
		write(1, WRONGFILE, sizeof(WRONGFILE));
	if (code == -3)
		write(1, WRONGNUMFILES, sizeof(WRONGNUMFILES));
	if (code == -4)
		write(1, FILEDNTEXIST, sizeof(FILEDNTEXIST));
	if (code == -5)
		write(1, MALLOCCRASH, sizeof(MALLOCCRASH));
	if (code == -6)
		write(1, WRONGAMOUNTWORD, sizeof(WRONGAMOUNTWORD));
	if (code == -7)
		write(1, ALOTUPPERSETTING, sizeof(ALOTUPPERSETTING));
	if (code == -8)
		write(1, NOTENOUGHSETTS, sizeof(NOTENOUGHSETTS));
	if (code == -9)
		write(1, WRONGVALUE, sizeof(WRONGVALUE));
	exit (-1);
}

int ft_void(t_list *ptrlist, int *countcams, int *counta, int *countr)
{
	int i = 0;
	char **buf;

	while ((ptrlist->str) && (ptrlist->str)[i] == ' ')
		i++;
	if ((ptrlist->str)[i] == 'p' && (ptrlist->str)[i + 1] == 'l')
	{
		buf = ft_split(&((ptrlist->str)[i + 2]), ' ', ',');
		if (ft_hardstrlen(buf) != 9)
			ft_errormanage (-6);
		ptrlist->r = ft_atoi(buf[6]);
		ptrlist->g = ft_atoi(buf[7]);
		ptrlist->b = ft_atoi(buf[8]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 5;
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ft_create(&ptrlist->cornorm, ft_float(buf[3]), ft_float(buf[4]), ft_float(buf[5]));
		if (fabsf(ptrlist->cornorm.x) > 1 || fabsf(ptrlist->cornorm.y) > 1 || fabsf(ptrlist->cornorm.z) > 1 )
			ft_errormanage(-9);
	
	}
	else if ((ptrlist->str)[i] == 's' && (ptrlist->str)[i + 1] == 'p')
	{
		buf = ft_split(&((ptrlist->str)[i + 2]), ' ', ',');
		if (ft_hardstrlen(buf) != 7)
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ptrlist->diameter = ft_float(buf[3]);
		ptrlist->r = ft_atoi(buf[4]);
		ptrlist->g = ft_atoi(buf[5]);
		ptrlist->b = ft_atoi(buf[6]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 6;
	}
	else if ((ptrlist->str)[i] == 's' && (ptrlist->str)[i + 1] == 'q')
	{
		buf = ft_split(&((ptrlist->str)[i + 2]), ' ', ',');
		if (ft_hardstrlen(buf) != 10)
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ft_create(&ptrlist->cornorm, ft_float(buf[3]), ft_float(buf[4]), ft_float(buf[5]));
		if (fabsf(ptrlist->cornorm.x) > 1 || fabsf(ptrlist->cornorm.y) > 1 || fabsf(ptrlist->cornorm.z) > 1 )
			ft_errormanage(-9);
		ptrlist->sidesize = ft_float(buf[6]);
		ptrlist->r = ft_atoi(buf[7]);
		ptrlist->g = ft_atoi(buf[8]);
		ptrlist->b = ft_atoi(buf[9]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 7;

	}
	else if ((ptrlist->str)[i] == 'c' && (ptrlist->str)[i + 1] == 'y')
	{
		buf = ft_split(&((ptrlist->str)[i + 2]), ' ', ',');
		if (ft_hardstrlen(buf) != 11) 
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ft_create(&ptrlist->cornorm, ft_float(buf[3]), ft_float(buf[4]), ft_float(buf[5]));
		if (fabsf(ptrlist->cornorm.x) > 1 || fabsf(ptrlist->cornorm.y) > 1 || fabsf(ptrlist->cornorm.z) > 1 )
			ft_errormanage(-9);
		ptrlist->diameter = ft_float(buf[6]);
		ptrlist->height = ft_float(buf[7]);
		ptrlist->r = ft_atoi(buf[8]);
		ptrlist->g = ft_atoi(buf[9]);
		ptrlist->b = ft_atoi(buf[10]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 8;
	}
	else if ((ptrlist->str)[i] == 't' && (ptrlist->str)[i + 1] == 'r')
	{
		buf = ft_split(&((ptrlist->str)[i + 2]), ' ', ',');
		if (ft_hardstrlen(buf) != 12) 
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ft_create(&ptrlist->cor2, ft_float(buf[3]), ft_float(buf[4]), ft_float(buf[5]));
		ft_create(&ptrlist->cor3, ft_float(buf[6]), ft_float(buf[7]), ft_float(buf[8]));
		ptrlist->r = ft_atoi(buf[9]);
		ptrlist->g = ft_atoi(buf[10]);
		ptrlist->b = ft_atoi(buf[11]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 9;
	}
	else if ((ptrlist->str)[i] == 'R')
	{
		buf = ft_split(&((ptrlist->str)[i + 1]), ' ', ',');
		if (ft_hardstrlen(buf) != 2)
			ft_errormanage (-6);
		(*countr)++;
		ptrlist->resolx = ft_atoi(buf[0]);
		ptrlist->resoly = ft_atoi(buf[1]);
		ptrlist->s = 1;	
	}
	else if ((ptrlist->str)[i] == 'A')
	{
		buf = ft_split(&((ptrlist->str)[i + 1]), ' ', ',');
		if (ft_hardstrlen(buf) != 4) 
			ft_errormanage (-6);
		(*counta)++;
		ptrlist->ratio = ft_float(buf[0]);
		if (ptrlist->ratio < 0 || ptrlist->ratio > 1)
			ft_errormanage(-9);
		ptrlist->r = ft_atoi(buf[1]);
		ptrlist->g = ft_atoi(buf[2]);
		ptrlist->b = ft_atoi(buf[3]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		ptrlist->s = 2;
	}
	else if ((ptrlist->str)[i] == 'c')
	{
		buf = ft_split(&((ptrlist->str)[i + 1]), ' ', ',');
		if (ft_hardstrlen(buf) != 7) 
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ft_create(&ptrlist->cornorm, ft_float(buf[3]), ft_float(buf[4]), ft_float(buf[5]));
		if (fabsf(ptrlist->cornorm.x) > 1 || fabsf(ptrlist->cornorm.y) > 1 || fabsf(ptrlist->cornorm.z) > 1 )
			ft_errormanage(-9);
		ptrlist->fow = ft_atoi(buf[6]);
		if (ptrlist->fow < 0 || ptrlist->fow > 180)
			ft_errormanage(-9);
		ptrlist->countcams = *countcams;
		(*countcams)++;
		ptrlist->s = 3;
	}
	else if ((ptrlist->str)[i] == 'l')
	{
		buf = ft_split(&((ptrlist->str)[i + 1]), ' ', ',');
		if (ft_hardstrlen(buf) != 7) 
			ft_errormanage (-6);
		ft_create(&ptrlist->cor1, ft_float(buf[0]), ft_float(buf[1]), ft_float(buf[2]));
		ptrlist->ratio = ft_float(buf[3]);
		ptrlist->r = ft_atoi(buf[4]);
		ptrlist->g = ft_atoi(buf[5]);
		ptrlist->b = ft_atoi(buf[6]);
		if (ptrlist->r > 255 || ptrlist->r < 0 || ptrlist->g > 255 || ptrlist->g < 0 || ptrlist->b > 255 || ptrlist->b < 0)
			ft_errormanage(-9);
		if (ptrlist->ratio < 0 || ptrlist->ratio > 1)
			ft_errormanage(-9);
		ptrlist->s = 4;

	}
	else
		ft_errormanage (-6);
	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free (buf);
	free (ptrlist->str);	
	return (0);
}

void ft_rootcopyhelp1(t_list *buffer, t_list *ptrlist)
{
	if (buffer->s == 1)
	{
		ptrlist->resolx = buffer->resolx;
		ptrlist->resoly = buffer->resoly;
		ptrlist->s = 1;	
	}
	if (buffer->s == 2)
	{
		ptrlist->ratio = buffer->ratio;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 2;
	}
	if (buffer-> s == 3)
	{
		ptrlist->countcams = buffer->countcams;
		ptrlist->cor1 = buffer->cor1;
		ptrlist->cornorm = buffer->cornorm;
		ptrlist->fow = buffer->fow;
		ptrlist->s = 3;
	}
}

void ft_rootcopyhelp2(t_list *buffer, t_list *ptrlist)
{
	if (buffer-> s == 4)
	{
		ptrlist->cor1 = buffer->cor1;
		ptrlist->ratio = buffer->ratio;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 4;
	}
	if (buffer-> s == 5)
	{
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 5;
		ptrlist->cor1 = buffer->cor1;
		ptrlist->cornorm = buffer->cornorm;
	}
}

void ft_rootcopyhelp3(t_list *buffer, t_list *ptrlist)
{
	if (buffer-> s == 6)
	{
		ptrlist->cor1 = buffer->cor1;
		ptrlist->diameter = buffer->diameter;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 6;
	}
	if (buffer-> s == 7)
	{
		ptrlist->cor1 = buffer->cor1;
		ptrlist->cornorm = buffer->cornorm;
		ptrlist->sidesize = buffer->sidesize;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 7;
	}
}

void ft_rootcopyhelp4(t_list *buffer, t_list *ptrlist)
{
	if (buffer-> s == 8)
	{
		ptrlist->cor1 = buffer->cor1;
		ptrlist->cornorm = buffer->cornorm;
		ptrlist->diameter = buffer->diameter;
		ptrlist->height = buffer->height;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 8;
	}
	if (buffer-> s == 9)
	{
		ptrlist->cor1 = buffer->cor1;
		ptrlist->cor2 = buffer->cor2;
		ptrlist->cor3 = buffer->cor3;
		ptrlist->r = buffer->r;
		ptrlist->g = buffer->g;
		ptrlist->b = buffer->b;
		ptrlist->s = 9;
	}
}

t_list *ft_rootcopy(t_list *root)
{
	t_list *buffer;
	t_list *newroot;
	t_list *ptrlist;
	int i;

	buffer = root;
	i = 1;
	newroot = ft_crnewlst();
	ptrlist = newroot;
	while (buffer)
	{
		if (i == 0)
		{
			ptrlist->next = ft_crnewlst();
			ptrlist = ptrlist->next;
		}
		i = 0;
		ft_rootcopyhelp1(buffer, ptrlist);
		ft_rootcopyhelp2(buffer, ptrlist);
		ft_rootcopyhelp3(buffer, ptrlist);
		ft_rootcopyhelp4(buffer, ptrlist);
		buffer = buffer->next;
	}
	return (newroot);
}

void ft_parser(t_list *root)
{
	t_list *ptrlist;
	int count;
	int counta;
	int countr;

	count = 1;
	counta = 0;
	countr = 0;
	ptrlist = root;
	
	while(ptrlist)
	{
		ft_void(ptrlist, &count, &counta, &countr);
		if (counta > 1 || countr > 1)
			ft_errormanage(-7);
		ptrlist = ptrlist->next;
	}
	if (countr == 0 || counta == 0)
		ft_errormanage(-8);
}

t_list *ft_crsequence(int fd)
{
	t_list *ptrlist;
	t_list *root;
	t_list *buffer;
	int checker;
	char *str;

	if ((root = ft_crnewlst()) == 0)
		ft_errormanage(-5);
	ptrlist = root;
	checker = 1;
	while (checker >= 0)
	{
		checker = get_next_line(fd, &ptrlist->str);
		if (checker == 0)
		{
			if (ptrlist->str && *(ptrlist->str) == '\0')
			{
				free(ptrlist->str);
				free(ptrlist);
				buffer->next = 0;
			}
			checker = -1;
		}
		else
		{
			if (ptrlist->str && *(ptrlist->str) == '\0')
				free(ptrlist->str);
			else
			{
				buffer = ptrlist;
				if ((ptrlist->next = ft_crnewlst()) == 0)
					exit(-5);
				ptrlist = ptrlist->next;
			}
		}		
	}
	return (root);
}

t_vec *ft_normvec(t_vec *vec)
{
	float length;

	length = ft_modulvec(vec);
	vec->x = vec->x * pow(length, -1);
	vec->y = vec->y * pow(length, -1);
	vec->z = vec->z * pow(length, -1);
	
	return (vec);
}

void ft_resoluition (t_list *root, int *wx, int *wy)
{
	int resolbufx;
	int resolbufy;

	resolbufx = 0;
	resolbufy = 0;
	while (root)
	{
		if (root->s == 1)
		{
			if(root->resolx < *wx)
				*wx = root->resolx;
			if(root->resoly < *wy)
				*wy = root->resoly;
		}
		root = root->next;
	}
}

t_vec * ft_lavec(t_vec *r, t_vec *u, t_vec *d, t_vec *formatrix, t_vec *oldvec)
{
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	new->x = (r->x * oldvec->x) + (r->y * oldvec->y) + (r->z * oldvec->z) + formatrix->x;
	new->y = (u->x * oldvec->x) + (u->y * oldvec->y) + (u->z * oldvec->z) + formatrix->y;
	new->z = (d->x * oldvec->x) + (d->y * oldvec->y) + (d->z * oldvec->z) + formatrix->z;
	return (new);
 }

void ft_lavecnewnorm(t_help *help, t_vec *oldvec)
 {
	float x;
	float y;
	float z;

	x = ((help->right)->x * oldvec->x) + ((help->right)->y * oldvec->y) + ((help->right)->z * oldvec->z);
	y = ((help->up)->x * oldvec->x) + ((help->up)->y * oldvec->y) + ((help->up)->z * oldvec->z);
	z = ((help->direct)->x * oldvec->x) + ((help->direct)->y * oldvec->y) + ((help->direct)->z * oldvec->z);
	oldvec->x = x;
	oldvec->y = y;
	oldvec->z = z;
 }

void ft_lavecnew(t_help *help, t_vec *oldvec)
 {
	float x;
	float y;
	float z;

	x = ((help->right)->x * oldvec->x) + ((help->right)->y * oldvec->y) + ((help->right)->z * oldvec->z) + (help->lamatrix)->x ;
	y = ((help->up)->x * oldvec->x) + ((help->up)->y * oldvec->y) + ((help->up)->z * oldvec->z) + (help->lamatrix)->y;
	z = ((help->direct)->x * oldvec->x) + ((help->direct)->y * oldvec->y) + ((help->direct)->z * oldvec->z) + (help->lamatrix)->z;
	oldvec->x = x;
	oldvec->y = y;
	oldvec->z = z;
 }

t_vec *ft_lamatrix(t_vec *r, t_vec *u, t_vec *d, t_vec *cam)
{
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	cam->x *= -1;
	cam->y *= -1;
	cam->z *= -1;
	new->x = (r->x * cam->x) + (r->y * cam->y) + (r->z * cam->z); 
	new->y = (u->x * cam->x) + (u->y * cam->y) + (u->z * cam->z); 
	new->z = (d->x * cam->x) + (d->y * cam->y) + (d->z * cam->z);
	cam->x *= -1;
	cam->y *= -1;
	cam->z *= -1;

	return (new);
}

t_vec *ft_crossproduct(t_vec *vec1, t_vec *vec2)
{
	t_vec * new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	new->x = (vec1->y * vec2->z) - (vec1->z * vec2->y);
	new->y = (vec1->x * vec2->z) - (vec2->x * vec1->z);
	new->y *= -1;
	new->z = (vec1->x * vec2->y) - (vec2->x * vec1->y);
	return (new);
}

t_vec *ft_axismake(t_help *help)
{
	t_vec *lol;

	if ((help->direct)->x == 0 && ((help->direct)->y == 1 || (help->direct)->y == -1) && (help->direct)->z == 0)
		lol = ft_crnewvec(-1, 0, 0);
	else 
		lol = ft_crnewvec(0, 1, 0);
	return(lol);

}

void ft_matrixcreate(t_list *root, t_help *help, int cam)
{
	t_list *buffer;
	t_vec *lol;
	t_vec sphere;
	t_vec *campoint;
	
	buffer = root;
	while (buffer && buffer->countcams != cam)
		buffer = buffer->next;
	if (buffer && buffer->s == 3 && buffer->countcams == cam)
	{
		campoint = ft_crnewvec(buffer->cor1.x, buffer->cor1.y, buffer->cor1.z);
		help->direct = ft_normvec(ft_crnewvec(buffer->cornorm.x, buffer->cornorm.y, buffer->cornorm.z));
	}
	else
	{
		write(1, "No camera in .rt file", 22);
		exit(1);
	}
	ft_inversevec(help->direct);
	lol = ft_axismake(help);
	help->right = ft_normvec(ft_crossproduct(lol, help->direct));
	help->up = ft_normvec(ft_crossproduct(help->direct, help->right));
	help->lamatrix = ft_lamatrix(help->right, help->up, help->direct, campoint);
	free(campoint);
	free(lol);
}

float ft_vecdot(t_vec *vec1, t_vec *vec2)
{
	float result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (result);
}

void ft_changegv(t_list *root, t_help *help)
{
	t_list *buffer;

	buffer = root;
	while (buffer)
	{
		if (buffer->s == 5 || buffer->s == 7 || buffer->s == 8 || buffer->s == 3)
		{
			ft_lavecnew(help, &buffer->cor1);
			ft_lavecnewnorm(help, &buffer->cornorm);
			ft_normvec(&buffer->cornorm);
		}
		else if (buffer->s == 6 || buffer->s == 4)
			ft_lavecnew(help, &buffer->cor1);
		else if (buffer->s == 9)
		{
			ft_lavecnew(help, &buffer->cor1);
			ft_lavecnew(help, &buffer->cor2);
			ft_lavecnew(help, &buffer->cor3);
		}
		buffer = buffer->next;
	}
}

int ft_discr(t_vec *ray, t_vec *camtosph, float radius, t_help *help)
{
	float a;
	float b;
	float c;
	float discr;
	float buf;

	a = ft_vecdot(ray, ray);
	b = 2 * ft_vecdot(camtosph, ray);
	c = ft_vecdot(camtosph, camtosph) - (radius * radius);
	discr = b*b - 4*a*c;
	if (discr < 0)
		return (-1);
	help->d1 = ((b * -1) - sqrt(discr)) * pow(2*a, -1);
	help->d2 = ((b * -1) + sqrt(discr)) * pow(2*a, -1);
	buf = (help->d1 > help->d2) ? help->d2 : help->d1;
	if ((help->clsd) > buf && buf > 0)
	{
		(help->clsd) = buf;
		return (1);
	}
	return (0);
}

void ft_ambient(t_list *root, t_help *help)
{
	t_list *buffer;

	buffer = root;
	while (buffer && buffer->s != 2)
		buffer = buffer->next;
	if (buffer && buffer->s == 2)
	{
		help->ar = buffer->r * buffer->ratio;
		help->ag = buffer->g * buffer->ratio;
		help->ab = buffer->b * buffer->ratio;
		help->amcolour = (help->ar << 16 | help->ag << 8 | help->ab);
	}
}

int ft_count (t_list *root, int num)
{
	t_list *buffer;
	int countsp;

	countsp = 0;
	buffer = root;
	while (buffer)
	{
		if (buffer->s == num)
			countsp++;
		buffer = buffer->next;			
	}
	return (countsp);
}

t_square *ft_rotmat(t_vec *cornorm)
{
	t_square *new;
	t_vec *tmpaxis;
	t_vec *ax;

	if ((new = malloc(sizeof(t_square))) == 0)
		return (0);
	new->axis1 = ft_crnewvec(cornorm->x, cornorm->y, cornorm->z);
	new->axis1 = ft_normvec(new->axis1);
	if (new->axis1->x == 0 && (new->axis1->y == 1 || new->axis1->y == -1) && new->axis1->z == 0)
		tmpaxis = ft_crnewvec(-1, 0, 0);
	else
		tmpaxis = ft_crnewvec(0,1,0);
	new->axis2 = ft_crossproduct(new->axis1, tmpaxis);
	new->axis3 = ft_crossproduct(new->axis2, new->axis1);
	free (tmpaxis);
	return(new);
}

int ft_interplane(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	float denom;
	int count;
	int i;
	int border;
	t_vec *cam;

	count = ft_count(root, 5);
	buffer = root;
	i = 0;	
	while (count > 0 && buffer)
	{
		border = 1000;
		while (buffer && buffer->s != 5)
			buffer = buffer->next;
		if (buffer && buffer->s == 5)
		{
			denom = ft_vecdot(ray, ft_normvec(&buffer->cornorm));
			if (denom > 0.00001)
			{
			help->d1 = ft_vecdot(&buffer->cor1, ft_normvec(&buffer->cornorm)) * pow(denom, -1);
			if (buffer->cornorm.x == 0 && (buffer->cornorm.y != 0) && buffer->cornorm.z == 0)
				border = 1000;
			if (help->d1 < border)
			{
				
				if ((help->d1 > 0) && ((help->clsd) > help->d1))
				{
					(help->clsd) = help->d1;
					help->clf = buffer;
				}
			}
			}
			buffer = buffer->next;
		}
		count--;
	}
	return (1);
}

int ft_sphereintersect(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	t_vec *campoint;
	t_vec *camtosph;
	int count;

	campoint = ft_crnewvec(0, 0, 0);
	help->clsd = 9999999;
	count = ft_count(root, 6);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 6)
			buffer = buffer->next;
		if (buffer && buffer->s == 6)
		{
			camtosph = ft_vesubtruct(campoint, &buffer->cor1); 
			if ((ft_discr(ray, camtosph, buffer->diameter / 2, help)) == 1)
				help->clf = buffer; 
			free(camtosph);
			buffer = buffer->next;
		}
		count--;
	}
	free(campoint);
	if (help->clf == 0)
		return (-1);
	return(1);
}

t_vec *ft_squarematrix(t_vec *axis1, t_vec *axis2, t_vec *axis3, t_vec *old)
 {
	t_vec *new;

	if ((new = malloc(sizeof(t_vec))) == 0)
		return (0);
	new->x = (axis2->x * old->x) + (axis2->y * old->y) + (axis2->z * old->z);
	new->y = (axis3->x * old->x) + (axis3->y * old->y) + (axis3->z * old->z);
	new->z = (axis1->x * old->x) + (axis1->y * old->y) + (axis1->z * old->z);
	return (new);
 }

float ft_cylinderdiscr(t_list *buffer, t_vec *ray, t_help *help)
{
	float a;
	float b;
	float c;
	float discr;
	t_vec *x;

	x = ft_crnewvec(buffer->cor1.x, buffer->cor1.y, buffer->cor1.z);
	ft_inversevec(x);
	a = ft_vecdot(ray, ray) - (ft_vecdot(ray, &buffer->cornorm) * ft_vecdot(ray, &buffer->cornorm));
	b = (ft_vecdot(ray, x) - (ft_vecdot(ray, &buffer->cornorm) * ft_vecdot(x, &buffer->cornorm)) );
	b = b * 2;
	c = ft_vecdot(x, x) - ft_vecdot(x, &buffer->cornorm) * ft_vecdot(x, &buffer->cornorm);
	c = c - (buffer->diameter / 2) * (buffer->diameter / 2);
	discr = b*b - 4*a*c;
	if (discr < 0)
	{
		free(x);
		return (-1);
	}
	help->d1 = ((b * -1) - sqrt(discr)) * pow(2*a, -1);
	help->d2 = ((b * -1) + sqrt(discr)) * pow(2*a, -1);
	free(x);
	return (1);
}

int ft_pointcheck(t_list *buffer, t_vec *ray, float mult)
{
	float s;
	t_vec *res;
	t_vec *p;
	t_vec *v;
	if (mult > 0)
	{
		p = ft_vecmultiply(ray, mult);
		res = ft_vesubtruct(p, &buffer->cor1);
		v = ft_crnewvec(buffer->cornorm.x, buffer->cornorm.y, buffer->cornorm.z);
		s = ft_vecdot(res, v);
		free(p);
		free(v);
		free(res);
		if (s < buffer->height && s > 0)
		 	return (0);
		else
			return (1);
	}
	return (1);
}

void ft_changefigure(t_list *buffer, t_help *help, int lever)
{
	if (lever == 1)
	{
		if (help->d1 < help->clsd)
		{
			help->clsd = help->d1;
			help->clf = buffer;
		}
	}
	else
	{
		if (help->d2 < help->clsd)
		{
			help->clsd = help->d2;
			help->clf = buffer;
		}
	}

}

int ft_checkplanec(t_list *buffer, t_vec *ray, t_help *help)
{
	float denom;
	float tmp;
	t_vec *p;
	t_vec *pc;
	float check;

	denom = ft_vecdot(ray, ft_normvec(&buffer->cornorm));
	if (denom > 0)
	{
		tmp = ft_vecdot(&buffer->cor1, ft_normvec(&buffer->cornorm)) * pow(denom, -1);
		if (tmp > 0)
		{
			p = ft_vecmultiply(ray, tmp);
			pc = ft_vesubtruct(p, &buffer->cor1);
			check = ft_modulvec(pc);
			free(p);
			free(pc);
			if (check < buffer->diameter * 0.5)
			{
				if (tmp < help->clsd)
				{
					help->clsd = tmp;
					help->clf = buffer;
					help->cylinder = 1;
					return (1);
				}
			}
		}
	}
		t_vec *far;
		t_vec *farpoint;
		t_vec *pfc;
		t_vec *inversenorm;
		far = ft_vecmultiply(ft_normvec(&buffer->cornorm), buffer->height);
		farpoint = ft_vecsum(&buffer->cor1, far);
		inversenorm = ft_crnewvec(-buffer->cornorm.x, -buffer->cornorm.y, -buffer->cornorm.z);
		if ((denom = ft_vecdot(ray, ft_normvec(inversenorm))) > 0)
		{
			tmp = ft_vecdot(farpoint, ft_normvec(inversenorm)) * pow(denom, -1);
			p = ft_vecmultiply(ray, tmp);
			pfc = ft_vesubtruct(p, farpoint);
			check = ft_modulvec(pfc);
			free(far);
			free(farpoint);
			free(inversenorm);
			free(p);
			free(pfc);
			if (tmp <= 0)
				return (0);
			if (check < buffer->diameter * 0.5)
			{
				if (tmp < help->clsd)
				{
					help->clsd = tmp;
					help->clf = buffer;
					help->cylinder = 1;
					return (1);
				}
			}
		}
	free(far);
	free(farpoint);
	free(inversenorm);
	return (0);
}

int ft_intercylinder(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	int count;
	float discr;

	buffer = root;
	count = ft_count(root, 8);
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 8)
			buffer = buffer->next;
		if (buffer && buffer->s == 8)
		{
			ft_normvec(&buffer->cornorm);
				if((ft_cylinderdiscr(buffer, ray, help) == 1))
				{
					if (ft_pointcheck(buffer, ray, help->d1) == 0)
						ft_changefigure(buffer, help, 1);
					if (ft_pointcheck(buffer, ray, help->d2) == 0)
						ft_changefigure(buffer, help, 0);
				}
				ft_checkplanec(buffer, ray, help);

			buffer = buffer->next;
		}
		--count;
	}
	return(0);
}

float ft_square2(t_vec *newsquare, t_vec *p, t_list *buffer, t_vec *ray)
{
	float denom;
	float res;
	int i;

	if (fabsf(p->x - newsquare->x) > buffer->sidesize * 0.5)
		return (-1);
	if (fabsf(p->y - newsquare->y) > buffer->sidesize * 0.5)
		return (-1);
	denom = ft_vecdot(ray, ft_normvec(&buffer->cornorm));
	if (denom < 0.00001)
		return (-1);
	res = ft_vecdot(&buffer->cor1, ft_normvec(&buffer->cornorm)) * pow(denom, -1);
	return (res);
}

int ft_square(t_square *square, t_list *buffer, t_vec *ray, t_help *help)
{
	t_vec *newray;
	t_vec *newnorm;
	t_vec *newsquare;
	float denom;
	t_vec *p;

	newray = ft_squarematrix(square->axis1, square->axis2, square->axis3, ray);
	newnorm = ft_normvec(ft_squarematrix(square->axis1, square->axis2, square->axis3, &buffer->cornorm));
	newsquare = ft_squarematrix(square->axis1, square->axis2, square->axis3, &buffer->cor1);
	denom = ft_vecdot(newray, newnorm);
	free(square->axis1);
	free(square->axis2);
	free(square->axis3);
	if (denom < 0.00001)
	{
		free(newray);
		free(newnorm);
		free(newsquare);
		return (-1);
	}
	p = ft_vecmultiply(newray, ft_vecdot(newsquare, newnorm) * pow(denom, -1));
	denom = ft_square2(newsquare, p, buffer, ray);
	free(p);
	free(newray);
	free(newnorm);
	free(newsquare);
	if (denom <= 0)
		return (-1);
	if (help->clsd > denom)
	{
		(help->clsd) = denom;
		help->clf = buffer;
	}
	return (1);
}

int ft_intersquare(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	int count;
	t_square *square;

	buffer = root;
	count = ft_count(root, 7);
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 7)
			buffer = buffer->next;
		if (buffer && buffer->s == 7)
		{
			square = ft_rotmat(&buffer->cornorm);
			ft_square(square, buffer, ray, help);
			free(square);
			buffer = buffer->next;
		}
		count--;
	}
		return(0);
}

float ft_maxmin(float v1, float v2, float v3, int louder)
{
	float tmp;

	if (louder == 1)
	{
		tmp = v1;
		if (v2 > tmp)
			tmp = v2;
		if (v3 > tmp)
			tmp = v3;
	}
	else
	{
		tmp = v1;
		if (v2 < tmp)
			tmp = v2;
		if (v3 < tmp)
			tmp = v3;
	}
	return (tmp);
}

float ft_triangle2(t_list *buffer, float invdet, t_vec *ray, t_triangle *triangle)
{
	float v;
	float distance;
	t_vec *vec;
	float u;
	t_vec *vec1;
	
	vec = ft_crnewvec(buffer->cor1.x, buffer->cor1.y, buffer->cor1.z);
	ft_inversevec(vec);
	u = ft_vecdot(vec, triangle->side3) * invdet;
	if (!(u < 0 || u > 1))
	{
		vec1 = ft_crossproduct(vec, triangle->side1);
		v = ft_vecdot(ray, vec1) * invdet;
		if (!(v < 0 || v + u > 1))
			distance = ft_vecdot(triangle->side2, vec1) * invdet;
		free(vec1);
	}
	else
		v = -1;
	free(vec);
	if (v < 0 || v + u > 1)
		return (-1);
	distance = distance * pow(ft_modulvec(ray), -1);
	return (distance);
}

float ft_triangle(t_list *buffer, t_vec *ray)
{
	float denom;
	t_triangle *triangle;
	t_vec *cornorm;
	float invdet;

	if ((triangle = malloc(sizeof(t_triangle))) == 0) // malloc
		return (0);
	triangle->side1 = ft_vesubtruct(&buffer->cor2, &buffer->cor1);
	triangle->side2 = ft_vesubtruct(&buffer->cor3, &buffer->cor1);
	triangle->side3 = ft_crossproduct(ray, triangle->side2);
	denom = ft_vecdot(triangle->side1, triangle->side3);
	if (denom < 0.000000001 && denom > -0.000000001)
		return (-1);
	invdet = 1 * pow(denom, -1);
	invdet = ft_triangle2(buffer, invdet, ray, triangle);
	free(triangle->side1);
	free(triangle->side2);
	free(triangle->side3);
	free(triangle);
	if (invdet <= 0)
		return (-1);
	return (invdet);
}

int ft_intertriangel(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	int count;
	float tmp;

	count = ft_count(root, 9);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 9)
			buffer = buffer->next;
		if (buffer && buffer->s == 9)
		{
			if ((tmp = ft_triangle(buffer, ray)) != -1)
			{
				if (tmp < help->clsd && tmp > 0)
				{
					help->clf = buffer;
					help->clsd = tmp;
					return (1);
				}
			}
			buffer = buffer->next;
		}
		count--;
	}
	return (0);
}

void ft_lightninghelp2(t_help *help, float multiplier, t_list *buffer)
{
	float mr;
	float mg;
	float mb;

	mb = multiplier / ((buffer->r * buffer->g/(buffer->b * buffer->g)) + buffer->g/buffer->b + 1);
	mg = buffer->g * mb /buffer->b;
	mr = mg * buffer->r / buffer->g;
	if (help->clf->r != 0)
		help->r += buffer->r * mr;
	if (help->clf->g != 0)
		help->g += buffer->g * mg;
	if (help->clf->b != 0)
		help->b += buffer->b * mb;
}

float ft_lightninghelp(t_list *buffer, t_vec *p, t_vec *n, t_help *help, t_vec *ray)
{
	t_vec *l;
	float ndotl;
	float multiplier;

	l = ft_vesubtruct(&buffer->cor1, p);
	if ((help->clf->s == 9 || help->clf->s == 7) && ft_vecdot(n, l) < 0)
		ft_inversevec(n);
	if (ft_vecdot(ray, n) > 0)
	{
		free(l);
		return (0);
	}
	if ((ndotl = ft_vecdot(n, l)) < 0)
	{
		free(l);
		return (0);
	}
	multiplier = buffer->ratio * ndotl / (ft_modulvec(n) * ft_modulvec(l));
	if (multiplier < 0.00392156 || multiplier > 1)
	{
		free(l);
		return (0);
	}
	help->m += multiplier;
	buffer->r = buffer->r == 0 ? 1 : buffer->r;
	buffer->g = buffer->g == 0 ? 1 : buffer->g;
	buffer->b = buffer->b == 0 ? 1 : buffer->b;
	ft_lightninghelp2(help, multiplier, buffer);
	free(l);
	return(1);
}

void ft_lightaddvolume(t_help *help)
{
	int ambient;

	help->r += help->clf->r * help->m;
	help->g += help->clf->g * help->m;
	help->b += help->clf->b * help->m;
	ambient = (help->amcolour & 0x00FF0000) >> 16;
	help->r += ambient;
	ambient = (help->amcolour & 0x0000FF00) >> 8;
	help->g += ambient;
	ambient = help->amcolour & 0x000000FF;
	help->b += ambient;
	help->r = help->r > 255 ? 255 : help->r;
	help->g = help->g > 255 ? 255 : help->g;
	help->b = help->b > 255 ? 255 : help->b;
	help->colour= help->r << 16 | help->g << 8 | help->b;
}

int ft_shadowdiscr(t_vec *ray, t_vec *camtosph, float radius)
{
	float a;
	float b;
	float c;
	float discr;
	float c1;

	a = ft_vecdot(ray, ray);
	b = 2 * ft_vecdot(camtosph, ray);
	c = ft_vecdot(camtosph, camtosph) - (radius * radius);
	discr = b*b - 4*a*c;
	if (discr < 0)
		return (-1);
	c = ((b * -1) - sqrt(discr)) * pow(2*a, -1);
	c1 = ((b * -1) + sqrt(discr)) * pow(2*a, -1);	 
	if ((c >= 0.0001 && c < 1) || (c1 >= 0.0001 && c1 < 1))
		return (1);
	return (-1);
}

int ft_sphereshadow(t_list *root, t_vec *p, t_vec *l)
{
	t_list *buffer;
	int count;
	t_vec *camtosph;
	int i;

	count = ft_count(root, 6);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 6)
			buffer = buffer->next;
		if (buffer && buffer->s == 6)
		{
			camtosph = ft_vesubtruct(p, &buffer->cor1);
			i = ft_shadowdiscr(l, camtosph, buffer->diameter / 2);
			free (camtosph);
			if (i == 1)
				return (1);
			buffer = buffer->next;
		}
			count--;
	}
	return (-1);
}

int ft_planeshadow(t_list *root, t_vec *l, t_vec *p)
{
	t_list *buffer;
	int count;
	float denom;
	float tmp;
	t_vec *pl;

	count = ft_count(root, 5);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 6)
			buffer = buffer->next;
		if (buffer && buffer->s == 6)
		{
			denom = ft_vecdot(l, ft_normvec(&buffer->cornorm));
			if (denom > 0.00001)
			{
				pl = ft_vesubtruct(&buffer->cor1, p);
				tmp = ft_vecdot(pl, ft_normvec(&buffer->cornorm)) * pow(denom, -1);
				if (tmp > 0.001 && tmp < 1)
				{
					free(pl);
					return (1);
				}
				free(pl);
			}
			buffer = buffer->next;
		}
		count--;
	}
	return (-1);
}

int ft_squaresha2(t_vec *newsquare, t_vec *p, t_list buffer, t_vec *ray, t_vec *pold)
{
	float denom;
	float res;
	int i;
	t_vec *newnorm;

	ft_inversevec(&buffer.cornorm);
	if (fabsf(p->x - newsquare->x) > buffer.sidesize * 0.5)
		return (-1);
	if (fabsf(p->y - newsquare->y) > buffer.sidesize * 0.5)
		return (-1);
	denom = ft_vecdot(ray, ft_normvec(&buffer.cornorm));
	 if (denom > 0.00001)
	 	return (-1);
	t_vec *pl;
	pl = ft_vesubtruct(&buffer.cor1, pold);
	res = ft_vecdot(pl, ft_normvec(&buffer.cornorm)) * pow(denom, -1);
	free(pl);
	ft_inversevec(&buffer.cornorm);
	if (res > 0.0001 && res < 1)
		return (1);
	return (-1);
}

int ft_squaresha1(t_square *square, t_list *buffer, t_vec *ray, t_vec *pold)
{
	t_vec *newray;
	t_vec *newnorm;
	t_vec *newsquare;
	float denom;
	t_vec *p;
	t_vec *pl;
	t_vec *pnew;

	newray = ft_squarematrix(square->axis1, square->axis2, square->axis3, ray);
	newnorm = ft_normvec(ft_squarematrix(square->axis1, square->axis2, square->axis3, &buffer->cornorm));
	newsquare = ft_squarematrix(square->axis1, square->axis2, square->axis3, &buffer->cor1);
	pnew = ft_squarematrix(square->axis1, square->axis2, square->axis3, pold);
	denom = ft_vecdot(newray, newnorm);
	free(square->axis1);
	free(square->axis2);
	free(square->axis3);
	free(square);
	ft_inversevec(&buffer->cornorm);
	if (denom >= 0.00001)
	{
		pl = ft_vesubtruct(newsquare, pnew);
		float res;
		res = ft_vecdot(pl, newnorm) * pow(denom, -1);
		if (res > 0.0001 && res < 1)
		{
			p = ft_vecmultiply(newray, res);
			p->x += pnew->x;
			p->y += pnew->y;
			if (!(fabsf(p->x - newsquare->x) > buffer->sidesize * 0.5))
			{
				if (!(fabsf(p->y - newsquare->y) > buffer->sidesize * 0.5))
				{
					free(pl);
					free(p);
					free(newsquare);
					free(newray);
					free(newnorm);
					free(pnew);
					return (1);
				}
			}
			free(p);
		}
		free(pl);
	}
	free(newsquare);
	free(newray);
	free(newnorm);
	free(pnew);
	return (-1);
}

int ft_squareshadow(t_list *root, t_vec *l, t_vec *pold)
{	
	t_list *buffer;
	int count;
	t_square *square;
	t_vec *newnorm;

	buffer = root;
	count = ft_count(root, 7);
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 7)
			buffer = buffer->next;
		if (buffer && buffer->s == 7)
		{
			if (ft_vecdot(l, &buffer->cornorm) > 0)
				return (-1);
			ft_inversevec(&buffer->cornorm);
			square = ft_rotmat(&buffer->cornorm);
			if ((ft_squaresha1(square, buffer, l, pold)) == 1)
				return (1);
			buffer = buffer->next;
		}
		count--;
	}
	return(0);
	
}

void ft_kek(t_vec *vec1, t_vec *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	vec1->z -= vec2->z;
}

float ft_trianglesha2(t_list *buffer, float invdet, t_vec *ray, t_triangle *triangle, t_vec *p)
{
	float v;
	float distance;
	t_vec *vec;
	float u;
	t_vec *vec1;
	
	vec = ft_vesubtruct(p, &buffer->cor1);
	u = ft_vecdot(vec, triangle->side3) * invdet;
	if (!(u < 0 || u > 1))
	{
		vec1 = ft_crossproduct(vec, triangle->side1);
		v = ft_vecdot(ray, vec1) * invdet;
		if (!(v < 0 || v + u > 1))
			distance = ft_vecdot(triangle->side2, vec1) * invdet;
		free(vec1);
	}
	else
		v = -1;
	free(vec);
	if (v < 0 || v + u > 1)
		return (-1);
	t_vec *coak;
	coak = ft_normvec (ft_crnewvec(ray->x, ray->y, ray->z));
	distance = distance * pow(ft_modulvec(coak), -1);
	free(coak);
	return (distance);
}

float ft_trianglesha(t_list buffer, t_vec *ray, t_vec *p)
{
	float denom;
	t_triangle *triangle;
	t_vec *cornorm;
	float invdet;

	if ((triangle = malloc(sizeof(t_triangle))) == 0)
		return (0);
	triangle->side1 = ft_vesubtruct(&buffer.cor2, &buffer.cor1);
	triangle->side2 = ft_vesubtruct(&buffer.cor3, &buffer.cor1);
	triangle->side3 = ft_crossproduct(ray, triangle->side2);
	denom = ft_vecdot(triangle->side1, triangle->side3);
	if (denom < 0.000000001 && denom > -0.000000001)
	{
	free(triangle->side1);
	free(triangle->side2);
	free(triangle->side3);
	free(triangle);
		return (-1);
	}
	invdet = 1 * pow(denom, -1);
	invdet = ft_trianglesha2(&buffer, invdet, ray, triangle, p);
	free(triangle->side1);
	free(triangle->side2);
	free(triangle->side3);
	free(triangle);
	if (invdet > 0.1 && invdet < 1)
		return (1);
	return (-1);
}

int ft_triangleshadow(t_list *root, t_vec *p, t_vec *l)
{
	t_list *buffer;
	int count;
	float tmp;

	count = ft_count(root, 9);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 9)
			buffer = buffer->next;
		if (buffer && buffer->s == 9)
		{
			if ((tmp = ft_trianglesha(*buffer, l, p)) == 1)
				return (1);
			buffer = buffer->next;
		}
		count--;
	}
	return (-1);
}

int ft_checkplanecsha(t_list buffer, t_vec *ray, t_help *help, t_vec *pold)
{
	float denom;
	float tmp;
	t_vec *p;
	t_vec *pc;
	t_vec *pr;
	t_vec *far;
	far = ft_vecmultiply(&buffer.cornorm, buffer.height);
	ft_inversevec(&buffer.cornorm);
	denom = ft_vecdot(ray, ft_normvec(&buffer.cornorm));
	if (denom > 0.00001)
	{
		buffer.cor1.x += far->x;
		buffer.cor1.y += far->y;
		buffer.cor1.z += far->z;
		pr = ft_vesubtruct(&buffer.cor1, pold);
		tmp = ft_vecdot(pr, ft_normvec(&buffer.cornorm)) * pow(denom, -1);
		if (tmp < 0.00001)
			return (0);
		p = ft_vecmultiply(ray, tmp);
		p->x += pold->x;
		p->y += pold->y;
		p->z += pold->z;
		pc = ft_vesubtruct(p, &buffer.cor1);
		if (ft_modulvec(pc) < buffer.diameter * 0.5)
		{
			if (tmp > 0.0001 && tmp < 1)
			{
				return (1);
			}
		}
	}
	return (0);
}

int ft_shadowmanage(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	t_vec *p;
	t_vec *l;
	int count;
	int i;
	int off;

	off = 0;
	p = ft_vecmultiply(ray, (help->clsd));
	count = ft_count(root, 4);
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 4)
			buffer = buffer->next;
		if ((buffer && buffer->s == 4))
		{
			i = 0;
			l = ft_vesubtruct(&buffer->cor1, p);
			if ((ft_sphereshadow(root, p, l) == 1))
				i++;
			if (ft_planeshadow(root, l, p) == 1)
				i++;
			if (ft_squareshadow(root, l, p) == 1)
				i++;
			if (ft_triangleshadow(root, p, l) == 1)
			 	i++;
			if (i > 0)
				off++;
			buffer = buffer->next;
		}
		count--;
	}
	free(p);
	free(l);
	if (off == ft_count(root, 4))
		return (1);
	return (0);
}

t_vec *ft_squaerenorm(t_help *help, t_vec *camdir, t_vec *p)
{
	t_vec *n;

	n = ft_normvec(ft_crnewvec(help->clf->cornorm.x, help->clf->cornorm.y, help->clf->cornorm.z));
	if (ft_vecdot(camdir, n) > 0)
		ft_inversevec(n);
	return (n);
}

t_vec *ft_cylindernorm(t_help *help, t_vec *camdir, t_vec *p)
{
	t_vec *orign;
	t_vec *pc;
	t_vec *a;
	t_vec *ao;

	orign = ft_normvec(ft_crnewvec(help->clf->cornorm.x, help->clf->cornorm.y, help->clf->cornorm.z));
	if (help->cylinder == 1)
	{
		if (ft_vecdot(camdir, orign) > 0)
			ft_inversevec(orign);
		return (orign);	
	}
	pc = ft_vesubtruct(p, &help->clf->cor1);
	if (ft_vecdot(pc, orign) < 0)
		ft_inversevec(orign);
	a = ft_vecmultiply(orign, ft_vecdot(pc, orign));
	free(pc);
	ao = ft_crnewvec(a->x + help->clf->cor1.x, a->y + help->clf->cor1.y, a->z + help->clf->cor1.z);
	pc = ft_normvec(ft_vesubtruct(p, ao));
	free(ao);
	free(a);
	free(orign);
	return (pc);
}

t_vec *ft_trianglenorm(t_help *help, t_vec *camdir, t_vec *p)
{
	t_vec *n;
	t_vec *side1;
	t_vec *side3;
	t_vec *normcamdir;

	normcamdir = ft_normvec(ft_crnewvec(camdir->x, camdir->y, camdir->z));
	side1 = ft_vesubtruct(&(help->clf->cor2), &(help->clf->cor1));
	side3 = ft_vesubtruct(&help->clf->cor2, &help->clf->cor3);
	n = ft_normvec(ft_crossproduct(side1, side3));
	free(side1);
	free(normcamdir);
	free(side3);
	return (n);
}

t_vec *ft_crnormalvec(t_help *help, t_vec *p, t_vec *ray)
{
	t_vec *normal;
	t_vec *camdir;

	camdir = ft_crnewvec(ray->x,ray->y,ray->z);
	if (help->clf->s == 6)
		normal = ft_normvec(ft_vesubtruct(p, &((help->clf)->cor1)));
	else if (help->clf->s == 7)
		normal = ft_squaerenorm(help, camdir, p);
	else if (help->clf->s == 8)
		normal = ft_cylindernorm(help, camdir, p);
	else if (help->clf->s == 9)
		normal = ft_trianglenorm(help, camdir, p);
	else if (help->clf->s == 5)
	{
		if (help->clf->cornorm.x == 0 && (help->clf->cornorm.y == 1 || help->clf->cornorm.y == -1) && help->clf->cornorm.z == 0)
			normal = ft_normvec(ft_crnewvec(0, 0.4, -0.4));
		else
			normal = ft_normvec(ft_crnewvec(help->clf->cornorm.x, help->clf->cornorm.y, help->clf->cornorm.z));
		if (ft_vecdot(normal, camdir) > 0)
			ft_inversevec(normal);
	}
	free(camdir);
	return (normal);
}

int ft_lightningsphere(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	t_vec *p;
	t_vec *n;
	int count;

	count = ft_count(root, 4);
	p = ft_vecmultiply(ray, (help->clsd));
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 4)
			buffer = buffer->next;
		if ((buffer && buffer->s == 4))
		{
			n = ft_crnormalvec(help, p, ray);
				ft_lightninghelp(buffer, p, n, help, ray);
			free(n);
			buffer = buffer->next;
		}
		count--;
	}
	free(p);
	ft_lightaddvolume(help);
	return (1);
}

int ft_planelighthelp(t_list *buffer, t_vec *p, t_vec *n, t_help *help)
{
	t_vec *l;
	float ndotl;
	float multiplier;

	l = ft_vesubtruct(&buffer->cor1, p);
	if ((ndotl = ft_vecdot(n, l)) < 0)
	{
		free(l);
		return (0);
	}
	multiplier = buffer->ratio * ndotl / (ft_modulvec(n) * ft_modulvec(l));
	if (multiplier < 0.00392156 || multiplier > 1)
	{
		free(l);
		return (0);
	}
	help->m += multiplier;
	buffer->r = buffer->r == 0 ? 1 : buffer->r;
	buffer->g = buffer->g == 0 ? 1 : buffer->g;
	buffer->b = buffer->b == 0 ? 1 : buffer->b;
	free(l);
	return(1);
}

int ft_planelight(t_list *root, t_vec *ray, t_help *help)
{
	t_list *buffer;
	t_vec *p;
	t_vec *n;
	int count;
	t_vec *camdir;

	camdir = ft_crnewvec(0,0,-1);
	count = ft_count(root, 4);
	p = ft_vecmultiply(ray, (help->clsd));
	buffer = root;
	while (count > 0 && buffer)
	{
		while (buffer && buffer->s != 4)
			buffer = buffer->next;
		if ((buffer && buffer->s == 4))
		{
			n = ft_crnormalvec(help, p, ray);
				ft_planelighthelp(buffer, p, n, help);
			free(n);
			buffer = buffer->next;
		}
		count--;
	}
	free(camdir);
	free(p);
	ft_lightaddvolume(help);
	return (1);
}

int inter(t_list *root, t_vec *ray, t_help *help, t_list1 *set)
{
	ft_sphereintersect(root, ray, help);
	ft_interplane(root, ray, help);
	ft_intersquare(root, ray, help);
	ft_intertriangel(root, ray, help);
	ft_intercylinder(root, ray, help);
	if (help->clf == 0)
		return (-1);
	if (help->clf && (help->clf)->s == 6)
	{
		if ((ft_lightningsphere(root, ray, help)) == -1)
			return(-1);
	}
	if ((help->clf && (help->clf)->s == 5))
		if ((ft_planelight(root, ray, help)) == -1)
			return (-1);
	if (help->clf && (help->clf)->s == 7)
		if ((ft_lightningsphere(root, ray, help)) == -1)
			return(-1);
	if (help->clf && (help->clf)->s == 8)
		if ((ft_lightningsphere(root, ray, help)) == -1)
			return(-1);
	if (help->clf && (help->clf)->s == 9)
		if ((ft_lightningsphere(root, ray, help)) == -1)
			return(-1);
	if ((ft_shadowmanage(root, ray, help)) == 1)
	{
		if (!(help->r == help->ar && help->g == help->ag && help->b == help->ab))
	  	help->colour= (int)(help->r * 0.7) << 16 | (int)(help->g * 0.7) << 8 | (int)(help->b * 0.7);
	}
	return (1);
}

int  ft_ray(t_list *root, float iterx, float itery, t_help *help, t_list1 *set)
{
	t_vec *ray;

	help->clf = 0;
	ray = ft_crnewvec(iterx , itery , -1);
	help->r = 0;
	help->g = 0;
	help->b = 0;
	help->m = 0;
	help->cylinder = 0;
	if ((inter(root, ray, help, set)) == -1)
	{
		free(ray);
		return (-1);
	}
		free(ray);
	return (1);
}

int ft_ratio(t_list1 *set, float iterx, float itery, t_help *help)
{
	float widthx;
	float widthy;
	float ratio;
	t_list *buffer;
	float fow;
	buffer = set->root;
	while (buffer && buffer->countcams != set->cam)
		buffer = buffer->next;
	if (buffer && buffer->s == 3 && buffer->countcams == set->cam)
		fow = buffer->fow;
	else
		return (-1);
	widthx = 2 * tan(0.5 * fow * 0.0174533);
	ratio = set->wx * pow(set->wy, -1);
	widthy = widthx * pow(ratio, -1);
	iterx = iterx * widthx * pow(set->wx, -1);
	itery = itery * widthy * pow(set->wy, -1);
	return (ft_ray(set->root, iterx, itery, help, set));
}

void my_mlx_pixel_put(t_list1 *set, int x, int y, int color)
{
	char    *dst;

	dst = set->addr + (y * set->linelengh + x * (set->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_freelist(t_list *list)
{
	t_list *buffer;

	buffer = list->next;
	while (buffer)
	{
		list->next = 0;
		free(list);
		list = buffer;
		buffer = list->next;
	}
	free(list);
}

void ft_cirle(t_list1 *set, t_help *help)
{
	int itery;
	int iterx;
	int iteroutx;
	int iterouty;

	iterouty = 0;
	itery = set->wy / 2;
	set->img = mlx_new_image(set->mlx, set->wx, set->wy);
	set->addr = mlx_get_data_addr(set->img, &(set->bpp), &(set->linelengh), &(set->endian));
	while (itery > (set->wy / -2 ))
	{
		iterx = set->wx / -2;
		iteroutx = 0;
		while (iterx < set->wx / 2)
		{
			if ((ft_ratio(set, iterx, itery, help)) >= 0)
				my_mlx_pixel_put(set, iteroutx, iterouty, help->colour);
			else
				my_mlx_pixel_put(set, iteroutx, iterouty, help->amcolour);
			iteroutx++;
			iterx++;
		}
		iterouty++;
		itery--;
	}
	mlx_put_image_to_window(set->mlx, set->wnd, set->img, 0, 0);
}

int ft_mouseclick(t_list1 *set)
{
	mlx_clear_window(set->mlx, set->wnd);
	mlx_destroy_window(set->mlx, set->wnd);
	free(set->mlx);
	free(set->groot);
	free(set);
	exit(1);
}

void ft_start(t_list1 *set)
{
	t_help *help;
	
	help = malloc(sizeof(t_help));
	set->root = ft_rootcopy(set->groot);
	ft_matrixcreate(set->root, help, set->cam);
	ft_changegv(set->root, help);
	free(help->direct);
	free(help->right);
	free(help->up);
	free(help->lamatrix);
	ft_ambient(set->root, help);
	ft_cirle(set, help);
	free(help);
	ft_freelist(set->root);
}

int ft_junk(int keycode, t_list1 *set)
{
	t_list *buffer;

	if (keycode == 53)
	{
		mlx_clear_window(set->mlx, set->wnd);
		mlx_destroy_window(set->mlx, set->wnd);
		mlx_destroy_image(set->mlx, set->img);
		ft_freelist(set->groot);
		free(set->mlx);
		free(set);
		exit(1);
	}
	if (keycode == 123)
	{
		if (!(set->cam > 1 && set->cam <= ft_count(set->groot, 3)))
			return (0);
		set->cam -= 1;
		buffer = set->groot;
		while (buffer && buffer->countcams != set->cam)
			buffer = buffer->next;
		if (buffer && buffer->s == 3 && buffer->countcams == set->cam)
		{
			mlx_clear_window(set->mlx, set->wnd);
			mlx_destroy_image(set->mlx, set->img);
			ft_start(set);
		}
	}
	if (keycode == 124)
	{
		if (!(set->cam < ft_count(set->groot, 3)))
			return (0);
		set->cam += 1;
		buffer = set->groot;
		while (buffer && buffer->countcams != set->cam)
			buffer = buffer->next;
		if (buffer && buffer->s == 3 && buffer->countcams == set->cam)
		{
			mlx_clear_window(set->mlx, set->wnd); 			 //free img??
			mlx_destroy_image(set->mlx, set->img);
			//free(set->addr);
			ft_start(set);
		}
	}
	return (0);
}

int	ft_strnstr(const char *haystack)
{
	int i;
	int j;
	int k;
	char *needle;

	needle = ".rt";
	i = 3;
	k = 0;
	j = 0;
	if (haystack[0] == needle[0] && haystack[1] == needle[1] && haystack[2] == needle[2])
		return (0);
	while (needle[k] && haystack[j])
	{
		while (needle[k] && needle[k] == haystack[k + j])
			++k;
		if (k == i)
			return (1);
		j++;
		k = 0;
	}
	return (0);
}

int ft_checkfile(int argc, char **argv)
{
	if (argc == 3)
	{
		if ((argv[2])[0] != '-')
			ft_errormanage(-1);
		if ((argv[2])[1] != '-')
			ft_errormanage(-1);
		if ((argv[2])[2] != 's')
			ft_errormanage(-1);
		if ((argv[2])[3] != 'a')
			ft_errormanage(-1);
		if ((argv[2])[4] != 'v')
			ft_errormanage(-1);
		if ((argv[2])[5] != 'e')
			ft_errormanage(-1);
		if ((argv[2])[6] != '\0')
			ft_errormanage(-1);
		if (ft_strnstr(argv[1]) == 0)
			ft_errormanage(-2);
		return (2);
	}
	if (argc != 2)
		ft_errormanage(-3);
	if (ft_strnstr(argv[1]) == 0)
		ft_errormanage(-2);
	return(1);
}

// SCREENSHOT TIME... STARTS
void	ft_circlehelp(t_list1 *set)
{
	set->img = mlx_new_image(set->mlx, set->wx, set->wy);
	set->addr = mlx_get_data_addr(set->img, &(set->bpp),
	&(set->linelengh), &(set->endian));
}

void	ft_cirlescreen(t_list1 *set, t_help *help)
{
	int	itery;
	int	iterx;
	int	iteroutx;
	int	iterouty;

	iterouty = 0;
	itery = set->wy / 2;
	ft_circlehelp(set);
	while (itery > (set->wy / -2))
	{
		iterx = set->wx / -2;
		iteroutx = 0;
		while (iterx < set->wx / 2)
		{
			if ((ft_ratio(set, iterx, itery, help)) >= 0)
				my_mlx_pixel_put(set, iteroutx, iterouty, help->colour);
			else
				my_mlx_pixel_put(set, iteroutx, iterouty, help->amcolour);
			iteroutx++;
			iterx++;
		}
		iterouty++;
		itery--;
	}
}

unsigned char		*ft_crheader(int height, int extrawidth)
{
	int					fsize;
	int					i;
	unsigned char		*str;

	fsize = 54 + (extrawidth * height);
	i = 0;
	if (!(str = malloc(sizeof(unsigned char) * 15)))
		return (0);
	while (i < 14)
		str[i++] = 0;
	str[14] = '\0';
	str[0] = (unsigned char)('B');
	str[1] = (unsigned char)('M');
	str[2] = (unsigned char)(fsize);
	str[3] = (unsigned char)(fsize >> 8);
	str[4] = (unsigned char)(fsize >> 16);
	str[5] = (unsigned char)(fsize >> 24);
	str[10] = (unsigned char)(54);
	return (str);
}

unsigned char		*ft_info(int height, int width)
{
	unsigned char		*str;
	int					i;

	i = 0;
	if (!(str = malloc(sizeof(unsigned char) * 41)))
		return (0);
	while (i < 40)
		str[i++] = 0;
	str[40] = '\0';
	str[0] = (unsigned char)(40);
	str[4] = (unsigned char)(width);
	str[5] = (unsigned char)(width >> 8);
	str[6] = (unsigned char)(width >> 16);
	str[7] = (unsigned char)(width >> 24);
	str[8] = (unsigned char)(height);
	str[9] = (unsigned char)(height >> 8);
	str[10] = (unsigned char)(height >> 16);
	str[11] = (unsigned char)(height >> 24);
	str[12] = (unsigned char)(1);
	str[14] = (unsigned char)(24);
	return (str);
}

void				ft_pixelput(t_list1 *set, int fd, int padd)
{
	unsigned char		rgb[3];
	int					iteri;
	int					iterj;
	int					maxx;
	int					maxy;

	iteri = 0;
	maxy = set->wy - 1;
	while (iteri <= maxy)
	{
		maxx = set->wx;
		iterj = 0;
		while (iterj < maxx)
		{
			rgb[0] = set->addr[(maxy * set->linelengh +
							iterj * (set->bpp / 8))];
			rgb[1] = set->addr[(maxy * set->linelengh +
							iterj * (set->bpp / 8)) + 1];
			rgb[2] = set->addr[(maxy * set->linelengh +
							iterj++ * (set->bpp / 8)) + 2];
			write(fd, rgb, 3);
		}
		write(fd, "000", padd);
		maxy--;
	}
}

void				ft_screemake(t_list1 *set)
{
	int					fd;
	unsigned char		*header;
	unsigned char		*info;
	int					widthb;
	int					padd;

	widthb = set->wx * 3;
	padd = (4 - (widthb % 4)) % 4;
	if ((fd = open("miniRT.bmp", O_CREAT | O_RDWR, 416)) < 0)
		ft_errormanage(-4);
	if (!(header = ft_crheader(set->wy, widthb + padd)))
		ft_errormanage(-5);
	if (!(info = ft_info(set->wy, set->wx)))
		ft_errormanage(-5);
	write(fd, header, 14);
	write(fd, info, 40);
	free(header);
	free(info);
	ft_pixelput(set, fd, padd);
	close(fd);
	write(1, SUC, sizeof(SUC));
}

void	ft_startscreen(t_list1 *set)
{
	t_help	*help;

	help = malloc(sizeof(t_help));
	ft_matrixcreate(set->root, help, set->cam);
	ft_changegv(set->root, help);
	free(help->direct);
	free(help->right);
	free(help->up);
	free(help->lamatrix);
	ft_ambient(set->root, help);
	ft_cirlescreen(set, help);
	free(help);
	ft_freelist(set->root);
	ft_screemake(set);
	mlx_destroy_image(set->mlx, set->img);
	free(set->mlx);
	free(set);
	exit(1);
}

void	ft_screenshot(char **argv)
{
	t_list1	*set;
	int		fd;

	if ((set = malloc(sizeof(t_list1))) == 0)
		ft_errormanage(-5);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_errormanage(-4);
	set->root = ft_crsequence(fd);
	set->cam = 1;
	close(fd);
	ft_parser(set->root);
	mlx_get_screen_size(set->mlx, &set->wx, &set->wy);
	ft_resoluition(set->root, &set->wx, &set->wy);
	set->mlx = mlx_init();
	ft_startscreen(set);
}

//SCREENSHOT TIME... END

int main (int argc, char **argv)
{
	t_list1 *set;
	int fd;

	if ((ft_checkfile(argc, argv)) == 2)
	ft_screenshot(argv);
	if ((set = malloc(sizeof(t_list1))) == 0)
		ft_errormanage(-5);
	set->camoffset = 0;
	set->cam = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_errormanage(-4);
	set->groot = ft_crsequence(fd);
	close(fd);
	ft_parser(set->groot);
	mlx_get_screen_size(set->mlx, &set->wx, &set->wy);
	ft_resoluition (set->groot, &set->wx, &set->wy);
	set->mlx = mlx_init();
	set->wnd = mlx_new_window(set->mlx, set->wx, set->wy, "miniRT");
	ft_start(set);
	mlx_key_hook(set->wnd, ft_junk, set);
	mlx_hook(set->wnd, 17, 0L, ft_mouseclick, set);
	mlx_loop(set->mlx);
	return (0);	
}