#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ftw.h>
#include <stdio.h>

#define TOTALNUMBEROFLINES 1000
#define BUFSIZE 1000


void err_sys(const char *const str)
{
    perror(str);
    fflush(stdout);
    exit(1);
}

int storeLinesInArray(const char *file, char lines[][BUFSIZE])
{
    return 0;
}

static int for_each_file(const char *filepath, int totalLines, const char *key, const char arr[][BUFSIZE])
{

    fprintf(stdout, "File name is = %s\n", filepath);
    fflush(stdout);


    return 0;
}

static int soner_each_time(const char *filepath, const struct stat *info,
                           int typeflag, struct FTW *ftwinfo)
{

    pid_t   pid = 0;
    char    buf[BUFSIZE];
    int     status;

    /* The variables are related to functions of reading file  */

    int     totalLines;
    char    arr[TOTALNUMBEROFLINES][BUFSIZE];
    int     retval;


    const char *const filename = filepath + ftwinfo->base;

    if (( pid = fork()) < 0) {
        perror("failed fork");
        exit(-1);
    }
    else if( pid > 0 ) // parent
    {
        if (typeflag == FTW_DP || typeflag == FTW_D)
        {
            sprintf(buf, "%*s%s\n\n", ftwinfo->level * 4, "", filepath);
            write(1, buf, strlen(buf));
            pid = wait(&status);
            if (pid == -1)
                perror("Failed to wait for child");
            else if (WIFEXITED(status) && !WEXITSTATUS(status))
                printf("parent [%d] reaped child [%d]\n", getpid(), pid);
            else if (WIFEXITED(status))
                printf("Child %ld terminated with return status %d\n",
                       (long)pid, WEXITSTATUS(status));
            else if (WIFSIGNALED(status))
                printf("Child %ld terminated due to uncaught signal %d\n",
                       (long)pid, WTERMSIG(status));
            else if (WIFSTOPPED(status))
                printf("Child %ld stopped due to signal %d\n",
                       (long)pid, WSTOPSIG(status));
        }
    }


    if (pid == 0) // child
    {
        if (typeflag == FTW_F)
        {
            sprintf(buf, "||| Child [%d] of parent [%d]: %s |||\n", getpid(), getppid(), filename);
            write(1, buf, strlen(buf));

            /* Both of them are about reading function */
            totalLines = storeLinesInArray(filename, arr);

            retval = for_each_file(filename, totalLines, "not needed now", arr);

            sprintf(buf, "||| Child [%d] of parent [%d] is about to exit |||\n", getpid(), getppid());
            write(1, buf, strlen(buf));
        }

        else if (typeflag == FTW_DP || typeflag == FTW_D)
        {
            sprintf(buf, "%*s%s\n\n", ftwinfo->level * 4, "", filepath);
            write(1, buf, strlen(buf));
        }

    }
    return 0;
}



int main(int argc, char *argv[])
{

    if (nftw("here is directory path", soner_each_time, 15, FTW_CHDIR)) {
        fprintf(stderr, "Failed directory.\n");
        exit(-1);
    }

    return 0;
}