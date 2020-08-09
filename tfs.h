#ifndef TFS_H
#define TFS_H

#include <stdint.h>

#define MAGIJA 0xAA5346540A

#define VEL_BLOKA (4*1024)

struct tfs_superblock {
	uint64_t magija;
	uint64_t nblokova;
	uint64_t ninode;
	uint64_t inodepoc;
	uint64_t blokpoc;
	uint64_t velbloka;
};

typedef uint8_t blok[VEL_BLOKA] ;

#endif /* TFS_H */
