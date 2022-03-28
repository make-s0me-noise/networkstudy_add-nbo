#include <stdio.h>
#include <stdint.h>

int my_htons(uint32_t *num)
{
	//printf("%x",*num >>24);
	return (*num << 24) | ((*num << 8) & 0x00ff0000) | ((*num >> 8) & 0x0000ff00) | (*num >> 24);
	
}

int main(int argc, char* argv[])
{
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2],"r");
	char firstfile[4];
	char secondfile[4];	
	fread(firstfile,4, 1,fp1);
	fread(secondfile,4,1,fp2);
	uint32_t* first_file = reinterpret_cast<uint32_t*>(firstfile);
	uint32_t* second_file = reinterpret_cast<uint32_t*>(secondfile);
	uint32_t fresult = my_htons(first_file);
	uint32_t sresult = my_htons(second_file);
	uint32_t sum = fresult + sresult;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",fresult,fresult,sresult,sresult,sum,sum);
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
