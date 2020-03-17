// from https://github.com/amosnier/sha-2 (public domain equivalent license)
#ifndef SHA256
#define SHA256

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void calc_sha_256(uint8_t hash[32], const uint8_t * input, size_t len);

inline void hash_to_string(char* string, const uint8_t* hash)
{
	size_t i;
	for (i = 0; i < 32; i++) {
		string += sprintf(string, "%02x", hash[i]);
	}
}

inline void run_sha_256(const char* input, size_t len, uint8_t* output)
{
    calc_sha_256(output,reinterpret_cast<const uint8_t*>(input),len);
}

#endif // SHA256
