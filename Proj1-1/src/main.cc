#include "cache.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <assert.h>

Cache c;

int main(int argc, char *argv[]) {
	// hello_world(argc, argv);
	if(argc < 6) {
		// invalid command
		printf("Error: sim_cache <L1_BLOCKSIZE> <L1_SIZE> <L1_ASSOC> <L1_REPLACEMENT_POLICY> <L1_WRITE_POLICY> <trace_file>\n");
		return 0;
	}
	
	if(!freopen(argv[6], "r", stdin)) return 0;
	unsigned int block			= (unsigned)atoi(argv[1]);
	unsigned int size			= (unsigned)atoi(argv[2]);
	unsigned int assoc			= (unsigned)atoi(argv[3]);
	unsigned int replacement	= (unsigned)atoi(argv[4]);
	unsigned int write			= (unsigned)atoi(argv[5]);
	char *tracefile				= argv[6];

	int length = (int)strlen(tracefile);
	int i;
	for(i=length; i>=0; i--) {
		if(tracefile[i] == '/') break;
	}
	tracefile = tracefile + i + 1;
	c.init(block, size, assoc, replacement, write, tracefile);
	c.input();
	c.output();

	return 0;

}
