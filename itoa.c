#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char    *strr(char *str)
{
    int        i;
    int        len;
    char    c;

    i = 0;
    len = ft_strlen(str);
    len--;
    while (i <= len / 2)
    {
        c = str[i];
        str[i] = str[len - i];
        str[len - i] = c;
        i++;
    }
    return (str);
}

char *ft_itoa(int nbr)
{
    char *res;
    long int n = nbr;
    int f = 0;
    int i = 0;

    if (n < 0)
    {
        f = 1;
        n = n * (-1);
    }
    while (n  > 9)
    {
        n = n / 10;
        i++;
    }
    if (f)
        i = i + 3;
    else
        i = i + 2;
    res = (char *)malloc((i) * sizeof(char));
    i = 0;
    if (f)
    {
        n = nbr;
        n = n * (-1);
    }
    else
        n = nbr;
    while (n > 9)
    {
        res[i] = (n % 10) + '0';
        i++;
        n = n / 10;
    }
    res[i] = n + '0';
    i++;
    if (f)
    {
        res[i] = '-';
        i++;
    }
    res[i] = '\0';
    res = strr(res);
    return (res);
}
int main()
{
    printf("%s\n", ft_itoa(-2147483648));
}
