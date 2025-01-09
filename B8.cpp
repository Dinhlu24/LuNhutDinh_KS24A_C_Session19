#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct{
	int id;
	char name[20];
	int age;
	char phoneNum[20];
}sinhVien;

void showSVList(sinhVien arr[],int sizeSVList);
void sortByName(sinhVien arr[],int sizeSVList);

int main(){
	system("color 3");
	int sizeSVList=5;
	sinhVien arr[max] = {
		{1,"Tran Van Dan", 18,"09010101010"},
		{2,"Le Van Lien",20,"0901234567"},
		{3,"Nguyen Van A",8,"0901224461"},
		{4,"Sean Combs",70,"0801994347"},
		{5,"Lebron James",40,"9090909090"},
	};
	
	printf("Day la danh sach sinh vien truoc khi duoc sap xep\n");
	showSVList(arr,sizeSVList);
	
	printf("Day la danh sach sinh vien sau khi duoc sap xep\n");
	sortByName(arr,sizeSVList);
	showSVList(arr,sizeSVList);
}

void showSVList(sinhVien arr[],int sizeSVList){
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("|%-5s%-20s%-5s%-15s|\n","ID","Name","Age","Phone Number");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(int i=0;i<sizeSVList;i++){
		printf("|%-5d%-20s%-5d%-15s|\n",arr[i].id=i+1,arr[i].name,arr[i].age,arr[i].phoneNum);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
}

void sortByName(sinhVien arr[],int sizeSVList){
	printf("Bat dau sap xep\n");
	for(int i=0;i<sizeSVList-1;i++){
		int maxIndex=i;
		for(int j=i+1;j<sizeSVList;j++){
			if(strcmp(arr[j].name,arr[maxIndex].name) > 0){
				maxIndex = j;
			}
			sinhVien tmp=arr[i];
				
			arr[i] = arr[maxIndex];	
			
			arr[maxIndex] = tmp;
		}
	}
	printf("Da sap xep xong\n");
}
