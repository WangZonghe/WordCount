#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("传入参数错误\n");
		return 0;
	} 
	int i;
	for(i = 0; i < 2; ++i) {
		if(argv[1][i] == '\0') {
			printf("控制参数错误\n");
			return 0;
		}
	}
	if(argv[1][0] != '-' || !(argv[1][1] == 'w' || argv[1][1] == 'c')) {
		printf("控制参数错误\n");
		return 0;
	}
	int ch, count = 1;
	FILE *file;
	if ((file = fopen(argv[2],"r")) == NULL) {
		printf("打开文件 %s 失败",argv[2]);
		exit(1);
	}

	if (strcmp(argv[1], "-c") == 0) {
		count = 0;
		while((ch = getc(file)) != EOF) {
			++count;
		}
		printf("字符数%d个\n", count);
	} else {
		while((ch = getc(file)) != EOF) {
			if ((ch == ' ') || (ch == ',')) ++count;
		}
		printf("单词数%d个\n", count);
	}
	fclose(file);
	return 0;
} 
