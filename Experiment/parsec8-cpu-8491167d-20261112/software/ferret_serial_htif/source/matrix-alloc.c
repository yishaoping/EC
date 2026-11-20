#include <cass.h>
void **__matrix_alloc (cass_size_t row, cass_size_t col, cass_size_t size)
{
	cass_size_t i;
	void **idx = (void **)malloc((row + 1)* sizeof (void *));
	assert(idx != NULL);
	idx[0] = calloc(row * col, size);
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
