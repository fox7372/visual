#include"±êÍ·.h"
#include<time.h>
typedef struct
{
    lie* node;
    int i;
}t;
t recycle(lie* head)
{
    t resuit;
    lie* m = head;
    lie* n = head;
    n = n->next;
    m = n->next;
    int i = 0;
    while (m != NULL)
    {
        n = n->next;
        m = m->next->next;
        if (m == n)
        {
            i++;
            break;
        }
    }
    resuit.i = i;
    resuit.node = NULL;
    if (i)
    {
        m = head;
        while (m != n)
        {
            m = m->next;
            n = n->next;
        }
        resuit.node = m;
    }
    return resuit;
}



t judge(lie* head1, lie* head2)
{
    lie* p1 = head1;
    t h1 = recycle(head1);
    lie* p2 = head2;
    t h2 = recycle(head2);
    t resuit;
    resuit.i = 0;
    resuit.node = NULL;
    if (h1.i == 0 && h2.i == 0)
    {
        int n1 = 0, n2 = 0;
        while (p1 != NULL)
        {
            p1 = p1->next;
            n1++;
        }
        while (p2 != NULL)
        {
            p2 = p2->next;
            n2++;
        }
        lie* np1 = (n1 - n2) > 0 ? head1 : head2;
        lie* np2 = (np1 == head1) ? head2 : head1;
        int num = (unsigned int)(n1 - n2);
        for (int i = 0; i<num; i++)
        {
            np1 = np1->next;
        }
        while (np1 != NULL && np2 != NULL)
        {
            np1 = np1->next;
            np2 = np2->next;
            if (np1 == np2)
            {
                resuit.i = 1;
                resuit.node = np1;
                break;
            }
        }
    }
    else if (h1.i == 1 && h2.i == 1)
    {
        if (h1.node == h2.node)
        {
            resuit.i = 1;
            int n1 = 0, n2 = 0;
            while (p1 != h1.node)
            {
                p1 = p1->next;
                n1++;
            }
            while (p2 !=h1.node)
            {
                p2 = p2->next;
                n2++;
            }
            lie* np1 = (n1 - n2) > 0 ? p1 : p2;
            lie* np2 = (np1 == p1) ? p2 : p1;
            int num = (unsigned int)(n1 - n2);
            for (int i = 0; i++; i < num)
            {
                np1 = np1->next;
            }
            while (np1 != h1.node && np2 != h1.node)
            {
                np1 = np1->next;
                np2 = np2->next;
                if (np1 == np2)
                {
                    resuit.i = 1;
                    resuit.node = np1;
                    break;
                }
            }
           
        }
        else
        {
            lie* m = h2.node->next;
            while (m != h2.node)
            {
                m = m->next;
                if (m == h1.node)
                {
                    resuit.i = 1;
                    resuit.node = h1.node;
                    break;
                }
            }
        }
    }
    return resuit;
}

 

int main() 
{
    srand((unsigned int)time(NULL));
    int r = rand() % 10 + 1;
	int arr[10] = { 0 };
    lie* head = creatlist(arr, 10);
    lie* p = head;
    lie* g = head;
    for (int i = 0; i++; i < 10)
    {
        p = p->next;
    }
    for (int i = 0; i++; i < r)
    {
        g = g->next;
    }
    p->next = g;
    t resuit = recycle(head);
    printf("%d", resuit.i);
}
