#include <stdint.h>
#include <cass.h>
void **__matrix_alloc (cass_size_t row, cass_size_t col, cass_size_t size)
{
	cass_size_t i;
	void **idx = (void **)malloc((row + 1)* sizeof (void *));
	assert(idx != NULL);
	cass_size_t bytes = row * col * size;
 idx[0] = malloc(bytes);
 assert(idx[0] != NULL);
 /* Same zeroed allocation, same shape, outside the warm replay ROI. */
 volatile uint64_t *words = (volatile uint64_t *)idx[0];
 for (cass_size_t zero_i=0; zero_i<bytes/8; ++zero_i) words[zero_i]=0;
 for (cass_size_t zero_i=bytes/8*8; zero_i<bytes; ++zero_i) ((volatile unsigned char *)idx[0])[zero_i]=0;
	if (row * col != 0)	
	assert(idx[0] != NULL);
	for (i = 1; i <= row; i++)
	{
		idx[i] = idx[i-1] + col * size;
	}
	assert(idx[row] - idx[0] == row * col * size);
	idx[row] = NULL;
	return idx;
}
