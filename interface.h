#ifndef INTERFACE
#define INTERFACE

#include "sha-256.h"

void get_input();
void merge_input();
void mine();
void output();

extern char block_id[10];

extern char root[500];
extern int root_len;

extern char problem[64];
extern int problem_len;

extern int points;

extern int month, day, year;
extern char code_path[500];
extern char statement_path[500];

extern FILE* code;
extern FILE* statement;

extern char full_code[5000];
extern char full_statement[5000];

extern int code_len, statement_len;

extern char language[32];
extern int language_len;

extern char prev_hash[100];
extern char code_hash[100];
extern char statement_hash[100];
extern uint8_t tmp_hash[32];

extern char author[32], solver[32], miner[32];
extern int author_len, solver_len, miner_len;

extern char comment[130];
extern int comment_len;

extern char full[300];
extern int full_len;
extern char full_hash[100];

extern char dmoj_path[500];
extern char dmoj_info[5000];

extern char raw_path[500];


static bool valid_hash(char* hash)
{
	for (int i = 0; i < 64; ++i)
	{
		if ((hash[i] >= '0'&&hash[i] <= '9') || (hash[i] >= 'a'&&hash[i] <= 'f')) continue;
		else return false;
	}

	if (hash[64] == 0) return true;
	else return false;
}

static void get_garbage()
{
	char garbage[20];
	fgets(garbage, 20, stdin);
}

static int read_line(char* out, int n)
{
	fgets(out, n, stdin);
	int len = strlen(out) - 1;
	out[len] = 0;
	return len;
}

#endif