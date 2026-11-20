/*
   Author:  Jianfei Zhu  
            Concordia University
   Date:    Feb. 10, 2004

Copyright (c) 2004, Concordia University, Montreal, Canada
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

   - Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
   - Neither the name of Concordia University nor the names of its
       contributors may be used to endorse or promote products derived from
       this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.

*/

/* This is an implementation of FP-growth* / FPmax* /FPclose algorithm.
 *
 * last updated Feb. 10, 2004
 *
 */

#include "wtime.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>



#include <time.h>
#include <sys/time.h>
#include "common.h"



#include "buffer.h"

#ifdef _OPENMP
#include <omp.h>
#else
static int omp_get_max_threads() {return 1;}
#endif //_OPENMP

#ifdef ENABLE_PARSEC_HOOKS
#include <hooks.h>
#endif

#define LINT sizeof(int)

// extern void gcStartup (void);
// extern void gcCleanup (void);

int** ITlen;
int** bran;
int** prefix;

int* order_item;		// given order i, order_item[i] gives itemname
int* item_order;		// given item i, item_order[i] gives its new order 
						//	order_item[item_order[i]]=i; item_order[order_item[i]]=i;
int** compact;
int** supp;


stack** list;
int TRANSACTION_NO=0;
int ITEM_NO=100;
int THRESHOLD;

memory** fp_buf;
memory* fp_node_sub_buf;
memory** fp_tree_buf;
memory* database_buf;
int **new_data_num;

void printLen()
{
	int i, j;
	int workingthread=omp_get_max_threads(); 

	for (j = 1; j < workingthread; j ++)
		for (i = 0; i < ITEM_NO; i ++)
		ITlen[0][i] += ITlen[j][i];
	for(i=ITEM_NO-1; i>=0&&ITlen[0][i]==0; i--);
	for(j=0; j<=i; j++) 
		printf("%d\n", ITlen[0][j]);
}

