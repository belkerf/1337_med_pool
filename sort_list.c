#include <stdlib.h>


typedef struct    s_list
{
    struct s_list *next;
    int nbr;
    void    *data;
}    t_list;
int order(int a, int b)
{
  return(a <= b);
}

t_list *sort_list(t_list* lst, int (*cmp) (int, int))
{
    int i = 0;
    t_list *l;
    t_list *p;
    int tmp1;
    

    l = lst;
    p = l;
    while (l->next)
    {
        if (!cmp(l->nbr, l->next->nbr))
        {
            tmp1 = l->nbr;
            l->nbr = l->next->nbr;
            l->next->nbr = tmp1;
            l = lst;
            continue;
        }
        p = l;
        l = l->next;
    }
    return lst;
}
int main()
{
  void *ref = "up";
    t_list *test = malloc(sizeof(t_list));
    test -> data = "up";
    test->nbr = 5;
    test->next = malloc(sizeof(t_list));
    test->next->data = "up";
    test->next->nbr = 4;
    test->next->next = malloc(sizeof(t_list));
    test->next->next->data = "pe";
    test->next->next->nbr = 2;
    test->next->next->next = NULL;
    test = sort_list(test, order);
}
