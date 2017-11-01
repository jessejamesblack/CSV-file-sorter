CCFLAGS = -ggdb -Wall -g

all: sorter default

default:
	rm -rf sorter
	gcc -Wall -g -o sorter mergesort.c sorter.c
sorter: sorter.c mergesort.c sorter.h
	gcc $(CCFLAGS) sorter.c mergesort.c sorter.h -o sorter
test:
	./sorter -c color 
	./sorter -c director_name 
	./sorter -c num_critic_for_reviews 
	./sorter -c duration > duration.csv
	./sorter -c director_facebook_likes 
	./sorter -c actor_3_facebook_likes 
	./sorter -c actor_2_name 
	./sorter -c actor_1_facebook_likes 
	./sorter -c gross 
	./sorter -c genres 
	./sorter -c actor_1_name 
	./sorter -c movie_title 
	./sorter -c num_voted_users 
	./sorter -c cast_total_facebook_likes
	./sorter -c actor_3_name 
	./sorter -c facenumber_in_poster 
	./sorter -c plot_keywords
	./sorter -c movie_imdb_link 
	./sorter -c num_user_for_reviews 
	./sorter -c language 
	./sorter -c country 
	./sorter -c content_rating 
	./sorter -c budget 
	./sorter -c title_year 
	./sorter -c actor_2_facebook_likes 
	./sorter -c imdb_score 
	./sorter -c aspect_ratio 
	./sorter -c movie_facebook_likes   
valgrind:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes -v ./sorter -c color < movie_metadata.csv
clean:
	find /Users/bschillaci25/desktop/cs214project1/ -type f -name '*-sorted-*' -delete
clean2:
	rm sorter
fullclean:
	cp movie_metadata.csv cp
	rm -rf sorter sorter.exe *.csv
	cp cp movie_metadata.csv
	rm cp