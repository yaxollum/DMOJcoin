#ifndef SHA256
#define SHA256

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void run_sha256(const char* input, size_t len, char* output);
void hash_to_string(char string[65], const uint8_t hash[32]);
void calc_sha_256(uint8_t hash[32], const uint8_t * input, size_t len);
#endif
