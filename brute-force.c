#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_SONGS 5

struct song {
    char name[100];
};

struct user {
    char name[100];
    struct song* songs[MAX_SONGS];
};

// array of users
struct user users[MAX_USERS];

void init_users(){
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_SONGS; j++){
            users[i].songs[j] = NULL;
        }
    }
}

void add_user(char* name, struct song* songs[]){
    static int user_count = 0;
    strcpy(users[user_count].name, name);
    for (int i = 0; i < MAX_SONGS; i++) {
        users[user_count].songs[i] = songs[i];
    }
    user_count++;
}

void search_users(struct song* song){
    
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_SONGS; j++) {
            if (users[i].songs[j] && !strcmp(users[i].songs[j]->name,song->name)) {
                printf("User %s listen to the same song %s\n", users[i].name,song->name);
                break;
            }
        }
    }
    
}

void main() {
    //initialize the users array
    init_users();

    //create songs
    struct song song1 = {"Shape of You"};
    struct song song2 = {"Thinking Out Loud"};
    struct song song3 = {"Despacito"};
    struct song song4 = {"Shape of You"};
    struct song song5 = {"Shape of You"};

    //create user1 and add songs
    struct song* user1_songs[MAX_SONGS] = {&song1, &song2};
    add_user("Alice", user1_songs);

    //create user2 and add songs
    struct song* user2_songs[MAX_SONGS] = {&song1, &song3};
    add_user("Bob", user2_songs);

    //create user3 and add songs
    struct song* user3_songs[MAX_SONGS] = {&song2, &song4,&song5};
    add_user("Charlie", user3_songs);

    //search for users who listen to the same song
    clock_t start = clock();
    search_users(&song1);
    clock_t end = clock();
    double time_elapsed = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Elapsed in seconds : %f\n",time_elapsed);
}


