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
void printRecord(struct Tokenizer *tk)
{
        printf("%s,", tk->color);
        printf("%s,", tk->director_name);
        if (tk->num_critic_for_reviews == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->num_critic_for_reviews);
        if (tk->duration == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->duration);
        if (tk->director_facebook_likes == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->director_facebook_likes);
        if (tk->actor_3_facebook_likes == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->actor_3_facebook_likes);
        printf("%s,", tk->actor_2_name);
        printf("%lu,", tk->actor_1_facebook_likes);
        if (tk->gross == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->gross);
        printf("%s,", tk->genres);
        printf("%s,", tk->actor_1_name);
        if (strstr(tk->movie_title, ",") != NULL)
        {
                printf("\"%s\",", tk->movie_title);
        }
        else
        {
                printf("%s,", tk->movie_title);
        }
        printf("%lu,", tk->num_voted_users);
        printf("%lu,", tk->cast_total_facebook_likes);
        printf("%s,", tk->actor_3_name);
        printf("%lu,", tk->facenumber_in_poster);
        printf("%s,", tk->plot_keywords);
        printf("%s,", tk->movie_imdb_link);
        printf("%lu,", tk->num_user_for_reviews);
        printf("%s,", tk->language);
        printf("%s,", tk->country);
        printf("%s,", tk->content_rating);
        if (tk->budget == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->budget);
        if (tk->title_year == 0)
                printf("%s", ",");
        else
                printf("%lu,", tk->title_year);
        printf("%lu,", tk->actor_2_facebook_likes);
        if (tk->imdb_score == 6)
                printf("%d,", 6);
        else
                printf("%.1f,", tk->imdb_score);

        if (tk->aspect_ratio == 16.00)
                printf("%.0f,", tk->aspect_ratio);
        else if (tk->aspect_ratio == 0)
                printf("%s", ",");
        else if (tk->aspect_ratio == 0.00)
                printf("%.0f,", tk->aspect_ratio);
        else
                printf("%.2f,", tk->aspect_ratio);

        printf("%lu", tk->movie_facebook_likes);
        printf("\n");
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
void listdir(const char *name, int indent)
{
        DIR *dir = NULL;
        struct dirent *entry;

        if (!(dir = opendir(name)))
                return;
        while ( (entry = readdir(dir)) != NULL)
        {
                if (entry->d_type == DT_DIR)
                {
                        char path[1024];
                        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                                continue;
                        snprintf(path, sizeof(path), "%s%s", name, entry->d_name);
                        printf("%*s[%s]\n", indent, "", entry->d_name);
                        listdir(path, indent + 2);
                }
                else
                        printf("%*s- %s\n", indent, "", entry->d_name);
        }
        closedir(dir);
}

FILE * sorter(char * columnName, FILE * moviefile, char * outputDir)
{
        int line = 0;

        //getting the column names
        char *str1 = malloc(1024);
        char bufferColumn[1024];
        int i, ch, blah = 0;
        for (i = 0; (i < (sizeof(bufferColumn) - 1) && ((ch = fgetc(stdin)) != EOF) && (ch != '\r')); i++)
        {
                bufferColumn[i] = ch;
                blah = 1;
        }
        if (blah == 0)
        {
                printf("ERROR: Empty file.\n");
                return 1;
        }
        bufferColumn[i] = '\0';

        struct Tokenizer *head = NULL, *curr = NULL, *newNode = NULL;

        //getting the rest of the rows
        while (fgets(str1, 1024, stdin) != NULL)
        {
                char buffer[1024];
                int i, ch;
                // check for empty line
                for (i = 0; (i < (sizeof(buffer) - 1) && ((ch = fgetc(stdin)) != EOF) && (ch != '\r')); i++)
                        buffer[i] = ch;
                buffer[i] = '\0';
                // create tokenizer struct and store at next open spot in array
                newNode = TKCreate(buffer);
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
        }
        if (line == 0)
        {
                printf("Error: No Entries in CSV to sort.\n");
                return 1;
        }

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
        char *columnName = argv[2];

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
                return 1;
        }

        int z = 0;
        printf("%s\n", bufferColumn);
        while (z < line)
        {
                printRecord(&rows[z]);
                //printShort(&rows[z], columnName);
                z++;
        }

        // extra credit section
/*
        // top 10 imdb rating averages of directors
        struct directorRating *headg = NULL, *ptr1 = headg;
        int f = 0;

        for (f = 0; f < line; f++)
        {
                if (headg == NULL)
                {
                        headg = DRcreate(rows[f].director_name, rows[f].imdb_score, 1);
                }
                while (ptr1 != NULL)
                {
                        if (strcmp(ptr1->directorName, rows[f].director_name) == 0)
                        {
                                ptr1->directorRating = ptr1->directorRating + rows[f].imdb_score;
                                ptr1->appearances++;
                                //    printf("name: %s rating total: %lf appearances: %d\n", ptr1->directorName, ptr1->directorRating, ptr1->appearances);
                                break;
                        }
                        else if (ptr1->next == NULL)
                        {
                                ptr1->next = DRcreate(rows[f].director_name, rows[f].imdb_score, 1);
                                break;
                        }
                        else
                        {
                                ptr1 = ptr1->next;
                        }
                }

                ptr1 = headg;
        }

        struct directorRating *temp1 = headg;
        int len = 0;

        while (temp1 != NULL)
        {
                len++;
                temp1 = temp1->next;
        }

        struct directorRating top10[len];
        struct directorRating *ptr2 = headg;
        int p = 0;
        do
        {
                top10[p] = *ptr2;
                ptr2 = ptr2->next;
                p++;
        } while (ptr2 != NULL);

        int lefty = 0, righty = len - 1;
        mergesortExtra(top10, lefty, righty);
        int order = 1;
        int e;
        if (line > 9)
        {
                printf("\n\n-------Top 10 Average Director IMDB Rating-------\n\n");
                for (e = len - 1; e > len - 11; e--)
                {
                        printf("%d. Director: %s, Average IMDB Rating: %lf \n", order, top10[e].directorName, (top10[e].directorRating / top10[e].appearances));
                        order++;
                }
        }
        else
        {
                printf("\n\nNot enough data to compute top 10 average IMDB score per director.\n\n");
        }

        // Freeing memory that was allocated in whole project
        int gg = 0;
        for (gg = 0; gg < line; gg++)
                TKDestroy(&rows[gg]);
        for (gg = 0; gg < len; gg++)
                TopDestroy(&top10[gg]);
        free(str1);
        struct Tokenizer *Jesse = head;
        struct directorRating *Brian = headg;

        while (Jesse != NULL)
        {
                struct Tokenizer *temppp = Jesse;
                Jesse = Jesse->next;
                free(temppp);
        }
        while (Brian != NULL)
        {
                struct directorRating *tempppp = Brian;
                Brian = Brian->next;
                free(tempppp);
        }


        */
        return 0;
}
