#include "list.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int cmp(int a, int b)
{
    if(a <= b)
        return 1;
    else
	    return 0;
}

t_list *create_node(int data)
{
    t_list *new_elemant = NULL;
    new_elemant = malloc(sizeof(t_list));
    if (!new_elemant)
        return NULL;
    new_elemant->next = NULL;
    new_elemant->data = data;
    return new_elemant;
}

t_list *add_element_back(t_list *list, t_list *new_element)
{
    if (!new_element)
        return list;

    if (!list)
    {
        return new_element;
    }

    t_list *current = list;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_element;
    return list; 
}

t_list *add_element_font(t_list *list, t_list *new_element)
{
    if(!new_element)
        return list;
    if(!list)
        return new_element;
    new_element->next = list;
    return new_element;
}

t_list *add_element_in_position(t_list *list, t_list *new_element, int index)
{
    if(!new_element)
        return list;
    if(index == 0)
        return add_element_font(list, new_element);
    int pos = 0;
    t_list *courrent = list;
    while(courrent)
    {
        if(pos == index)
        {
            new_element->next = courrent->next;
            courrent->next = new_element;
            return list;
        }
        pos++;
        courrent  = courrent->next;
    }
    return list;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    if(!lst || !lst->next)
        return lst;
    t_list *current = lst;
    t_list *tmp = NULL;
    while(current)
    {
        tmp = current->next;
        while(tmp)
        {
            if(cmp(current->data, tmp->data) == 0)
            {
                int c = current->data;
                current->data = tmp->data;
                tmp->data = c;
            }
            tmp = tmp->next;
        }
        current = current->next;
    }
    return lst;
}

void display_list(t_list *list)
{
    while(list)
    {
        printf("-->%d",list->data);
        list = list->next;
    }
    printf("\n");
}


int main()
{
    t_list *list=NULL;
    list = add_element_back(list,create_node(0));
    list = add_element_back(list,create_node(8));
    list = add_element_back(list,create_node(4));
    list = add_element_back(list,create_node(10));
    list = add_element_back(list,create_node(-10));
    list = add_element_back(list,create_node(7));
    list = add_element_back(list,create_node(20));
    list = add_element_back(list,create_node(-50));
    list = add_element_back(list,create_node(50));
    list = add_element_back(list,create_node(-44));
    list = add_element_back(list,create_node(44));
    list = add_element_back(list,create_node(30));

    list = add_element_font(list,create_node(100));
    list = add_element_font(list,create_node(1000));
    list = add_element_font(list,create_node(200));
    list = add_element_font(list,create_node(2000));
    list = add_element_font(list,create_node(400));
    list = add_element_font(list,create_node(40000));

    list = add_element_in_position(list, create_node(100000000), 5);
    list = add_element_in_position(list, create_node(200000000), 5);
    list = add_element_in_position(list, create_node(200000000), 0);
    list = add_element_in_position(list, create_node(8888), 0);

    display_list(list);
    list = sort_list(list, cmp);
    
    return 0;
}
