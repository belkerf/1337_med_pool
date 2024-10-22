#include <unistd.h>
#include <stdlib.h>

void brainf(char *str)
{
	int arr[2048] = {0};
	int *ptr;
	int co;
	ptr = arr;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if(*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr);
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			co = -1;
			while (co != 0)
			{
				str++;
				if (*str == ']')
					co++;
				if (*str == '[')
					co--;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			co = -1;
			while (co != 0)
			{
				str--;
				if (*str == '[')
					co++;
				if (*str == ']')
					co--;
			}
		}
		str++;
	}
}
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		brainf(argv[1]);
	}
	else
		write(1, "\n", 1);
	return 0;
}
