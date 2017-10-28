CCFLAGS = -ggdb -Wall -g

all: sorter default

default:
	rm -rf sorter
	gcc -Wall -g -o sorter mergesort.c sorter.c
sorter: sorter.c mergesort.c sorter.h
	gcc $(CCFLAGS) sorter.c mergesort.c sorter.h -o sorter
test:
	cat movie_metadata.csv | ./sorter -c color > color.csv
	cat movie_metadata.csv | ./sorter -c director_name > director_name.csv
	cat movie_metadata.csv | ./sorter -c num_critic_for_reviews > num_critic_for_reviews.csv
	cat movie_metadata.csv | ./sorter -c duration > duration.csv
	cat movie_metadata.csv | ./sorter -c director_facebook_likes > director_facebook_likes.csv
	cat movie_metadata.csv | ./sorter -c actor_3_facebook_likes > actor_3_facebook_likes.csv
	cat movie_metadata.csv | ./sorter -c actor_2_name > actor_2_name.csv
	cat movie_metadata.csv | ./sorter -c actor_1_facebook_likes > actor_1_facebook_likes.csv
	cat movie_metadata.csv | ./sorter -c gross > gross.csv
	cat movie_metadata.csv | ./sorter -c genres > genres.csv
	cat movie_metadata.csv | ./sorter -c actor_1_name > actor_1_name.csv
	cat movie_metadata.csv | ./sorter -c movie_title > movie_title.csv
	cat movie_metadata.csv | ./sorter -c num_voted_users > num_voted_users.csv
	cat movie_metadata.csv | ./sorter -c cast_total_facebook_likes > cast_total_facebook_likes.csv
	cat movie_metadata.csv | ./sorter -c actor_3_name > actor_3_name.csv
	cat movie_metadata.csv | ./sorter -c facenumber_in_poster > facenumber_in_poster.csv
	cat movie_metadata.csv | ./sorter -c plot_keywords > plot_keywords.csv
	cat movie_metadata.csv | ./sorter -c movie_imdb_link > movie_imdb_link.csv
	cat movie_metadata.csv | ./sorter -c num_user_for_reviews > num_user_for_reviews.csv
	cat movie_metadata.csv | ./sorter -c language > language.csv
	cat movie_metadata.csv | ./sorter -c country > country.csv
	cat movie_metadata.csv | ./sorter -c content_rating > content_rating.csv
	cat movie_metadata.csv | ./sorter -c budget > budget.csv
	cat movie_metadata.csv | ./sorter -c title_year > title_year.csv
	cat movie_metadata.csv | ./sorter -c actor_2_facebook_likes > actor_2_facebook_likes.csv
	cat movie_metadata.csv | ./sorter -c imdb_score > imdb_score.csv
	cat movie_metadata.csv | ./sorter -c aspect_ratio > aspect_ratio.csv
	cat movie_metadata.csv | ./sorter -c movie_facebook_likes > movie_facebook_likes.csv
valgrind:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -v ./sorter -c color < movie_metadata.csv
clean:
	find /mnt/c/Users/Brian/Desktop/fall2017projects/cs214project1/* -type f -name '*-sorted-*' -delete
fullclean:
	cp movie_metadata.csv cp
	rm -rf sorter sorter.exe *.csv
	cp cp movie_metadata.csv
	rm cp
