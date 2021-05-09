/********************************************************************************
* @File name: WordCount.c
* @Author: 邓涛 201931061515
* @Version: 1.1.2
* @Date: 2021-5-9
* @Description: 一个统计
********************************************************************************/

#include<stdio.h>
#include<string.h>

/********************************************************************************
* Function name：wordCnt
* Description: 统计单词数量
* Parameter：
* 	@fp 需要被统计的文件
* Return：void
********************************************************************************/
void wordCnt(FILE *fp);

/********************************************************************************
* Function name：charCnt
* Description: 统计字符数量
* Parameter：
* 	@fp ：需要被统计的文件
* Return：void
********************************************************************************/
void charCnt(FILE *fp);


/********************************************************************************
* Function name：main
* Description: 统计一个文本文件中的单词数和字符数
* Parameter：
* 	@argc：命令行命令数量
* 	@argv：命令行命令
* Return：void
********************************************************************************/
int main(int argc, char *argv[]){
	FILE *fp;
	//打开目标文件
	fp = fopen(argv[2], "r");
	//目标文件存在
	if(fp != NULL){
		//判断命令执行相应功能
		if(strcmp(argv[1], "-c") == 0){
			//统计字符数量
			charCnt(fp);
		}else if(strcmp(argv[1], "-w") == 0){
			//统计单词数量
			wordCnt(fp);
		}else{
			printf("option not fond!");
		}
		
		fclose(fp);
	}
	// 目标文件不存在
	else{
		printf("file not fond!");
	}
	return 0;
}

void wordCnt(FILE *fp){
	//当前读取的字符
	int ch;
	//单词数
	int words = 0;
	while((ch = fgetc(fp)) != EOF){
		if(ch == ',' || ch == ' '){
			words++;
		}
	}
	words = words > 0 ? words + 1: words;
	printf("total words: %d", words);
}

void charCnt(FILE *fp){
	//当前读取的字符
	int ch;
	//字符数
	int chars = 0;
	while((ch = fgetc(fp)) != EOF){
		chars++;
	}
	printf("total chars: %d", chars);
}