#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "disemvowel.h"

bool isvowel(char const c) {
  char cl = tolower(c);
  if(cl == 'a' || cl == 'e' || cl == 'i' || cl == 'o' || cl == 'u') {
    return true;
  } else {
    return false;
  }
}

char *disemvowel(char const *str) {
  int i, len, nvlen, pos;
  char* outstr;
  
  len = strlen(str) + 1;

  // if(len == 0) {
  //   outstr = (char*) calloc(1, sizeof(char));
  //   outstr[0] = '\0';
  //   return outstr;
  // }

  nvlen = 0;
  for(i=0; i<len; ++i) {
    if(!isvowel(str[i])) {
      nvlen++;
    }
  }

  outstr = (char*) calloc(nvlen, sizeof(char));

  pos = 0;

  for(i=0; i<len; ++i) {
    if(!isvowel(str[i])) {
      outstr[pos] = str[i];
      pos++;
    }
  }

  return outstr;
}