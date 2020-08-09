#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *izime = strdup("out.bin");
	uint64_t vel = 0;

	for(int i = 1; i < argc; i++)
		if(argv[i][0] == '-') {
			switch(argv[i][1]) {
				case 'o':
					if (++i < argc) {
						free(izime);
						izime = strdup(argv[i]);
					}
					else
						fprintf(stderr, "No filename provided.\n"), exit(1);
					break;

				case 's':
					if (++i < argc) {
						vel = atoll(argv[i]) * 1024 * 1024;
					}
					else
						fprintf(stderr, "No size provided.\n"), exit(1);
					break;
			}

		} else {
			fprintf(stderr, "Invalid argument\n");
			exit(1);
		}


	printf("izlaz = \"%s\"\n", izime);
	printf("vel   = %lu B\n", vel);

	FILE *iz = fopen(izime, "wb+");
	
	char tst[] = "Hello Test World";
	fwrite(tst, sizeof(char), strlen(tst), iz);
	fclose(iz);
}
