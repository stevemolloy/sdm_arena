#include <stdio.h>
#include <string.h>

#include "sdm_arena.h"

static sdm_arena_t main_arena = {0};
static sdm_arena_t *active_arena = &main_arena;

void *active_alloc(size_t size) {
  return sdm_arena_alloc(active_arena, size);
}
#define ALLOC active_alloc

int main(void) {
  size_t capacity = 4;
  sdm_arena_init(&main_arena, capacity);

  char *original_string = "Hello world";

  char *new_string = ALLOC(strlen(original_string));

  memcpy(new_string, original_string, strlen(original_string));
  new_string[5] = '#';

  printf("original_string => %s\n", original_string);
  printf("new_string      => %s\n", new_string);

  return 0;
}

