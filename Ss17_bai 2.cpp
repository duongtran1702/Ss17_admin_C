#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void enter_str(char **str){
	*str=(char*)malloc(100*sizeof(char));
	if(*str==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	printf("Enter string :");
	fgets(*str,100,stdin);	
	(*str)[strcspn(*str,"\n")]='\0';
}

void print_str(char *str){
	printf("String:%s\n",str);
}

void count_letter(char *str){
	size_t len=strlen(str);
	int index=0;
	for(int i=0;i<len;i++){
		if(str[i]>=65&&str[i]<=90||str[i]>=97&&str[i]<=122){
			index+=1;
		}
	}
	printf("Count of letters in the string :%d\n",index);
}

void count_digit(char *str){
	size_t len=strlen(str);
	int index=0;
	for(int i=0;i<len;i++){
		if(str[i]>=48&&str[i]<=57){
			index+=1;
		}
	}
	printf("Count of digits in the string :%d\n",index);
}

void count_special_character(char *str){
	size_t len=strlen(str);
	int index=0;
	for(int i=0;i<len;i++){
		if(str[i]>=65&&str[i]<=90||str[i]>=97&&str[i]<=122||str[i]>=48&&str[i]<=57){
		}
		else {
			index+=1;
		}
	}
	printf("Count of speacial character in the string :%d\n",index);
}
void show_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Enter a string\n");
    printf("2. Print the string\n");
    printf("3. Count letters in the string\n");
    printf("4. Count digits in the string\n");
    printf("5. Count special characters in the string\n");
    printf("6. Exit\n");
    printf("================\n");
}

int main(){
	char *str=NULL;
	do{	
		show_menu();
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		getchar();
		if(choice==1){
			enter_str(&str);
		}
		else if(choice==2){
			print_str(str);	
		}
		else if(choice==3){
			count_letter(str);
		}
		else if(choice==4){
			count_digit(str);
		}
		else if(choice==5){
			count_special_character(str);
		}
		else if(choice==6){
			printf("Exit !");
			free(str);
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
}