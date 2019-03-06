#include "sha-256.h"

#define TPROG

#ifdef TPROG
#include <time.h>
#endif

#define REPS 1000000

namespace
{
    char ff[5000];
    uint8_t res[32];
    char sstr[65];
    char test_str[]="hello this is DMOJcoin something which nobody will ever use";
}

int sha_256_test()
{
#ifdef TPROG
	clock_t start = clock();
#endif

    //FILE* file=fopen("/home/yaxollum/Desktop/Problem Blockchain/proj/test.txt","r");
    //int len=fread(ff,1,5000,file);

    int test_len=strlen(test_str);
	for(int loop=0;loop<REPS;++loop)
    {
        run_sha_256(test_str,test_len,res);
    }
    hash_to_string(sstr,res);
    puts(sstr);

#ifdef TPROG
	clock_t end = clock();
	printf("%.3f seconds!\n", double(end - start) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}
