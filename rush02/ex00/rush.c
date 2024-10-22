#include <stdlib.h>

char *supp_occ(char *obj);
char *proc_obj(char **obj);
char **ruch(char **arr, char **rh);
char *gen_obj(char **ma, int l, int p, char *obj);
char *data(char *str, int p, char *obj);
char **alloc_data(char **arr, int l);
int ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	char	*re;

	re = dest;
	while (*src != '\0')
	{
		*re = *src;
		re++;
		src++;
	}
	*re = '\0';
	return (dest);
}
char **alloc_data(char **arr, int l) {
    int i;
    arr = (char **)malloc(l * sizeof(char *));
	i = 0;
    while (i < l)
	{
        arr[i] = (char *)malloc(5 * sizeof(char));
		i++;
    }
    return arr;
}

char *data(char *str, int p, char *obj)
{
    char **d1_2, **d1_3, **d1_4, **d2_2, **d2_3;
    char *c12 = "12", *c13 = "13", *c14 = "14", *c22 = "22";
	char t;
    int f = 0;
    if (!ft_strcmp(str , "21") || !ft_strcmp(str, "31") || !ft_strcmp(str, "41") || !ft_strcmp(str, "32"))
    {
        f = 1;
    }
    if (f == 1)
    {
        t = str[0];
        str[0] = str[1];
        str[1] = t;
        p = 4 - p - 1;
    }
    d1_2 = alloc_data(d1_2, 2);
    d1_3 = alloc_data(d1_3, 2);
    d1_4 = alloc_data(d1_4, 2);
    d2_2 = alloc_data(d2_2, 3);
    d2_3 = alloc_data(d2_3, 3);

    ft_strcpy(d1_2[0], "4123");
    ft_strcpy(d1_2[1], "4213");
    ft_strcpy(d1_3[0], "4132");
    ft_strcpy(d1_3[1], "4231");
    ft_strcpy(d1_4[0], "4321");
    ft_strcpy(d1_4[1], "4321");
    ft_strcpy(d2_2[0], "1423");
    ft_strcpy(d2_2[1], "2413");
    ft_strcpy(d2_2[2], "3412");
    ft_strcpy(d2_3[0], "1432");
    ft_strcpy(d2_3[1], "2431");
    ft_strcpy(d2_3[2], "3421");

    if (!(ft_strcmp(str, c12)))
        obj = gen_obj(d1_2, 2, p, obj);
    else if (!(ft_strcmp(str, c13)))
        obj = gen_obj(d1_3, 2, p, obj);
    else if (!(ft_strcmp(str, c14)))
        obj = gen_obj(d1_4, 2, p, obj);
    else if (!(ft_strcmp(str, c22)))
        obj = gen_obj(d2_2, 3, p, obj);
    else
        obj = gen_obj(d2_3, 3, p, obj);

    return obj;
}

char *supp_occ(char *obj)
{
	int i = 0, j, k = 0;
	while (obj[i])
	{
		k = i + 1;
		while (obj[k])
		{
			if (obj[i] == obj[k])
			{
				j = i;
				while(obj[j])
				{
					obj[j] = obj[j + 1];
					j++;
				}
				i--;
			}
			k++;
		}
		i++;
		return (obj);
	}
}
char *gen_obj(char **ma, int l, int p, char *obj) {
    int i;

 i = 0;	
	while(i < l)
	{
        if (ma[i][p] != '\0')
		{
            obj[i] = ma[i][p];
        }
		else
		{
            break;
        }
		i++;
    }
    obj[i] = '\0';
    return obj;
}
char *proc_obj(char **obj)
{
    int i = 0, j;
    char *cas = (char *)malloc(5 * sizeof(char));
    char *p = cas;
    char *s1 = supp_occ(obj[0]);
    char *s2 = supp_occ(obj[1]);

    while (s1[i])
    {
        j = 0;
		while(s2[j])
		{
			if (s1[i] == s2[j])
			{
				*p = s1[i];
				p++;
			}
			j++;
		}
        i++;
    }
    *p = '\0';
    return cas;
}
char **ruch(char **arr, char **rh)
{
    char **obj;
	int i = 4, j = 0;
	char *cas;

    obj = alloc_data(obj, 2);
	while (i < 8)
	{
		j = 0;
		while (j < 4)
		{
			obj[0] = data(arr[j], i - 4, obj[0]);
			obj[1] = data(arr[i],  j, obj[1]);
			cas = proc_obj(obj);
			if (cas[0] == '\0')
				return rh;
			else if (cas[1] == '\0')
				rh[i - 4][j] = cas[0];
			else
				rh[i - 4][j] = '6';
			j++;
		}
		i++;
	}
    return rh;
}

