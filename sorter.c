#include "sorter.h"

//Function to remove unnecessary leading and trailing whitespace characters.
//Returns a string with the whitespace removed.
char *trimwhitespace(char *str)
{
        while (isspace((unsigned char)*str)) // beginning spaces
                str++;
        if (*str == 0)
                return str;
        int index, i;
        i = 0;
        while (str[i] != '\0') //end spaces
        {
                if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
                {
                        index = i;
                }

                i++;
        }
        str[index + 1] = '\0';
        return str;
}

// Our own tokenizer function we created to prevent seg fault on empty entries.
// Uses strpbrk to find places where there are empty columns of a row entry.
// Returns a char * that is the next token in the line.

int gQuoteCount = 0;
char *strtokk(char *str, char const *delims)
{
        static char *src = NULL;
        char *n;
        char *ret = 0;

        if (str != NULL)
        {
                src = str;
        }
        if (src == NULL)
        {
                return NULL;
        }
        if ((n = strpbrk(src, delims)) != NULL)
        {
                *n = 0;
                ret = src;
                src = ++n;
        }
        else if (*src)
        {
                ret = src;
                src = NULL;
        }
        return ret;
}

// Function that prints our row struct out.
// This is used to reprint the newly sorted CSV file at the end.
void printRecord(struct Tokenizer *tk, FILE *f)
{
        fprintf(f, "%s,", tk->color);
        fprintf(f, "%s,", tk->director_name);
        if (tk->num_critic_for_reviews == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->num_critic_for_reviews);
        if (tk->duration == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->duration);
        if (tk->director_facebook_likes == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->director_facebook_likes);
        if (tk->actor_3_facebook_likes == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->actor_3_facebook_likes);
        fprintf(f, "%s,", tk->actor_2_name);
        fprintf(f, "%lu,", tk->actor_1_facebook_likes);
        if (tk->gross == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->gross);
        fprintf(f, "%s,", tk->genres);
        fprintf(f, "%s,", tk->actor_1_name);
        if (strstr(tk->movie_title, ",") != NULL)
        {
                fprintf(f, "\"%s\",", tk->movie_title);
        }
        else
        {
                fprintf(f, "%s,", tk->movie_title);
        }
        fprintf(f, "%lu,", tk->num_voted_users);
        fprintf(f, "%lu,", tk->cast_total_facebook_likes);
        fprintf(f, "%s,", tk->actor_3_name);
        fprintf(f, "%lu,", tk->facenumber_in_poster);
        fprintf(f, "%s,", tk->plot_keywords);
        fprintf(f, "%s,", tk->movie_imdb_link);
        fprintf(f, "%lu,", tk->num_user_for_reviews);
        fprintf(f, "%s,", tk->language);
        fprintf(f, "%s,", tk->country);
        fprintf(f, "%s,", tk->content_rating);
        if (tk->budget == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->budget);
        if (tk->title_year == 0)
                fprintf(f, "%s", ",");
        else
                fprintf(f, "%lu,", tk->title_year);
        fprintf(f, "%lu,", tk->actor_2_facebook_likes);
        if (tk->imdb_score == 6)
                fprintf(f, "%d,", 6);
        else
                fprintf(f, "%.1f,", tk->imdb_score);

        if (tk->aspect_ratio == 16.00)
                fprintf(f, "%.0f,", tk->aspect_ratio);
        else if (tk->aspect_ratio == 0)
                fprintf(f, "%s", ",");
        else if (tk->aspect_ratio == 0.00)
                fprintf(f, "%.0f,", tk->aspect_ratio);
        else
                fprintf(f, "%.2f,", tk->aspect_ratio);

        fprintf(f, "%lu", tk->movie_facebook_likes);
        fprintf(f, "\n");
}

