#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "interface.h";

void mine()
{
	full_len += 10;
	uint8_t pp = points / 10 * 16 + points % 10;
	for (char a = 'a'; a <= 'z'; ++a)
	{
		for (char b = 'a'; b <= 'z'; ++b)
		{
			for (char c = 'a'; c <= 'z'; ++c)
			{
				for (char d = 'a'; d <= 'z'; ++d)
				{
					for (char e = 'a'; e <= 'z'; ++e)
					{
						for (char f = 'a'; f <= 'z'; ++f)
						{
							for (char g = 'a'; g <= 'z'; ++g)
							{
								for (char h = 'a'; h <= 'z'; ++h)
								{
									for (char i = 'a'; i <= 'z'; ++i)
									{
										for (char j = 'a'; j <= 'z'; ++j)
										{
											full[full_len - 1] = j;
											full[full_len - 2] = i;
											full[full_len - 3] = h;
											full[full_len - 4] = g;
											full[full_len - 5] = f;
											full[full_len - 6] = e;
											full[full_len - 7] = d;
											full[full_len - 8] = c;
											full[full_len - 9] = b;
											full[full_len - 10] = a;

											run_sha_256(full, full_len, tmp_hash);
											if (tmp_hash[0] == 0x3f && tmp_hash[1] == 0x3f && tmp_hash[2] == pp)
											{
												hash_to_string(full_hash, tmp_hash);
												return;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}