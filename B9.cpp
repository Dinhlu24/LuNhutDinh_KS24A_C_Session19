#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 100

typedef struct{
	int id;
	char name[20];
	int age;
	char phoneNum[20];
}sinhVien;

void showSVList(sinhVien arr[],int size);
void addSV(sinhVien arr[],int *size);
void fixByID(sinhVien arr[],int size);
void deleteByID(sinhVien arr[],int *size);
void findByName(sinhVien arr[],int size);
void sortByAge(sinhVien arr[],int size);

int main(){
	int currentSize=5,choice;
	sinhVien arr[maxSize] = {
		{1,"Tran Van Dan", 18,"09010101010"},
		{2,"Le Van Lien",20,"0901234567"},
		{3,"Nguyen Van A",8,"0901224461"},
		{4,"Sean Combs",70,"0801994347"},
		{5,"Lebron James",40,"9090909090"},
	};
	do{
		printf("\n-=-=-=--=-=-=-MENU-=-=-=--=-=-=-\n");
		printf("1. Hien thi danh sach sinh vien\n");
		printf("2. Them sinh vien\n");
		printf("3. Sua thong tin sinh vien\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Tim kiem sinh vien\n");
		printf("6. Sap xep danh sach sinh vien\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice); fflush(stdin);
		switch(choice){
			case 1://Hien thi danh sach sinh vien
				{
					showSVList(arr,currentSize);
				}
				break;
			case 2://Them sinh vien
				{
					addSV(arr,&currentSize);
				}
				break;
			case 3:// Sua thong tin sinh vien
				{
					fixByID(arr,currentSize);
				}
				break;
			case 4://Xoa sinh vien
				{
					deleteByID(arr,&currentSize);
				}
				break;
			case 5://Tim kiem sinh vien
				{
					findByName(arr,currentSize);
				}
				break;
			case 6://Sap xep danh sach sinh vien
				{
					sortByAge(arr,currentSize);
				}
				break;
			case 7://Thoat
				{
					printf("Chuong trinh ket thuc");
				}
				break;
			default:
				printf("Lua chon cua ban khong hop le vui long nhap lai");
		}
		printf("\n\n");
	}while(choice != 7);
}

void showSVList(sinhVien arr[],int size){
	printf("%32s","DANH SACH SINH VIEN\n");
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
	printf("|%-5s%-20s%-5s%-15s|\n","ID","Name","Age","Phone Number");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(int i=0;i<size;i++){
		printf("|%-5d%-20s%-5d%-15s|\n",arr[i].id,arr[i].name,arr[i].age,arr[i].phoneNum);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
}

void addSV(sinhVien arr[],int *size){
	sinhVien newStudent;
	
	newStudent.id = *size+1;
	printf("Moi nhap vao ten sinh vien can them vao: ");	gets(newStudent.name);
	
	printf("Moi nhap vao tuoi sinh vien can them vao: ");	scanf("%d",&newStudent.age);	fflush(stdin);
	
	printf("Moi nhap vao sdt sinh vien can them vao: ");	gets(newStudent.phoneNum);
	
	arr[*size] = newStudent;
	(*size)++;
}

void fixByID(sinhVien arr[],int size){
	int fixID;
	printf("Moi nhap vao ID sinh vien can xoa: ");	scanf("%d",&fixID);	fflush(stdin);
	for(int i=0;i<size;i++){
		if(arr[i].id == fixID){
			printf("Moi nhap vao ten sinh vien: ");	gets(arr[i].name);
			printf("Moi nhap vao tuoi sinh vien: ");	scanf("%d",&arr[i].age);	fflush(stdin);
			printf("Moi nhap vao sdt sinh vien: ");	gets(arr[i].phoneNum);
			return;
		}
	}
	printf("ID ban nhap vao khong hop le");
	return;
}

void deleteByID(sinhVien arr[],int *size){
	int deleteID;
	printf("Moi nhap vao ID sinh vien ban can xoa: ");	scanf("%d",&deleteID);	fflush(stdin);
	for(int i=0;i<*size;i++){
		if(arr[i].id == deleteID){
			(*size)--;
			for(int j=i;j<*size;j++){
				arr[j+1].id = j+1;
				arr[j] = arr[j+1];
			}
			printf("Da xoa sinh vien xong !!!");
			return;
		}
	}
	printf("ID sinh vien ban can tim khong ton tai");
}

void findByName(sinhVien arr[],int size){
	char s[20];
	printf("Moi nhap vao ten sinh vien ban can tim kiem: ");	gets(s);
	for(int i=0;i<size;i++){
		if(strcmp(arr[i].name,s) == 0){
			printf("Day la thong tin sinh vien ban can tim kiem:\n");
			printf("%-5s%-20s%-5s%-15s\n","ID","Name","Age","Phone Number");
			printf("%-5d%-20s%-5d%-15s",arr[i].id,arr[i].name,arr[i].age,arr[i].phoneNum);
			return;
		}
	}
	
	printf("Sinh vien ban can tim kiem khong ton tai trong danh sach");
}

void sortByAge(sinhVien arr[],int size){
	printf("Bat dau sap xep\n");
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j].age > arr[j+1].age){
				sinhVien tmp=arr[j];
				arr[j] = arr[j+1];
				arr[j].id = tmp.id;
				tmp.id = arr[j+1].id;
				arr[j+1]=tmp;
			}
		}
	}
	printf("Da sap xep tang dan theo tuoi xong !!!");
}
