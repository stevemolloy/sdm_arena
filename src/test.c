#include <stdio.h>
#include <string.h>

#include "sdm_arena.h"

sdm_arena_t main_arena = {0};

int main(void) {
  size_t capacity = 4;
  sdm_arena_t main_arena = {0};
  sdm_arena_init(&main_arena, capacity);

  char *original_string = "Hello world";
  char *new_string = sdm_arena_alloc(&main_arena, strlen(original_string));
  memcpy(new_string, original_string, strlen(original_string));
  new_string[5] = '_';

  printf("original_string => %s\n", original_string);
  printf("new_string      => %s\n", new_string);

  return 0;
}

