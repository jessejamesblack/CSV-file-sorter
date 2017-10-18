#include "sorter.h"

void mergesortString(struct Tokenizer rows[], char * columnName, int l,int r){
        if (l < r)
        {
                int m = l+(r-l)/2;
                mergesortString(rows,columnName, l, m);
                mergesortString(rows,columnName, m+1, r);
                mergeString(rows,columnName, l, m, r);
        }
}

void mergeString(struct Tokenizer rows[], char * columnName, int l, int m, int r){
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        struct Tokenizer L[n1], R[n2];
        int casecmp;
        for (i = 0; i < n1; i++)
                L[i] = rows[l + i];
        for (j = 0; j < n2; j++)
                R[j] = rows[m + 1+ j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
                casecmp = 0;
                if(strcmp(columnName,"color") == 0) {
                        if (strcasecmp(L[i].color, R[j].color) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].color, R[j].color) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].color, R[j].color) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"director_name") == 0) {
                        if (strcasecmp(L[i].director_name, R[j].director_name) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].director_name, R[j].director_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].director_name, R[j].director_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"actor_2_name") == 0) {
                        if (strcasecmp(L[i].actor_2_name, R[j].actor_2_name) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].actor_2_name, R[j].actor_2_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].actor_2_name, R[j].actor_2_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"genres") == 0) {
                        if (strcasecmp(L[i].genres, R[j].genres) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].genres, R[j].genres) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].genres, R[j].genres) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"actor_1_name") == 0) {
                        if (strcasecmp(L[i].actor_1_name, R[j].actor_1_name) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].actor_1_name, R[j].actor_1_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].actor_1_name, R[j].actor_1_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"movie_title") == 0) {
                        if (strcasecmp(L[i].movie_title, R[j].movie_title) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].movie_title, R[j].movie_title) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].movie_title, R[j].movie_title) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"actor_3_name") == 0) {
                        if (strcasecmp(L[i].actor_3_name, R[j].actor_3_name) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].actor_3_name, R[j].actor_3_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].actor_3_name, R[j].actor_3_name) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"plot_keywords") == 0) {
                        if (strcasecmp(L[i].plot_keywords, R[j].plot_keywords) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].plot_keywords, R[j].plot_keywords) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].plot_keywords, R[j].plot_keywords) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"movie_imdb_link") == 0) {
                        if (strcasecmp(L[i].movie_imdb_link, R[j].movie_imdb_link) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].movie_imdb_link, R[j].movie_imdb_link) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].movie_imdb_link, R[j].movie_imdb_link) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"language") == 0) {
                        if (strcasecmp(L[i].language, R[j].language) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].language, R[j].language) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].language, R[j].language) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"country") == 0) {
                        if (strcasecmp(L[i].country, R[j].country) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].country, R[j].country) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].country, R[j].country) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
                if(strcmp(columnName,"content_rating") == 0) {
                        if (strcasecmp(L[i].content_rating, R[j].content_rating) == 0) {
                                casecmp = 1;
                        }
                        if(casecmp == 1) {
                                if(strcmp(L[i].content_rating, R[j].content_rating) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }
                        else{
                                if (strcasecmp(L[i].content_rating, R[j].content_rating) < 0)
                                {
                                        rows[k] = L[i];
                                        i++;
                                }
                                else
                                {
                                        rows[k] = R[j];
                                        j++;
                                }
                                k++;
                        }

                }
        }


        while (i < n1)
        {
                rows[k] = L[i];
                i++;
                k++;
        }

        while (j < n2)
        {
                rows[k] = R[j];
                j++;
                k++;
        }
}

void mergesortInt(struct Tokenizer rows[], char *columnName, int l, int r)
{
        if (l < r)
        {
                int m = l + (r - l) / 2;
                mergesortInt(rows, columnName, l, m);
                mergesortInt(rows, columnName, m + 1, r);
                mergeInt(rows, columnName, l, m, r);
        }
}

