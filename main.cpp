#include "main.h"

int main(int arg, char* argv[]){	
	// get file name 
	if(arg < 2){
		printf("Input Two Files Only");
		return 0;
	}
	
	char *f1 = argv[1];
	char *f2 = argv[2];

	// open file 
	FILE* fp1 = fopen(f1, "rb");
	FILE* fp2 = fopen(f2, "rb");
	
	if(!fp1 || !fp2){
		printf("Invalid File");
		return 0;
	}
	
	// check 32bit number by checking file size 
	fseek(fp1, 0, SEEK_END);
	uint32_t f1_size = ftell(fp1);
	rewind(fp1);
	fseek(fp2, 0, SEEK_END);
	uint32_t f2_size = ftell(fp2);
	rewind(fp2);
	
	
	uint32_t n1, n2;
	if(f1_size!=sizeof(uint32_t)||f2_size!=sizeof(uint32_t)){
		printf("32bits Number Only");
		return 0;
	}
	
	fread(&n1, sizeof(uint32_t), 1, fp1); // (포인터, 읽어올 아이템 크기(1로 해주는게 좋음), n번 읽어옴, 읽어온 아이템 수) 
	fread(&n2, sizeof(uint32_t), 1, fp2);
	
	n1 = ntohl(n1);
	n2 = ntohl(n2);

	//원래는 return 할 때마다 fclose()해줘야 함. 
	//construct, destruct 사용하면 복잡함 해결 
	fclose(fp1);
	fclose(fp2);	
	
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", n1,n1,n2,n2,n1+n2,n1+n2);
	
	return 0;
}
