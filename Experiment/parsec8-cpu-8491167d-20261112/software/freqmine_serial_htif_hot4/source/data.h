/*----------------------------------------------------------------------
  File     : data.h
  Contents : data set management
----------------------------------------------------------------------*/
#ifndef _DATA_CLASS
#define _DATA_CLASS

#include <stdio.h>
#include <stdlib.h>

#define TransLen 50
class MapFile;

class Data
{
 public:
	
	Data(char *filename);
	~Data();
	int isOpen();
	void close(){}

	long totallength;
	
	int *parseDataFile(MapFile *mapfile);

	long currentlength(){
		return cursor;
	}

	void caltotallength(){
		totallength=0;
	}
  
 private:
  
	const char *in;
 long cursor;
};

/**
 chunrong lai, 07-19-2005
**/
class MapFileNode;

class MapFileNode
{
public:
    	int *TransactionContent;
	int size;
	int top;
	unsigned int MR;
	int MC;
	char* MB;
	MapFileNode* next;
	void init(int SIZE, int mul);
	void finalize();
};

class MapFile
{
public:
	MapFileNode* first;
	MapFileNode** table;
	int* nodebegin;
	int* nodeend;
	int *posbegin;
	int *posend;
	char *shareinfomap;
	int tablesize;
	void init();
	void transform_list_table();
	void alloc_work_between_threads(int workingthread);
};

#endif

