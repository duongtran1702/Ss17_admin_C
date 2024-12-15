#include<stdio.h>
#include<stdlib.h>
void creat_array(int *n,int **a){
	printf("Enter the number of elements in the array :");
	scanf("%d",n);
	if (*n <= 0) {
        printf("Invalid number of elements!\n");
        return;
	}
	*a=(int *)calloc(*n,sizeof(int));
	if(*a==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	for(int i=0;i<*n;i++){
		printf("Enter the %d-th element:",i+1);
		scanf("%d",&(*a)[i]);
	}
}

void print_array(int n,int *a){
	printf("Show the elements of the array :\n");
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
void length_array(int n){
	printf("The length of the array :%d\n",n);
}
 
void sum_array(int n,int *a){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=*(a+i);
	}
	printf("The sum of the elements in the array :%d \n",sum);
}

void max_element(int n,int *a){
	int max=*a;
	for(int i=0;i<n;i++){
		if(max<*(a+i)){
			max=*(a+i);
		}
	}
	printf("The maximum element in the array :%d\n",max);
}


int main(){
	int *a=NULL;
	int n;
	do{
		printf("Menu:\n");
        printf("1. Create array\n");
        printf("2. Print array\n");
        printf("3. Get array length\n");
        printf("4. Sum array elements\n");
        printf("5. Find max element\n");
        printf("6. Exit\n");
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		if(choice==1){
			creat_array(&n,&a);
		}
		else if(choice==2){
			print_array(n,a);	
		}
		else if(choice==3){
			length_array(n);
	}
		else if(choice==4){
			sum_array(n,a);	
		}
		else if(choice==5){
			max_element(n,a);		
		}

		else if(choice==6){
			printf("Exit !");
			free(a);
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
}