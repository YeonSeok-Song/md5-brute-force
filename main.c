#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include <pthread.h>
#include <windows.h>

int end = 0;
unsigned char result[6] = {0, };
unsigned char ComparePlain[16] = {0x00, }; //unsigned�� �����ִ� �տ� 11111111�� ä������ 0e�ε� ffffff0e�� �ǹ���. 

char* md5check(const char *in){
	unsigned char out[16];
	MD5Simple(in, (unsigned int)strlen(in), out);
	return out;
}

char* md5test(const char *in)
{
	unsigned char out[16];
	MD5Simple(in, (unsigned int)strlen(in), out);
	printf("\"%s\" = ", in);
	MDPrint(out);
	printf("\n");
	
	return out;
}

int md5cmp(char *y){
	
	unsigned char BrutePlain[16]="";
	int i;
	int Rcmp;
	
	strcpy(BrutePlain, md5check(y));
	
	Rcmp = 0;
	for(i = 0; i < 16; i++){
		if(BrutePlain[i] != ComparePlain[i]){
			Rcmp = 1;
			break;
		}
	}
	
	return Rcmp;
}

void *switch1 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	char StartCheck[12] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'Y', 'Z'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 12; checkNum1++){
		check[0] = StartCheck[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
					}
				}
			}
		}
	}
	
}

void *switch2 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };

	char StartCheck2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 10; checkNum1++){
		check[0] = StartCheck2[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
						
						
					}
				}
			}
		}
	}
	
}

void *switch3 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	char StartCheck3[10] = {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 10; checkNum1++){
		check[0] = StartCheck3[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
						
						
					}
				}
			}
		}
	}
	
}

void *switch4 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	char StartCheck4[10] = {'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 10; checkNum1++){
		check[0] = StartCheck4[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
						
						
					}
				}
			}
		}
	}
	
}

void *switch5 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	char StartCheck5[10] = {'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 10; checkNum1++){
		check[0] = StartCheck5[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
						
						
					}
				}
			}
		}
	}
	
}

void *switch6 (void* x){
	
    char checkArray[62] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
					'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
					'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
					'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	char StartCheck6[10] = {'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'};
	
	int checkNum1 = 0;
	int checkNum2 = 0;
	int checkNum3 = 0;
	int checkNum4 = 0;
	int checkNum5 = 0;
	
	char check[6] = "";
	for(checkNum1 = 0; checkNum1 < 10; checkNum1++){
		check[0] = StartCheck6[checkNum1];
		
		for(checkNum2 = 0; checkNum2 < 62; checkNum2++){
			check[1] = checkArray[checkNum2];
			
			for(checkNum3 = 0; checkNum3 < 62; checkNum3++){
				check[2] = checkArray[checkNum3];
				
				for(checkNum4 = 0; checkNum4 < 62; checkNum4++){
					check[3] = checkArray[checkNum4];
					
					for(checkNum5 = 0; checkNum5 < 62; checkNum5++){
						check[4] = checkArray[checkNum5];

						if(md5cmp(check) == 0){
							end = 1;
							strcpy(result, check);
							pthread_exit(NULL);
						}
						else if(end == 1){
							pthread_exit(NULL);
						}
					}
				}
			}
		}
	}
	
}

int main()
{
	char Plain[6] = {0, };
	
	int i;
	
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	pthread_t thread5;
	pthread_t thread6;
	
	scanf_s("%s", Plain, sizeof(Plain)); //input a 5text to make a md5text
	
	strncpy(ComparePlain, md5test(Plain), 16);
	
    if(pthread_create(&thread1, NULL, switch1, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	if(pthread_create(&thread2, NULL, switch2, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	if(pthread_create(&thread3, NULL, switch3, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	if(pthread_create(&thread4, NULL, switch4, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	if(pthread_create(&thread5, NULL, switch5, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	if(pthread_create(&thread6, NULL, switch6, (void*)ComparePlain)<0){
    	perror("thread create error:");
    	exit(0);
	}
	
	printf("�� �����غ���~!\n");
	
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    
    printf("result : %s\n", result); //print the original key

	return 1;   
}

