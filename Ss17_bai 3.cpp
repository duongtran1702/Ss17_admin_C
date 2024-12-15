#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void print_str(char *str){
	printf("String:%s\n",str);
}

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

void print_reverse_str(char *str){
	size_t len=strlen(str);
	char reverse_str[100];
	for(int i=0;i<len;i++){
		reverse_str[i]=str[len-i-1];
	}
	reverse_str[len]='\0';
	printf("String reverse :%s",reverse_str);
}

void count_word(char *str){
	size_t len=strlen(str);
	int	count=0;
	for(int i=0;i<len;i++){
		if(str[i]!=' '&&(i==0||str[i-1]==' ')){
			count+=1;
		}
	}
	printf("The number of word in the string :%d\n",count);
}


void input_and_compare_str(char *str){
	size_t len_1=strlen(str);
	char str_1[100];
	printf("Enter a different string :");
	fgets(str_1,100,stdin);
	str_1[strcspn(str_1,"\n")]='\0';
	size_t len_2=strlen(str_1);
	if(len_1<len_2){
		printf("Longer!\n");
	}
	else if(len_1>len_2){
		printf("Shorter!\n");
	}
	else{
		printf("The two strings are equal!\n");
	}
}

void toupper_case(char *str){
	size_t len=strlen(str);
	for(int i=0;i<len;i++){
		if(!isspace(str[i])){
			str[i]=toupper(str[i]);
		}
	}
	print_str(str);
}

void add_str(char **str){
	printf("Enter a string :");
	char str_temp[100];
	fgets(str_temp,100,stdin);
	str_temp[strcspn(str_temp,"\n")]='\0';
	strcat(*str,str_temp);
	print_str(*str);
}
void show_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Enter a string\n");
    printf("2. Print the reverse string\n");
    printf("3. Count word\n");
    printf("4. Enter a different string and compare\n");
    printf("5. Make the string uppercase\n");
    printf("6. Add string to the original string\n");
    printf("7. Exit\n");
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
			print_reverse_str(str);	
		}
		else if(choice==3){
			count_word(str);
		}
		else if(choice==4){
			input_and_compare_str(str);
		}
		else if(choice==5){
			toupper_case(str);
		}
		else if(choice==6){
			add_str(&str);
		}
		else if(choice==7){
			printf("Exit !");
			free(str);
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
}
