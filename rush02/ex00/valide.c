#include <stdlib.h>
int    valide3(char **arr);
int    valide2(char *str, char **arr);
int    valide1(char *str, char **arr);
int    ft_strcmp(char *s1,    char *s2);

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 - *s2 == 0)
        {
            s2++;
            s1++;
        }
        else
            return (*s1 - *s2);
    }
    return (*s1 - *s2);
}
int valide1(char *str, char **arr)
{
    int i;

    i = 0;
    while ((str[i] >= '1' && str[i] <= '4') && ( str[i + 1] == ' ') && str[i])
    {
        i = i + 2;
    }
    i++;
    if (str[i] == '\0' && i == 31)
        return (valide2(str, arr));
    else
        return 0;
}

int    valide2(char *str, char **arr)
{
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    while (j < 2)
    {
      
        i = 0;
        while (i < 4)
        {
            arr[i][j] = str[k];
            i++;
            k = k + 2;
        }
        j++;
    }
    j = 0;
    while (j < 2)
    {
        i = 4;
        while (i < 8)
        {
            arr[i][j] = str[k];
            k = k + 2;
            i++;
        }
        j++;
    }
    return (valide3(arr));
}
int    valide3(char **arr)
{
    int f;
    int i;
    int    j;
    char data[9][2] = { "12", "13", "14", "22", "23" ,"21", "31", "41", "32"};

    i = 0;
    f = 0;
    while (f == 0 && i < 8)
    {
        j = 0;
        while (j < 9 && f!= 0)
        {
            f = ft_strcmp(arr[i], data[j]);
            j++;
        }
        i++;
    }
    if (f == 0)
        return (1);
    else
        return (0);
}
