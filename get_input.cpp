#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"

char block_id[10];
char root[500];
int root_len;

int problem_len;
char problem[64];

int points;

int month, day, year;
char code_path[500];
char statement_path[500];

FILE* code;
FILE* statement;

char full_code[5000];
char full_statement[5000];

int code_len, statement_len;

char language[32];
int language_len;

char prev_hash[100];
char code_hash[100];
char statement_hash[100];
uint8_t tmp_hash[32];

char author[32], solver[32], miner[32];
int author_len, solver_len, miner_len;

char comment[130];
int comment_len;

char full[300];
int full_len;
char full_hash[100];

char dmoj_path[500];
char dmoj_info[5000];

char raw_path[500];

void get_input()
{
	printf("Block number: ");
	read_line(block_id, 10);
	printf("Block #%s\n", block_id);

	printf("Name of problem: ");
	problem_len = read_line(problem, 64);
	puts(problem);

	printf("Points: ");
	scanf("%d", &points);
	printf("%d points\n", points);

	printf("Solved on (month day year): ");
	scanf("%d%d%d", &month, &day, &year);
	printf("%d %d %d\n", month, day, year);

	printf("Root directory path: ");
	get_garbage();
	root_len = read_line(root, 500);

	/* Create paths */
	int tmp_len;

	memcpy(code_path, root, root_len);
	tmp_len = root_len;
	code_path[tmp_len] = '\\';
	++tmp_len;
	strcpy(code_path + tmp_len, block_id);
	tmp_len += strlen(block_id);
	strcpy(code_path + tmp_len, "\\code");

	memcpy(statement_path, root, root_len);
	tmp_len = root_len;
	statement_path[tmp_len] = '\\';
	++tmp_len;
	strcpy(statement_path + tmp_len, block_id);
	tmp_len += strlen(block_id);
	strcpy(statement_path + tmp_len, "\\problem");
	/* DONE */

	code = fopen(code_path, "r");
	if (code) printf("File \"%s\" successfully opened!\n", code_path);
	else printf("Unable to open \"%s\"\n", code_path);
	
	statement = fopen(statement_path, "r");
	if (statement) printf("File \"%s\" successfully opened!\n", statement_path);
	else printf("Unable to open \"%s\"\n", statement_path);

	printf("Language: ");
	language_len = read_line(language, 32);

	printf("Previous Block hash: ");
	read_line(prev_hash, 100);
	if (valid_hash(prev_hash)) printf("Valid hash (starts with %c, ends with %c).\n", prev_hash[0], prev_hash[63]);
	else puts("INVALID HASH!");

	printf("Problem Author: ");
	author_len = read_line(author, 32);
	puts(author);

	printf("Problem Solver: ");
	solver_len = read_line(solver, 32);
	puts(solver);

	printf("Miner: ");
	miner_len = read_line(miner, 32);
	puts(miner);

	printf("128 char max one-line comment: ");
	comment_len = read_line(comment, 130);
	puts(comment);

	code_len = fread(full_code, 1, 5000, code);
	run_sha_256(full_code, code_len, tmp_hash);
	hash_to_string(code_hash, tmp_hash);

	statement_len = fread(full_statement, 1, 5000, statement);
	run_sha_256(full_statement, statement_len, tmp_hash);
	hash_to_string(statement_hash, tmp_hash);
}