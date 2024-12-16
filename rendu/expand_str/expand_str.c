#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char **argv)
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    int end = 0;
    int sp_tab = 0;

    while(argv[1][i] && (argv[1][i] ==' ' || argv[1][i] == '\t'))
        i++;

    while(argv[1][i])
    {
        if(argv[1][i] == ' ' ||  argv[1][i] == '\t')
        {
            sp_tab = 1;
            while(argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                i++;
            if(!argv[1][i])
                end = 1;
        }
        if(sp_tab == 0)
        {
            char h = argv[1][i];
            write(1,&h,1);
            i++;
        }
        if(sp_tab == 1 && end == 0)
        {
            sp_tab = 0;
            write(1,"   ",3);
        }
    }
    write(1,"\n",1);
    return 0;
}
