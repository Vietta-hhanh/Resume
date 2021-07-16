#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <math.h>
#include <fcntl.h>
#include "mlx/mlx.h"

#define WRONGSAVE "Error\ncheck your <<--save>>\n"
#define WRONGFILE "Error\ncheck your <<.rt file>>\n"
#define WRONGNUMFILES "Error\ncheck amount of agruments\n"
#define FILEDNTEXIST "Error\nfile dosen't exist"
#define MALLOCCRASH "Error\nmalloc tried allocate memory, but ooops..."
#define WRONGAMOUNTWORD "Error\nwrong settings of object in .rt file"
#define ALOTUPPERSETTING "Error\nresolutin and ambient light must be presented once"
#define NOTENOUGHSETTS "Error\nthere isn't ambient light or resolutin in .rt file"
#define WRONGVALUE "Error\ncheck values such parameters as ratio, norm.orint.vec, fow and rgb channels"
#define NOANYCAM "Error\nno cams in .rt file"
# define SUC "Screenshot was successfully created!"

typedef struct s_vector
{
	float x;
	float y;
	float z;

}				t_vec;

typedef struct		s_list1
{
	char *str;
	struct s_list1 *next;
	int s;
	int resolx;
	int resoly;
	int r;
	int g;
	int b;
	float ratio;
	int countcams;
	int fow;
	float diameter;
	float height;
	float sidesize;
	t_vec cor1;
	t_vec cor2;
	t_vec cor3;
	t_vec cornorm;
}					t_list;

typedef struct s_square
{
	t_vec *axis1;
	t_vec *axis2;
	t_vec *axis3;

}				t_square;

typedef struct s_triangle
{
	t_vec *side1;
	t_vec *side2;
	t_vec *side3;

}				t_triangle;

typedef struct s_help
{
			float d1;
			float d2;
			float clsd;
			int cylinder;
			float i;
			float colour;
			int amcolour;
			t_list *clf;
			t_vec *right;
			t_vec *up;
			t_vec *direct;
			t_vec *lamatrix;
			int ar;
			int ag;
			int ab;
			int r;
			int g;
			int b;
			float m;
			t_vec tmpray;
}				t_help;

typedef struct s_list
{
    void *mlx;
    void *wnd;
    void *img;
    char *addr;
    int bpp;
	int camoffset;
	int cam;
    int endian;
    int linelengh;
	int wx;
	int wy;
	int readytoclose;
	t_list *root;
	t_list *groot;

}               t_list1;

typedef struct s_squarevec
{
	t_vec *newray;
	t_vec *newnorm;
	t_vec *newsquare;
	t_vec *pnew;
	
}		t_squarevec;

t_vec	*ft_crnewvec(float x, float y, float z);
t_vec	*ft_vesubtruct(t_vec *vec1, t_vec *vec2);
t_vec	*ft_vecsum(t_vec *vec1, t_vec *vec2);
t_vec	*ft_vecmultiply(t_vec *vec1, float t);
float	ft_modulvec(t_vec *vec);
t_vec	*ft_dublvec (t_vec *old);
void	ft_create (t_vec *dst, float x, float y, float z);
void	ft_inversevec(t_vec *vec);
void	ft_equalize(t_vec *dir, t_vec srs);
void	ft_zerovec(t_vec *vec);
t_list	*ft_crnewlst();
int		ft_hardstrlen(char **str);
int		ft_atoi(const char *str);
float	ft_float(char *kek);
char	**ft_split(char const *s, char c, char c1);
#endif
