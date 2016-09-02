#include <stdio.h>

char* titles[] = {"My Time is Now", "Never Gonna Give You Up", "Wake Me Up"};
char* artists[] = {"John Cena", "Rick Astley", "Evanesence feat. Goofy"};

struct song_t {
  char* title;
  char* artist;
};

struct node_t {
  struct song_t* song;
  struct node_t* next;
};

struct playlist_t {
  char* name;
  struct node_t* head;
};

void print( struct playlist_t* pl ) {
  struct node_t* ptr;
  ptr = pl->head;
  while (ptr->next != NULL) {
    printf("%s by %s\n", ptr->song->title, ptr->song->artist);
    ptr = ptr->next;
  }
}

int main(int argc, char* argv[]) {
  //struct song_t song;

  //song.title = titles[0];
  //song.artist = artists[0];

  struct song_t timeIsNow, rickRoll, wakeMeUp;
  struct playlist_t pl1, pl2;
  struct node_t p1_s1, p1_s2, p1_s3;
  struct node_t p2_s1, p2_s2, p2_s3;


  timeIsNow.title = titles[0];
  timeIsNow.artist = artists[0];
  rickRoll.title = titles[1];
  rickRoll.artist = artists[1];
  wakeMeUp.title = titles[2];
  wakeMeUp.artist = artists[2];

  pl1.name = "Memes and Dreams";
  pl1.head = &p1_s1;
  p1_s1.song = &timeIsNow;
  p1_s1.next = &p1_s2;
  p1_s2.song = &rickRoll;
  p1_s2.next = NULL; 
  
  print(&pl1);
  
  return 0;
}
