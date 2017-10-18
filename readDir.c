#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir ("./")) != NULL){
        while ((ent = readdir (dir)) != NULL){
            printf("%s\n", ent->d_name);
        }
        closedir (dir);
    }else{
        perror("Error");
    }
    return 0;
}