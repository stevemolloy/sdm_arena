#include <stdio.h>
#include <string.h>

#include "sdm_arena.h"

void sdm_arena_init(sdm_arena_t *arena, size_t capacity) {
  arena->start = malloc(capacity);
  if (arena->start == NULL) {
    fprintf(stderr, "Memory problem. Aborting.\n");
    exit(1);
  }
  memset(arena->start, 0, capacity);
  arena->next = malloc(sizeof(*arena->next));
  if (arena->next == NULL) {
    fprintf(stderr, "Memory problem. Aborting.\n");
    exit(1);
  }
  memset(arena->next, 0, sizeof(*arena->next));
  arena->capacity = capacity;
  arena->length = 0;
}

void *sdm_arena_alloc(sdm_arena_t *arena, size_t size) {
  if (arena->start == NULL) {
    size_t capacity = (arena->capacity > 0) ? arena->capacity : DEFAULT_CAP;
    while (capacity < size) {
      capacity *= 2;
    }
    sdm_arena_init(arena, capacity);
  }

  if (arena->capacity - arena->length < size) {
    arena->next->capacity = arena->capacity;
    return sdm_arena_alloc(arena->next, size);
  }

  void *return_val = (char*)arena->start + arena->length;

  if (size > 0)
    arena->length += size;
  else
    arena->length += 1;

  return return_val;
}