void mergeInt(struct Tokenizer rows[], char *columnName, int l, int m, int r)
{
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        struct Tokenizer L[n1], R[n2];

        for (i = 0; i < n1; i++)
                L[i] = rows[l + i];
        for (j = 0; j < n2; j++)
                R[j] = rows[m + 1+ j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
                if(strcmp(columnName,"num_critic_for_reviews") == 0) {
                        if (L[i].num_critic_for_reviews <= R[j].num_critic_for_reviews)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"duration") == 0) {
                        if (L[i].duration <= R[j].duration)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"director_facebook_likes") == 0) {
                        if (L[i].director_facebook_likes <= R[j].director_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"actor_3_facebook_likes") == 0) {
                        if (L[i].actor_3_facebook_likes <= R[j].actor_3_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"actor_1_facebook_likes") == 0) {
                        if (L[i].actor_1_facebook_likes <= R[j].actor_1_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"gross") == 0) {
                        if (L[i].gross <= R[j].gross)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"num_voted_users") == 0) {
                        if (L[i].num_voted_users <= R[j].num_voted_users)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"cast_total_facebook_likes") == 0) {
                        if (L[i].cast_total_facebook_likes <= R[j].cast_total_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"facenumber_in_poster") == 0) {
                        if (L[i].facenumber_in_poster <= R[j].facenumber_in_poster)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"num_user_for_reviews") == 0) {
                        if (L[i].num_user_for_reviews <= R[j].num_user_for_reviews)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"budget") == 0) {
                        if (L[i].budget <= R[j].budget)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"title_year") == 0) {
                        if (L[i].title_year <= R[j].title_year)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"actor_2_facebook_likes") == 0) {
                        if (L[i].actor_2_facebook_likes <= R[j].actor_2_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"movie_facebook_likes") == 0) {
                        if (L[i].movie_facebook_likes <= R[j].movie_facebook_likes)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
        }


        while (i < n1)
        {
                rows[k] = L[i];
                i++;
                k++;
        }


        while (j < n2)
        {
                rows[k] = R[j];
                j++;
                k++;
        }

}

void mergesortFloat(struct Tokenizer rows[], char * columnName, int l,int r){
        if (l < r)
        {
                int m = l+(r-l)/2;
                mergesortFloat(rows,columnName, l, m);
                mergesortFloat(rows,columnName, m+1, r);
                mergeFloat(rows,columnName, l, m, r);
        }
}

void mergeFloat(struct Tokenizer rows[], char * columnName, int l, int m, int r){
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        struct Tokenizer L[n1], R[n2];
        for (i = 0; i < n1; i++)
                L[i] = rows[l + i];
        for (j = 0; j < n2; j++)
                R[j] = rows[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
                if(strcmp(columnName,"imdb_score") == 0) {
                        if (L[i].imdb_score <= R[j].imdb_score)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
                if(strcmp(columnName,"aspect_ratio") == 0) {
                        if (L[i].aspect_ratio <= R[j].aspect_ratio)
                        {
                                rows[k] = L[i];
                                i++;
                        }
                        else
                        {
                                rows[k] = R[j];
                                j++;
                        }
                        k++;
                }
        }


        while (i < n1)
        {
                rows[k] = L[i];
                i++;
                k++;
        }


        while (j < n2)
        {
                rows[k] = R[j];
                j++;
                k++;
        }
}


void mergesortExtra(struct directorRating top10[], int l,int r){
        if (l < r)
        {
                int m = l+(r-l)/2;
                mergesortExtra(top10, l, m);
                mergesortExtra(top10, m+1, r);
                mergeExtra(top10, l, m, r);
        }
}

void mergeExtra(struct directorRating top10[], int l, int m, int r){
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        struct directorRating L[n1], R[n2];
        for (i = 0; i < n1; i++)
                L[i] = top10[l + i];
        for (j = 0; j < n2; j++)
                R[j] = top10[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
                if ((L[i].directorRating/L[i].appearances) <= (R[j].directorRating/R[j].appearances))
                {
                        top10[k] = L[i];
                        i++;
                }
                else
                {
                        top10[k] = R[j];
                        j++;
                }
                k++;

        }

        while (i < n1)
        {
                top10[k] = L[i];
                i++;
                k++;
        }


        while (j < n2)
        {
                top10[k] = R[j];
                j++;
                k++;
        }
}
