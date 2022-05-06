#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("�����������\n");
		return 0;
	} 
	int i;
	for(i = 0; i < 2; ++i) {
		if(argv[1][i] == '\0') {
			printf("���Ʋ�������\n");
			return 0;
		}
	}
	if(argv[1][0] != '-' || !(argv[1][1] == 'w' || argv[1][1] == 'c')) {
		printf("���Ʋ�������\n");
		return 0;
	}
	int ch, count = 1;
	FILE *file;
	if ((file = fopen(argv[2],"r")) == NULL) {
		printf("���ļ� %s ʧ��",argv[2]);
		exit(1);
	}

	if (strcmp(argv[1], "-c") == 0) {
		count = 0;
		while((ch = getc(file)) != EOF) {
			++count;
		}
		printf("�ַ���%d��\n", count);
	} else {
		while((ch = getc(file)) != EOF) {
			if ((ch == ' ') || (ch == ',')) ++count;
		}
		printf("������%d��\n", count);
	}
	fclose(file);
	return 0;
} 
