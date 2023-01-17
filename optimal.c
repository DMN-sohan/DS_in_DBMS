#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song {
    char name[100];
    struct user *listeners;
};

struct user {
    char name[100];
    struct song *songs;
};

struct song* searchSong(char* name, struct song*songList, int numSongs) {
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(songList[i].name, name) == 0) {
            return &songList[i];
        }
    }
    return NULL;
}

void addUser(char* name, struct song* songList, int numSongs) {
    struct user* newUser = (struct user*) malloc(sizeof(struct user));
    strcpy(newUser->name, name);
    newUser->songs = (struct song*) malloc(sizeof(struct song)*numSongs);
    for(int i=0; i<numSongs; i++) {
        newUser->songs[i] =songList[i];
    }
    songList[0].listeners[0] = *newUser;
}

void findUsers(char* songName, struct song* songList, int numSongs) {
    struct song* result = searchSong(songName,songList,numSongs);
    if (result == NULL) {
        printf("Song not found.\n");
    } else {
        printf("Users listening to %s: \n", result->name);
        for (int i = 0; i < numSongs; i++) {
            if(result->listeners[i].name != NULL){
                printf("%s\n", result->listeners[i].name);
            }
        }
    }
}

void main() {
     int numSongs = 5;
    struct song songList[numSongs];
    char*songName[5]={"song1","song2","song3","song4","song5"};
    for(int i = 0; i < numSongs; i++) {
        strcpy(songList[i].name,songName[i]);
    }
    int numUsers = 5;
    struct user userList[numUsers];
    char* userName[5]={"user1","user2","user3","user4","user5"};
    for(int i=0; i<numUsers; i++){
        strcpy(userList[i].name, userName[i]);
        userList[i].songs = (struct song*) malloc(sizeof(struct song)*numSongs);
    }
    for(int i=0; i<numUsers; i++){
        for(int j=0; j<numSongs; j++){
            userList[i].songs[j]=songList[j];
        }
    }
    clock_t begin = clock();
    findUsers("song1",songList,numUsers);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    
}