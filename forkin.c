#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "sorter.h"

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}



int is_Valid_CSV(struct dirent * file) {
	//printf("%s\n", file->d_name);
	if(strcmp(get_filename_ext(file->d_name), ".csv")){
		return 0;
	}
    return -1;

}


void sortDir(char* path){
struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir(path);
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        
    }
    while ((de = readdir(dr)) != NULL){
    	printf("%s\n", de->d_name);
         if(de->d_type == DT_DIR){
         	//printf("directory\n");
         	// fork this new directory to be processed
         	path = de->d_name;
         //	printf("%s\n", path);
         	//continue;
         //	printf("directory\n");
         	//sortDir(path);
     	}	
     	else{
     		if(is_Valid_CSV(de) == 0){
     			//fork a sort on that file
 
     			//else continue
     			//printf("file\n");
     			//continue;
     		}
     	}

     }
 
    closedir(dr); 
}

int main(int argc, char **argv){
//need to correct this
 if (argc < 3)
        {
                printf("Invalid amount of arguments.");
                return 1;
        }

char * columnName = argv[2];
char * directory;
char * outputdirectory;
char buffer[1024];

printf("%d\n", argc);
printf("%s  %s  %s  %s  %s\n",argv[0],argv[1],argv[2],argv[3],argv[4] );

if(argc == 3){
getcwd(buffer,sizeof(buffer));
		directory = buffer;
}
else
if(argc == 5){
if (strcmp(argv[3], "-d") == 0){
	directory = argv[4];
	getcwd(buffer,sizeof(buffer));
	outputdirectory = buffer;
}
else{
	getcwd(buffer,sizeof(buffer));
	directory = buffer;
	outputdirectory = argv[4];

}
}
else
if(argc == 7){
directory = argv[4];
outputdirectory = argv[6];
}
else{
	printf("Invalid input.\n");
	return -1;
}


/* look for arguments here -c column name, -d  starting directory  -- could also be black->curr dir, 
 -o output directory*/


//listdir(".", 0);



sortDir(directory);








// traverse through directories
      // looking for csv files
        // then fork and call sorter(inputfile, outputfile, outputdirectory)
        // inside sorter first check if the file is a valid movie file to sort
        // sort it and then output to the file specified and the directory specified






return 0;
}