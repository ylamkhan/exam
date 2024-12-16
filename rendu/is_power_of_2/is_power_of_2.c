#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

// 4 is power two because ----> 4 = 2*2
// 6 doesn't power two because ---> 6 !=(x)^2 

// int	    is_power_of_2(unsigned int n)
// {
//     if( n > 3)
//     {
//         unsigned int i = 0;
//         while(i <= (unsigned int)n/i)
//         {
//             if(i*i == n)
//                 return 1;
//             i++;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     printf("--->%d",is_power_of_2(4));
// }


int is_power_of_2(unsigned int n)
{
    if (n > 0 && (n & (n - 1)) == 0)
        return 1;
    return 0;
}

// int main()
// {
//     printf("---> %d\n", is_power_of_2(81));
//     return 0;
// }