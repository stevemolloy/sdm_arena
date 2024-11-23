#ifndef _SDM_ARENA_H
#define _SDM_ARENA_H

#include <stdlib.h>

#define DEFAULT_CAP 256 * 1024*1024

typedef struct sdm_arena_t sdm_arena_t;

struct sdm_arena_t {
  size_t length;
  size_t capacity;
  void *start;
  sdm_arena_t *next;
};

void sdm_arena_init(sdm_arena_t *arena, size_t capacity);
void *sdm_arena_alloc(sdm_arena_t *arena, size_t size);
void sdm_arena_free(sdm_arena_t *arena);

#endif // !_SDM_ARENA_H

