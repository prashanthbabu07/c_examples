#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char *name;
    int code;
    int number;
};

int createBinFile(char *fname) {
	FILE *fp;
	struct person newrecord;

	// Open for binary writing
	fp=fopen(fname,"ab");
	if (!fp) {
		printf("Unable to open file!");
		return -1;
	}

	newrecord.name="aaa bbbb";
	newrecord.code=12345;
	newrecord.number=1;
	fwrite(&newrecord, sizeof(struct person), 1, fp);
	
	newrecord.name=strdup("cc ddd");
	newrecord.code=1234578;
	newrecord.number=2;
	fwrite(&newrecord, sizeof(struct person), 1, fp);

	newrecord.name="eeee ffffff";
	newrecord.code=123456;
	newrecord.number=3;
	fwrite(&newrecord, sizeof(struct person), 1, fp);

	fclose(fp);
	return 0;
}

int readBinFile(char *fname) {
	FILE *fp;
	struct person myrecord;

	fp=fopen(fname,"rb");
	if (!fp) {
		printf("Unable to open file!");
		return -1;
	}

	printf("The following records are in the binary file %s:\n", fname);
	while (fread(&myrecord,sizeof(struct person),1,fp) != NULL) {
		printf("%s\t", myrecord.name);
		printf("%d\t", myrecord.code);
		printf("%d\n", myrecord.number);
	}
	fclose(fp);
	return 0;
}


void main(void)
{
	int result, errno;
	
	// Setup a new file on each run.
	result = createBinFile("test.bin");
	if(result == -1) {
		perror("Error creating bin file!");
		exit(1);
	}

	result = readBinFile("test.bin");
	if(result == -1) {
		perror("Error reading bin file!");
		exit(1);
	}
}
