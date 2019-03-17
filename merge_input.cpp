#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"

void merge_input()
{
	memcpy(full, problem, problem_len);
	full_len += problem_len;

	full_len += sprintf(full + full_len, "%02d", points);

	full_len += sprintf(full + full_len, "%02d%02d%02d", month, day, year);

	memcpy(full + full_len, prev_hash, 64);
	full_len += 64;

	memcpy(full + full_len, code_hash, 64);
	full_len += 64;

	memcpy(full + full_len, language, language_len);
	full_len += language_len;

	memcpy(full + full_len, statement_hash, 64);
	full_len += 64;

	memcpy(full + full_len, author, author_len);
	full_len += author_len;

	memcpy(full + full_len, solver, solver_len);
	full_len += solver_len;

	memcpy(full + full_len, miner, miner_len);
	full_len += miner_len;

	memcpy(full + full_len, comment, comment_len);
	full_len += comment_len;
}
