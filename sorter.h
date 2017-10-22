#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>

/*****
*
*	Define structures and function prototypes for your sorter
*
*
*
******/

//Suggestion: define a struct that mirrors a record (row) of the data set
struct Tokenizer
{
    struct Tokenizer *next;
    unsigned long int num_critic_for_reviews;
    unsigned long int duration;
    unsigned long int director_facebook_likes;
    unsigned long int actor_3_facebook_likes;
    unsigned long int actor_1_facebook_likes;
    unsigned long int gross;
    unsigned long int num_voted_users;
    unsigned long int cast_total_facebook_likes;
    unsigned long int facenumber_in_poster;
    unsigned long int num_user_for_reviews;
    unsigned long int budget;
    unsigned long int title_year;
    unsigned long int actor_2_facebook_likes;
    unsigned long int movie_facebook_likes;
    char *color;
    char *director_name;
    char *actor_2_name;
    char *genres;
    char *actor_1_name;
    char *movie_title;
    char *actor_3_name;
    char *plot_keywords;
    char *movie_imdb_link;
    char *language;
    char *country;
    char *content_rating;
    float imdb_score;
    float aspect_ratio;
};

typedef struct Tokenizer J;

struct directorRating{
  double directorRating;
  char * directorName;
  int appearances;
  struct directorRating *next;
};

void listdir(const char *name, int indent);
void printSort(struct Tokenizer, char *columnName);
void mergesortString(struct Tokenizer rows[], char *columnName, int l, int r);

void mergeString(struct Tokenizer rows[], char *columnName, int l, int m, int r);

void mergesortInt(struct Tokenizer rows[], char *columnName, int l, int r);

void mergeInt(struct Tokenizer rows[], char *columnName, int l, int m, int r);

void mergesortFloat(struct Tokenizer rows[], char *columnNameFloat, int l, int r);

void mergeFloat(struct Tokenizer rows[], char *columnNameFloat, int l, int m, int r);

void mergesortExtra(struct directorRating top10[], int l,int r);

void mergeExtra(struct directorRating top10[], int l, int m, int r);

FILE * sorter(char * columnName, FILE * moviefile, char * outputDir, char * filename);

