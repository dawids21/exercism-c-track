#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stdio.h>

#define MAX_STR_LEN 20
#define USED_SYMBOL '*'

enum anagram_status {
   UNCHECKED = -1,
   NOT_ANAGRAM,
   IS_ANAGRAM
};

struct candidate {
   enum anagram_status is_anagram;
   const char *candidate;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for word.  Word buffer and candidate structures may be modified.
 */
void anagrams_for(const char *word, struct candidates *candidates);

#endif
