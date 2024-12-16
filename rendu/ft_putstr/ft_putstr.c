#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int ft_size(char *str)
{
    int i =0;
    if(str)
    {
        while(str[i])
            i++;
    }
    return i;
}

void	ft_putstr(char *str)
{
    write(1,str,ft_size(str));
}

// int main()
// {
//     ft_putstr("hello");
//     return 0;
// }