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
int deleteIndex(sinhVien arr[],int *sizeSVList,int deleteID);

int main(){
	system("color 6");
	int sizeSVList=5;
	sinhVien arr[max] = {
		{1,"Tran Van Dan", 18,"09010101010"},
		{2,"Le Van Lien",20,"0901234567"},
		{3,"Nguyen Van A",8,"0901224461"},
		{4,"Sean Combs",70,"0801994347"},
		{5,"Lebron James",40,"9090909090"},
	};
	
	printf("Day la danh sach cua ban truoc khi xoa");
	showSVList(arr,sizeSVList);
	
	int deleteID;
	printf("Moi ban nhap vao ID sinh vien can xoa: ");	scanf("%d",&deleteID);	fflush(stdin);
	
	if(deleteIndex(arr,&sizeSVList,deleteID)){
		printf("Day la danh sach cua ban sau khi da xoa di 1 sinh vien\n");
		showSVList(arr,sizeSVList);
	}
}

void showSVList(sinhVien arr[],int sizeSVList){
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("|%-5s%-20s%-5s%-15s|\n","ID","Name","Age","Phone Number");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(int i=0;i<sizeSVList;i++){
		printf("|%-5d%-20s%-5d%-15s|\n",arr[i].id,arr[i].name,arr[i].age,arr[i].phoneNum);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
}

int deleteIndex(sinhVien arr[],int *sizeSVList,int deleteID){
	if(deleteID < 1 || deleteID > *sizeSVList){
		printf("ID ban nhap vao khong hop le");
		return 0;
	}
	
	printf("Tien hanh xoa\n");
	(*sizeSVList)--;
	for(int i=deleteID-1;i<*sizeSVList;i++){
		arr[i] = arr[i+1];
		(arr[i].id)--; 
	}
	
	printf("Da xoa xong !!!\n");
	return 1;
}
