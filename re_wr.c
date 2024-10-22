#include <stdlib.h>
#include <unistd.h>

int c_w(char *str)
{
	int i = 0;
	int co = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			co++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				i++;
			}
		}
		if (str[i])
			i++;
	}
	return co;
}

void put_st(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char **st_cp(char **arr, char *str, int co)
{
	int i = 0;
	int j = -1;
	int k;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			j++;
			k = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				arr[j][k] = str[i];
				k++;
				i++;
			}
			arr[j][k] = '\0';
		}
		if (str[i])
			i++;
	}
	return  arr;
}

int main(int argc, char *argv[])
{
	int i = 0;
	char **arr;
	int co;
	if (argc == 2)
	{
		co = c_w(argv[1]);
		arr = (char **)malloc((co) * sizeof(char *));
		while (i < co)
		{
			arr[i] = malloc(100);
			i++;
		}
		arr = st_cp(arr, argv[1], co);
		i = co - 1;
		while (i  >= 0)
		{
			put_st(arr[i]);
			if (i != 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return 0;
}
