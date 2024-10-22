#include <stdio.h>
#include <stdlib.h>
int	valide3(char **arr);
int	valide2(char *str, char **arr);
int	valide1(char *str, char **arr);
int	ft_strcmp(char *s1,	char *s2);
char *proc_obj(char **obj);
char **ruch(char **arr, char **rh);
char *gen_obj(char **ma, int l, int p, char *obj);
char *data(char *str, int p, char *obj);
char **alloc_data(char **arr, int l);

int main(int argc, char *argv[])
{
	char **arr;
	char **rh;
	int i, j;

	if (argc == 2)
	{
		arr = (char **)malloc(8 * sizeof(char *));
		i = 0;
		while (i < 8)
		{
			arr[i] = (char *)malloc(3 * sizeof(char));
			i++;
		}
		i = valide1(argv[1], arr);
		if ( i == 0)
			printf("try another comb");
		else
		{
			rh = (char **)malloc(4 * sizeof(char *));
			i = 0;
			while (i < 4)
			{
				rh[i] = (char *)malloc(5 * sizeof(char));
				i++;
			}
			i = 0;
			while (i < 4)
			{
				j = 0;
				while (j < 4)
				{
					rh[i][j] = '0';
				}
				rh[i][j] = '\0';
				i++;
			}
			rh = ruch(arr, rh);
			i = 0;
			while (i < 4)
			{
				puts(rh[i]);
				i++;
			}
		}
		// Free allocated memory
	i = 0;
    while (i < 8)
	{
        free(arr[i]);
		i++;
    }
    free(arr);
	}
	return (0);
}
