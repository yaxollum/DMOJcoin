#include "interface.h"
#include <stdio.h>
#include <string.h>

void output()
{
	/* Create path */
	int tmp_len;

	memcpy(dmoj_path, root, root_len);
	tmp_len = root_len;
	dmoj_path[tmp_len] = '\\';
	++tmp_len;
	strcpy(dmoj_path + tmp_len, block_id);
	tmp_len += strlen(block_id);
	strcpy(dmoj_path + tmp_len, "\\dmoj");

	memcpy(raw_path, root, root_len);
	tmp_len = root_len;
	raw_path[tmp_len] = '\\';
	++tmp_len;
	strcpy(raw_path + tmp_len, block_id);
	tmp_len += strlen(block_id);
	strcpy(raw_path + tmp_len, "\\raw");
	/* DONE */

	FILE* dmoj = fopen(dmoj_path, "w");
	fprintf(dmoj, "## Block #%s ##\n", block_id);
	fprintf(dmoj, "**Block hash:** %s\n\n", full_hash);
	fprintf(dmoj, "**Previous block hash:** %s\n\n", prev_hash);
	fprintf(dmoj, "**Block data:** ([link][raw%s])\n\n", block_id);
	fprintf(dmoj, "**Problem name:** %s ([link][name%s])\n\n", problem, block_id);
	fprintf(dmoj, "**Problem statement:** ([link][statement%s])\n\n", block_id);
	fprintf(dmoj, "**Code:** ([link][code%s])\n\n", block_id);
	fprintf(dmoj, "**Points:** %d\n\n", points);
	fprintf(dmoj, "**Solved on:** %02d/%02d/%02d\n\n", month, day, year);
	fprintf(dmoj, "**Language:** %s\n\n", language);
	fprintf(dmoj, "**Author:** [user:%s]\n\n", author);
	fprintf(dmoj, "**Solver:** [user:%s]\n\n", solver);
	fprintf(dmoj, "**Miner:** [user:%s]\n\n", miner);
	fprintf(dmoj, "**Comment:** %s\n\n", comment);
	fprintf(dmoj, "**Magic word:** %s\n\n", full + full_len - 10);

	fprintf(dmoj, "  [raw%s]: https://raw.githubusercontent.com/yaxollum/DMOJcoin/master/blocks/%s/raw\n", block_id, block_id);
	fprintf(dmoj, "  [name%s]: https://dmoj.ca/problem/%s\n", block_id, problem);
	fprintf(dmoj, "  [statement%s]: https://raw.githubusercontent.com/yaxollum/DMOJcoin/master/blocks/%s/problem\n", block_id, block_id);
	fprintf(dmoj, "  [code%s]: https://raw.githubusercontent.com/yaxollum/DMOJcoin/master/blocks/%s/code", block_id, block_id);

	fclose(dmoj);

	FILE* raw = fopen(raw_path, "w");
	fwrite(full, 1, full_len, raw);
}