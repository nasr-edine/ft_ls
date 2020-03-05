#include <stdio.h>
#include <dirent.h> // function for handling directories
#include <stdlib.h> // exit

int main(int argc, char const *argv[])
{
    DIR *dir;
    struct dirent *dp;

    dir = opendir("toto");
    if (!dir)
    {
        perror("NULL");
        exit(EXIT_FAILURE);
    }
    while ((dp = readdir(dir)) != NULL) 
    {
        if (dp->d_name[0] != '.')
        {
            printf("%s\n", dp->d_name);
        }
    }
    int ret;
    if ((ret = closedir(dir)) == -1)
    {
        perror("CLOSE KO");
        exit(EXIT_FAILURE);
    }
    return 0;
}
