#pragma once
/*
 * hash.h -- A generic locked hash table implementation.
 *
 */

#include <stdint.h>
#include <stdbool.h>

typedef void lhashtable_t;	/* representation of a hashtable hidden */

/* lhopen -- opens a hash table with initial size hsize */
lhashtable_t *lhopen(uint32_t hsize);

/* lhclose -- closes a hash table */
void lhclose(lhashtable_t *lhtp);

/* lhput -- puts an entry into a hash table under designated key 
 * returns 0 for success; non-zero otherwise
 */
int32_t lhput(lhashtable_t *lhtp, void *ep, const char *key, int keylen);

/* lhapply -- applies a function to every entry in hash table */
void lhapply(lhashtable_t *lhtp, void (*fn)(void* ep));

/* lhsearch -- searchs for an entry under a designated key using a
 * designated search fn -- returns a pointer to the entry or NULL if
 * not found
 */
void *lhsearch(lhashtable_t *lhtp, 
	      bool (*searchfn)(void* elementp, const void* searchkeyp), 
	      const char *key, 
	      int32_t keylen);

/* lhremove -- removes and returns an entry under a designated key
 * using a designated search fn -- returns a pointer to the entry or
 * NULL if not found
 */
void *lhremove(lhashtable_t *lhtp, 
	      bool (*searchfn)(void* elementp, const void* searchkeyp), 
	      const char *key, 
	      int32_t keylen);