// This function creates a tokenizer struct out a char * line of the CSV file.
// Returns the newly created struct with everything malloc'd correctly.
struct Tokenizer *TKCreate(char *ts)
{
        struct Tokenizer *newNode = (struct Tokenizer *)malloc(sizeof(struct Tokenizer));
        if (strlen(ts) == 0)
        {
                return NULL;
        }
        if (strstr(ts, "\"") != NULL)
        {
                //entry has a comma in the title
                char *token;
                unsigned long int temp = 0;
                char *ptr = NULL;
                float temp2 = 0.0;
                token = strtokk(ts, ",");
                newNode->color = malloc(strlen(token) + 1);
                strcpy(newNode->color, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->director_name = malloc(strlen(token) + 1);
                strcpy(newNode->director_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_critic_for_reviews = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->duration = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->director_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_3_facebook_likes = temp;
                token = strtokk(NULL, ",");
                newNode->actor_2_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_2_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_1_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->gross = temp;
                token = strtokk(NULL, ",");
                newNode->genres = malloc(strlen(token) + 1);
                strcpy(newNode->genres, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->actor_1_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_1_name, trimwhitespace(token));

                while (gQuoteCount != 2)
                {
                        token = strtokk(NULL, "\"");
                        newNode->movie_title = malloc(strlen(token) + 1);
                        strcpy(newNode->movie_title, trimwhitespace(token));
                        gQuoteCount++;
                }
                if (gQuoteCount == 2)
                {
                        gQuoteCount = 0;
                }
                token = strtokk(NULL, ",");
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_voted_users = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->cast_total_facebook_likes = temp;
                token = strtokk(NULL, ",");
                newNode->actor_3_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_3_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->facenumber_in_poster = temp;
                token = strtokk(NULL, ",");
                newNode->plot_keywords = malloc(strlen(token) + 1);
                strcpy(newNode->plot_keywords, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->movie_imdb_link = malloc(strlen(token) + 1);
                strcpy(newNode->movie_imdb_link, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_user_for_reviews = temp;
                token = strtokk(NULL, ",");
                newNode->language = malloc(strlen(token) + 1);
                strcpy(newNode->language, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->country = malloc(strlen(token) + 1);
                strcpy(newNode->country, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->content_rating = malloc(strlen(token) + 1);
                strcpy(newNode->content_rating, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->budget = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->title_year = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_2_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp2 = atof(token);
                newNode->imdb_score = temp2;
                token = strtokk(NULL, ",");
                temp2 = atof(token);
                newNode->aspect_ratio = temp2;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->movie_facebook_likes = temp;
        }
        else
        {
                //  entry doesnt have comma in title
                char *token;
                unsigned long int temp = 0;
                char *ptr = NULL;
                float temp2 = 0.0;
                token = strtokk(ts, ",");
                newNode->color = malloc(strlen(token) + 1);
                strcpy(newNode->color, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->director_name = malloc(strlen(token) + 1);
                strcpy(newNode->director_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_critic_for_reviews = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->duration = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->director_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_3_facebook_likes = temp;
                token = strtokk(NULL, ",");
                newNode->actor_2_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_2_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_1_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->gross = temp;
                token = strtokk(NULL, ",");
                newNode->genres = malloc(strlen(token) + 1);
                strcpy(newNode->genres, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->actor_1_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_1_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->movie_title = malloc(strlen(token) + 1);
                strcpy(newNode->movie_title, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_voted_users = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->cast_total_facebook_likes = temp;
                token = strtokk(NULL, ",");
                newNode->actor_3_name = malloc(strlen(token) + 1);
                strcpy(newNode->actor_3_name, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->facenumber_in_poster = temp;
                token = strtokk(NULL, ",");
                newNode->plot_keywords = malloc(strlen(token) + 1);
                strcpy(newNode->plot_keywords, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->movie_imdb_link = malloc(strlen(token) + 1);
                strcpy(newNode->movie_imdb_link, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->num_user_for_reviews = temp;
                token = strtokk(NULL, ",");
                newNode->language = malloc(strlen(token) + 1);
                strcpy(newNode->language, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->country = malloc(strlen(token) + 1);
                strcpy(newNode->country, trimwhitespace(token));
                token = strtokk(NULL, ",");
                newNode->content_rating = malloc(strlen(token) + 1);
                strcpy(newNode->content_rating, trimwhitespace(token));
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->budget = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->title_year = temp;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->actor_2_facebook_likes = temp;
                token = strtokk(NULL, ",");
                temp2 = atof(token);
                newNode->imdb_score = temp2;
                token = strtokk(NULL, ",");
                temp2 = atof(token);
                newNode->aspect_ratio = temp2;
                token = strtokk(NULL, ",");
                temp = strtoul(token, &ptr, 10);
                newNode->movie_facebook_likes = temp;
        }
        return newNode;
}

// Function to create the director structure for the extra credit.
struct directorRating *DRcreate(char *director_name, double rating, int appearances)
{
        struct directorRating *newNode = (struct directorRating *)malloc(sizeof(struct directorRating));
        newNode->directorName = malloc(strlen(director_name) + 1);
        strcpy(newNode->directorName, director_name);
        newNode->directorRating = rating;
        newNode->appearances = appearances;
        return newNode;
}

// Function to free all the memory allocated for the tokenizer structs.
void TKDestroy(struct Tokenizer *tk)
{
        if (tk->color != NULL)
                free(tk->color);
        if (tk->director_name != NULL)
                free(tk->director_name);
        if (tk->actor_2_name != NULL)
                free(tk->actor_2_name);
        if (tk->genres != NULL)
                free(tk->genres);
        if (tk->actor_1_name != NULL)
                free(tk->actor_1_name);
        if (tk->movie_title != NULL)
                free(tk->movie_title);
        if (tk->actor_3_name != NULL)
                free(tk->actor_3_name);
        if (tk->plot_keywords != NULL)
                free(tk->plot_keywords);
        if (tk->movie_imdb_link != NULL)
                free(tk->movie_imdb_link);
        if (tk->language != NULL)
                free(tk->language);
        if (tk->country != NULL)
                free(tk->country);
        if (tk->content_rating != NULL)
                free(tk->content_rating);
        /*if (tk != NULL)
                free(tk);*/
}

// Function to free memory allocation for the extra credit.
void TopDestroy(struct directorRating *dr)
{
        if (dr->directorName != NULL)
                free(dr->directorName);
}

// Function used in testing to print all the columns out to see if order was correct.
void printShort(struct Tokenizer *tk, char *columnName)
{

        if (strcmp(columnName, "num_critic_for_reviews") == 0)
        {
                printf("%lu\n", tk->num_critic_for_reviews);
        }

        if (strcmp(columnName, "duration") == 0)
        {
                printf("%lu\n", tk->duration);
        }

        if (strcmp(columnName, "director_facebook_likes") == 0)
        {
                printf("%lu\n", tk->director_facebook_likes);
        }

        if (strcmp(columnName, "actor_3_facebook_likes") == 0)
        {
                printf("%lu\n", tk->actor_3_facebook_likes);
        }

        if (strcmp(columnName, "actor_1_facebook_likes") == 0)
        {
                printf("%lu\n", tk->actor_1_facebook_likes);
        }

        if (strcmp(columnName, "gross") == 0)
        {
                printf("%lu\n", tk->gross);
        }

        if (strcmp(columnName, "num_voted_users") == 0)
        {
                printf("%lu\n", tk->num_voted_users);
        }

        if (strcmp(columnName, "cast_total_facebook_likes") == 0)
        {
                printf("%lu\n", tk->cast_total_facebook_likes);
        }

        if (strcmp(columnName, "facenumber_in_poster") == 0)
        {
                printf("%lu\n", tk->facenumber_in_poster);
        }

        if (strcmp(columnName, "num_user_for_reviews") == 0)
        {
                printf("%lu\n", tk->num_user_for_reviews);
        }

        if (strcmp(columnName, "budget") == 0)
        {
                printf("%lu\n", tk->budget);
        }

        if (strcmp(columnName, "title_year") == 0)
        {
                printf("%lu\n", tk->title_year);
        }

        if (strcmp(columnName, "actor_2_facebook_likes") == 0)
        {
                printf("%lu\n", tk->actor_2_facebook_likes);
        }

        if (strcmp(columnName, "movie_facebook_likes") == 0)
        {
                printf("%lu\n", tk->movie_facebook_likes);
        }
        if (strcmp(columnName, "color") == 0)
        {
                printf("%s\n", tk->color);
        }
        if (strcmp(columnName, "director_name") == 0)
        {
                printf("%s\n", tk->director_name);
        }

        if (strcmp(columnName, "actor_2_name") == 0)
        {
                printf("%s\n", tk->actor_2_name);
        }

        if (strcmp(columnName, "genres") == 0)
        {
                printf("%s\n", tk->genres);
        }

        if (strcmp(columnName, "actor_1_name") == 0)
        {
                printf("%s\n", tk->actor_1_name);
        }

        if (strcmp(columnName, "movie_title") == 0)
        {
                printf("%s\n", tk->movie_title);
        }

        if (strcmp(columnName, "actor_3_name") == 0)
        {
                printf("%s\n", tk->actor_3_name);
        }

        if (strcmp(columnName, "plot_keywords") == 0)
        {
                printf("%s\n", tk->plot_keywords);
        }

        if (strcmp(columnName, "movie_imdb_link") == 0)
        {
                printf("%s\n", tk->movie_imdb_link);
        }

        if (strcmp(columnName, "language") == 0)
        {
                printf("%s\n", tk->language);
        }

        if (strcmp(columnName, "country") == 0)
        {
                printf("%s\n", tk->country);
        }

        if (strcmp(columnName, "content_rating") == 0)
        {
                printf("%s\n", tk->content_rating);
        }

        if (strcmp(columnName, "imdb_score") == 0)
        {
                printf("%f\n", tk->imdb_score);
        }
        if (strcmp(columnName, "aspect_ratio") == 0)
        {
                printf("%f\n", tk->aspect_ratio);
        }
}

void sorter(char *columnName, FILE *moviefile, char *outputDir, char *filename)
{
        int line = 0;

        //getting the column names
        char bufferColumn[1024];
        bufferColumn[0] = '\0';
        char stringnn[1024];
        int blah = 0;
        stringnn[0] = '\0';

        if(fgets(bufferColumn,1024,moviefile) != NULL)
        {
                blah = 1;
        }
        if (blah == 0)
        {
                printf("ERROR: Empty file.\n");
        }

        struct Tokenizer *head = NULL, *curr = NULL, *newNode = NULL;

        //getting the rest of the rows
        while (fgets(stringnn, 1024, moviefile) != NULL)
        {
                // create tokenizer struct and store at next open spot in array
                newNode = TKCreate(stringnn);
                if (newNode != NULL)
                { // to protect against empty lines in the file
                        if (head == NULL)
                        {
                                head = newNode;
                                curr = newNode;
                        }
                        else
                        {
                                curr->next = newNode;
                                curr = newNode;
                        }
                        curr->next = NULL;
                        line++;
                }
                // printf("%s\n", buffer);
        }

        if (line == 0)
        {
                printf("Error: No Entries in CSV to sort.\n");
        }

        /*
           Creating a new file and new file name.

        */
        //  printf("\ngot here 3\n");

        char *newfilename = malloc(strlen(filename) + strlen(columnName) + 9);
        filename[strlen(filename) - 4] = '\0';
        strcpy(newfilename, filename);
        strcat(newfilename, "-sorted-");
        strcat(newfilename, columnName);
        strcat(newfilename, ".csv");

        //printf("\nnew file name:  %s", newfilename);

        char outputNewDir[1024];
        strcpy(outputNewDir, outputDir);
        strcat(outputNewDir, "/");
        strcat(outputNewDir, newfilename);

        //printf("\noutputdirectory:%s\n", outputNewDir);

        FILE *outputFile = fopen(outputNewDir, "w+");
        //  printf("\n\n----file created----\n\n");

        struct Tokenizer rows[line];
        struct Tokenizer *ptr = head;
        int j = 0;
        do
        {
                rows[j] = *ptr;
                ptr = ptr->next;
                j++;
        } while (ptr != NULL);

        int l = 0, r = line - 1;

        if ((strcmp(columnName, "num_critic_for_reviews") == 0) || (strcmp(columnName, "duration") == 0) || (strcmp(columnName, "director_facebook_likes") == 0) || (strcmp(columnName, "actor_3_facebook_likes") == 0) || (strcmp(columnName, "actor_1_facebook_likes") == 0) || (strcmp(columnName, "gross") == 0) || (strcmp(columnName, "num_voted_users") == 0) || (strcmp(columnName, "cast_total_facebook_likes") == 0) || (strcmp(columnName, "facenumber_in_poster") == 0) || (strcmp(columnName, "num_user_for_reviews") == 0) || (strcmp(columnName, "budget") == 0) ||
            (strcmp(columnName, "title_year") == 0) || (strcmp(columnName, "actor_2_facebook_likes") == 0) || (strcmp(columnName, "movie_facebook_likes") == 0))
        {
                mergesortInt(rows, columnName, l, r);
        }
        else if ((strcmp(columnName, "imdb_score") == 0) || (strcmp(columnName, "aspect_ratio") == 0))
        {
                mergesortFloat(rows, columnName, l, r);
        }
        else if ((strcmp(columnName, "color") == 0) || (strcmp(columnName, "director_name") == 0) || (strcmp(columnName, "actor_2_name") == 0) || (strcmp(columnName, "genres") == 0) || (strcmp(columnName, "actor_1_name") == 0) || (strcmp(columnName, "movie_title") == 0) || (strcmp(columnName, "actor_3_name") == 0) || (strcmp(columnName, "plot_keywords") == 0) || (strcmp(columnName, "movie_imdb_link") == 0) || (strcmp(columnName, "language") == 0) || (strcmp(columnName, "country") == 0) ||
                 (strcmp(columnName, "content_rating") == 0))
        {
                mergesortString(rows, columnName, l, r);
        }
        else
        {
                printf("Not a valid column to sort.\n");
        }

        int z = 0;
        fprintf(outputFile, "%s", bufferColumn);
        while (z < line)
        {
                printRecord(&rows[z], outputFile);
                z++;
        }

        fclose(outputFile);
}

const char *get_filename_ext(const char *filename)
{
        //printf("in file ext funct\n");
        const char *dot = strrchr(filename, '.');
        if (!dot || dot == filename)
                return "";
        return dot + 1;
}

int is_Valid_CSV(struct dirent *file)
{
        //printf("%s\n",get_filename_ext(file->d_name));
        if (strstr(file->d_name, "-sorted-"))
        {
                return -1;
        }
        if (strcmp(get_filename_ext(file->d_name), "csv") == 0)
        {
                return 0;
        }
        return -1;
}

void sortDir(char *path, char *columnName, char *outputdirectory, int obool, FILE * meta)
{
        int pidCount = 0;
        int currentPids = 0;
        char fullpath[1024];
        strcpy(fullpath, path);
        struct dirent *currentDirFile; // Pointer for directory entry
        DIR *currentDir = opendir(path);
        //int initial = 1;
        if (currentDir == NULL) // opendir returns NULL if couldn't open directory
        {
                printf("Could not open current directory\n");
        }

        while ((currentDirFile = readdir(currentDir)) != NULL)
        {
                //current dirent is a folder that needs to be forked
                if (currentDirFile->d_type == DT_DIR)
                {
                        // fork this new directory to be processed
                        if (strcmp(currentDirFile->d_name, ".") == 0)
                        {
                                continue;
                        }
                        if (strcmp(currentDirFile->d_name, "sorter.dSYM") == 0)
                        {
                                continue;
                        }
                        if (strcmp(currentDirFile->d_name, "..") == 0)
                        {
                                continue;
                        }
                        if (strcmp(currentDirFile->d_name, ".git") == 0)
                        {
                                continue;
                        }
                        // need to create a new path with oldpath/newpath


                        int pid = fork();
                        if (pid < 0)
                        {
                                printf("error\n");
                        }
                        if (pid == 0)
                        { // child
                                strcat(fullpath, "/");
                                strcat(fullpath, currentDirFile->d_name);
                                path = fullpath;
                                currentDir = opendir(fullpath);

                        }
                        if (pid > 0)
                        {
                                currentPids++;
                                printf("%d, ", pid);
                                fflush(stdout);
                                fprintf(meta, "Parent with PID: %d, forked PID %d to process directory: %s\n", getppid(), pid, currentDirFile->d_name);
                                fflush(meta);

                        }
                }
                else if (is_Valid_CSV(currentDirFile) == 0)
                {
                        //fork a sort on that file
                        char outputPath[1024];
                        strcpy(outputPath, path);
                        char fullpath[1024];
                        strcpy(fullpath, path);
                        strcat(fullpath, "/");
                        strcat(fullpath, currentDirFile->d_name);

                        int pid = fork();


                        if (pid < 0)
                        {
                                printf("error\n");
                        }
                        if (pid == 0)
                        { // child
                        
                                FILE *sortfileptr = fopen(fullpath, "r+");
                                if (obool == 0)
                                {
                                        outputdirectory = outputPath;
                                }
                                sorter(columnName, sortfileptr, outputdirectory, currentDirFile->d_name);
                                fclose(sortfileptr);
                                exit(1);
                        }
                        if (pid > 0)
                        {
                                currentPids++;
                                printf("%d, ", pid);
                                fflush(stdout);
                                fprintf(meta, "Parent with PID: %d, forked PID %d to process valid CSV FILE: %s\n", getppid(), pid, currentDirFile->d_name);
                                fflush(meta);
                        }
                }
                // INVALID file, not a directory or a valid csv file
                else
                {
                        continue;
                }
        }

        int i = 0;
        // wait for all child processes to finish
        // printf("Pids of parent: %d\n", currentPids);
        for (i = 0; i < currentPids; i++)
        {
                int result = -1;
                wait(&result);
                pidCount = pidCount + (result/255);
        }

        exit(pidCount+1);
}

int main(int argc, char **argv)
{
        //need to correct this
        if (argc < 3)
        {
                printf("Invalid amount of arguments.");
                return 1;
        }

        char *columnName = argv[2];
        char *directory;
        char *outputdirectory;
        char buffer[1024];

        if ((strcmp(columnName, "num_critic_for_reviews") == 0) || (strcmp(columnName, "duration") == 0) || (strcmp(columnName, "director_facebook_likes") == 0) || (strcmp(columnName, "actor_3_facebook_likes") == 0) || (strcmp(columnName, "actor_1_facebook_likes") == 0) || (strcmp(columnName, "gross") == 0) || (strcmp(columnName, "num_voted_users") == 0) || (strcmp(columnName, "cast_total_facebook_likes") == 0) || (strcmp(columnName, "facenumber_in_poster") == 0) || (strcmp(columnName, "num_user_for_reviews") == 0) || (strcmp(columnName, "budget") == 0) || (strcmp(columnName, "title_year") == 0) || (strcmp(columnName, "actor_2_facebook_likes") == 0) || (strcmp(columnName, "movie_facebook_likes") == 0)
        ||(strcmp(columnName, "imdb_score") == 0) || (strcmp(columnName, "aspect_ratio") == 0) ||(strcmp(columnName, "color") == 0) || (strcmp(columnName, "director_name") == 0) || (strcmp(columnName, "actor_2_name") == 0) || (strcmp(columnName, "genres") == 0) || (strcmp(columnName, "actor_1_name") == 0) || (strcmp(columnName, "movie_title") == 0) || (strcmp(columnName, "actor_3_name") == 0) || (strcmp(columnName, "plot_keywords") == 0) || (strcmp(columnName, "movie_imdb_link") == 0) || (strcmp(columnName, "language") == 0) || (strcmp(columnName, "country") == 0) || (strcmp(columnName, "content_rating") == 0))
        {
                ;                
        } 
        else
        {
                printf("Not a valid column to sort.\n");
                return -1;
        }
        // 1 if a output directory is specified, 0 if no
        int obool = 0;

        //printf("%d\n", argc);
        //printf("%s  %s   \n",argv[0],argv[1],argv[2],argv[3],argv[4] );

        if (argc == 3)
        {
                getcwd(buffer, sizeof(buffer));
                directory = buffer;
                outputdirectory = buffer;
        }
        else if (argc == 5)
        {
                if (strcmp(argv[3], "-d") == 0)
                {
                        directory = argv[4];
                        getcwd(buffer, sizeof(buffer));
                        outputdirectory = buffer;
                }
                else if(strcmp(argv[3], "-o") == 0)
                {
                        getcwd(buffer, sizeof(buffer));
                        directory = buffer;
                        outputdirectory = argv[4];
                        obool = 1;
                }
                else{
                printf("Invalid input.\n");
                return -1;
                }
        }
        else if (argc == 7)
        {
                if((strcmp(argv[3], "-d") == 0) && (strcmp(argv[5], "-o") == 0)){
                directory = argv[4];
                outputdirectory = argv[6];
                obool = 1;
                }
                else 
                if((strcmp(argv[3], "-o") == 0) && (strcmp(argv[5], "-d") == 0)){
                directory = argv[6];
                outputdirectory = argv[4];
                obool = 1;
                }
                else{
                printf("Invalid input.\n");
                return -1;
                }
        }
        else
        {
                printf("Invalid input.\n");
                return -1;
        }

        /* look for arguments here -c column name, -d  starting directory  -- could also be black->curr dir,
         -o output directory*/

        FILE * meta = fopen("metadata.txt", "w+");


        printf("Initial PID: %d\n", getpid());
        printf("PIDS of all child processes: ");
        fflush(stdout);
        pid_t temp = fork();

        if(temp == 0){
           sortDir(directory, columnName, outputdirectory, obool, meta);
        }
        if(temp > 0){
                fprintf(meta, "Parent with PID: %d, forked PID %d to process directory: %s\n", getppid(), temp, directory);
                fflush(meta);
                printf("%d ", temp);
                int waiting = -1;
                wait(&waiting);
                printf("\nTotal number of processes: %d\n", (waiting/255)+1);
                fclose(meta);
        }

        // traverse through directories
        // looking for csv files
        // then fork and call sorter(inputfile, outputfile, outputdirectory)
        // inside sorter first check if the file is a valid movie file to sort
        // sort it and then output to the file specified and the directory specified

        return 0;
}
