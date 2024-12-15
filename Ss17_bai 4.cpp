#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
void Enter_array(int *n,int**a){
	printf("Enter the number of elements :");
	scanf("%d",n);
	if(n<0){
		printf("Invalid number of element!\n");
		return;
	}
	*a=(int *)malloc(*n*sizeof(int));
	if(*a==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	for(int i=0;i<*n;i++){
		printf("Enter the %d-th element :",i+1);
		scanf("%d",&(*a)[i]);
	}
}

void Print_even_element(int n,int *a){
	printf("Print elements that are even numbers :\n");
	for(int i=0;i<n;i++){
		if(*(a+i)%2==0){
			printf("%3d",*(a+i));
		}
	}
	printf("\n");
}

int is_prime(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void Print_prime_element(int n,int *a){
	printf("Print elements that are even numbers :\n");
	for(int i=0;i<n;i++){
		if(is_prime(*(a+i))==1){
			printf("%3d",*(a+i));
		}
	}
	printf("\n");
}

void reverse_array(int n,int *a){
	for(int i=0;i<n/2;i++){
		swap(&(*(a+i)),&(*(a+n-i-1)));
	}
	printf("Print array :\n");
	for(int i=0;i<n;i++){
		printf("%3d",*(a+i));
	}
	printf("\n");
}

void Arrange_elements(int n,int *a){
	printf("a.Sort ascending\n");
	printf("b.Sort descending\n");
	char option;
	do{
		printf("Please enter option a or b :");
		scanf(" %c",&option);	
	}while(option!='a'&&option!='b');
	if(option=='a'){
		printf("Sorting in ascending order... \n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	if(option=='b'){
		printf("Sorting in decending order...\n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]<a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	printf("Arranged successfully!\n");
	printf("Print array :\n");
	for(int i=0;i<n;i++){
		printf("%3d",*(a+i));
	}
	printf("\n");
}

void Search_element(int n,int *a){
	printf("Enter the number you want to search :");
	int number;
	int pos=-1;
	scanf("%d",&number);
	for(int i=0;i<n;i++){
		if(a[i]==number){
			pos=i;
			break;
		}
	}	
	if(pos==-1){
		printf("This element not found !\n");
	}
	else{
		printf("Element %d at index %d.\n",number,pos);
	}
}

void show_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Enter array\n");
    printf("2. Print even element\n");
    printf("3. Print prime element\n");
    printf("4. Reverse array\n");
    printf("5. Arrange array\n");
    printf("6. Search element\n");
    printf("7. Exit\n");
    printf("================\n");
}
int main(){
	int *a=NULL;
	int n;
	do{
		show_menu();
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		getchar();
		if(choice==1){
			Enter_array(&n,&a);
		}
		else if(choice==2){
			Print_even_element(n,a);	
		}
		else if(choice==3){
			Print_prime_element(n,a);
		}
		else if(choice==4){
			 reverse_array(n,a);
		}
		else if(choice==5){
			Arrange_elements(n,a);
		}
		else if(choice==6){
			Search_element(n,a);
		}
		else if(choice==7){
			printf("Exit !");
			free(a);
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
}
