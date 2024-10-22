#include <stdlib.h>
#include <string.h>


typedef struct    s_list
{
    struct s_list *next;
    int nb;
    void    *data;
}    t_list;

void ft_list_remove(t_list  **begin_list, void *data_ref, int (*cmp)())
{
  int i =0;
    t_list *l;
    t_list *p;
    l = *begin_list;

    p = l;
    while (l)
    {
      if (!cmp(l->data, data_ref) && i == 0)
        {
            p = l->next;
            free(l);
            l = p;
        }
        else if (!cmp(l->data, data_ref))
        {
            p->next = l->next;
            free(l);
            l = p;
        }
        p = l;
        l = l->next;
        i++;
    }
    return (begin_list);
}
int main()
{
  void *ref = "up";
    t_list *test = malloc(sizeof(t_list));
    test -> data = "up";
    test->nb = 1;
    test->next = malloc(sizeof(t_list));
    test->next->data = "up";
    test->next->nb = 2;
    test->next->next = malloc(sizeof(t_list));
    test->next->next->data = "pe";
    test->next->next->nb = 3;
    test->next->next->next = NULL;
    ft_list_remove(&test, ref, strcmp);
}
