#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct donor
{
	int d_id;
	char d_name[25];
	int d_age;
	char d_phno[11];
	char d_mail[25];
	char d_bg[4];
}donor;

void add_donor()
{
	donor *d;
	FILE *fp;
	int n,i;
	printf("\n**********   ADD DONOR   ***********\n");
	printf("\nENTER HOW MANY DONOR YOU WANT : ");
	scanf("%d",&n);
	d=(donor*)calloc(n,sizeof(donor));
	fp=fopen("donors.txt","a");
	for(i=0;i<n;i++)
	{
		printf("\nENTER DONOR ID : ");
		scanf("%d",&d[i].d_id);
		fflush(stdin);
		printf("ENTER DONOR NAME : ");
		scanf("%[^\n]s",d[i].d_name);
		printf("ENTER DONOR AGE : ");
		scanf("%d",&d[i].d_age);
		printf("ENTER DONOR MOBILE NUMBER : ");
		scanf("%s",d[i].d_phno);
		printf("ENTER DONOR EMAIL ID : ");
		scanf("%s",d[i].d_mail);
		printf("ENTER DONOR BLOOD GROUP : ");
		scanf("%s",d[i].d_bg);
		fwrite(&d[i],sizeof(donor),1,fp);
	}
	printf("\n**********   SUCCESFULLY ADDED RECORD   **********\n");
	fclose(fp);
}

void delete_donor()
{
	donor d1;
	FILE *fp,*fp1;
	int id,found=0;
	fp=fopen("donors.txt","r");
	fp1=fopen("temp1.txt","w");
	printf("\n**********   DELETE DONOR   ***********\n");
	printf("\nENTER DONOR ID TO DELETE : ");
	scanf("%d",&id);
	while(fread(&d1,sizeof(donor),1,fp))
	{
		if(d1.d_id==id)
			found=1;
		else
			fwrite(&d1,sizeof(donor),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		fp1=fopen("temp1.txt","r");
		fp=fopen("donors.txt","w");
		while(fread(&d1,sizeof(donor),1,fp1))
			fwrite(&d1,sizeof(donor),1,fp);
		printf("\n**********   SUCCESFULLY DELETEED RECORD   **********\n");
		fclose(fp);
		fclose(fp1);
	}
	else
		printf("\n********************    RECORD NOT FOUND     ********************\n");
}

void update_donor()
{
	donor d1;
	FILE *fp,*fp1;
	int id,found=0;
	fp=fopen("donors.txt","r");
	fp1=fopen("temp1.txt","w");
	printf("\n***********   UPDATE DONOR   ************\n");
	printf("\nENTER DONOR ID TO UPDATE : ");
	scanf("%d",&id);
	while(fread(&d1,sizeof(donor),1,fp))
	{
		if(d1.d_id==id)
		{
			found=1;
			fflush(stdin);
			printf("ENTER NEW DONOR NAME : ");
			scanf("%[^\n]s",d1.d_name);
			printf("ENTER NEW DONOR AGE : ");
			scanf("%d",&d1.d_age);
			printf("ENTER NEW DONOR MOBILE NUMBER : ");
			scanf("%s",d1.d_phno);
			printf("ENTER NEW DONOR EMAIL ID : ");
			scanf("%s",d1.d_mail);
			printf("ENTER NEW DONOR BLOOD GROUP : ");
			scanf("%s",d1.d_bg);
		}
		fwrite(&d1,sizeof(donor),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		fp1=fopen("temp1.txt","r");
		fp=fopen("donors.txt","w");
		while(fread(&d1,sizeof(donor),1,fp1))
			fwrite(&d1,sizeof(donor),1,fp);
		printf("\n**********   SUCCESFULLY UPDATED RECORD   **********\n");
		fclose(fp);
		fclose(fp1);
	}
	else
		printf("\n********************     RECORD NOT FOUND     *********************\n");
}

void search_donor()
{
	donor d1;
	FILE *fp;
	int id,found=0;
	fp=fopen("donors.txt","r");
	printf("**********   SEARCH DONOR   ***********\n");
	printf("\nENTER DONOR ID TO SEARCH : ");
	scanf("%d",&id);
	printf("\n----------------------------------------------------------------------------------------\n");
	printf("\nDONOR ID  DONOR NAME  \tDONOR AGE  MOBILE NUMBER  EMAIL ID \t\tBLOOD GROUP  ");
	printf("\n-----------------------------------------------------------------------------------------\n");
	while(fread(&d1,sizeof(donor),1,fp))
	{
		if(d1.d_id==id)
		{
			found=1;
			printf("\n%-10d%-15s%-10d%-15s%-21s%-5s",d1.d_id,d1.d_name,d1.d_age,d1.d_phno,d1.d_mail,d1.d_bg);
		}
	}
	if(!found)
		printf("\n********************     RECORD NOT FOUND     ********************\n");
	printf("\n----------------------------------------------------------------------------------------\n\n");
	fclose(fp);
}

void search_blood_group()
{
	donor d1;
	FILE *fp;
	int found=0;
	char bg[3];
	fp=fopen("donors.txt","r");
	printf("\n***********   SEARCH BLOOD GROUP   **********\n");
	printf("\nENTER SEARCH BLOOD GROUP : ");
	scanf("%s",&bg);
	printf("\n----------------------------------------------------------------------------------------\n");
	printf("\nDONOR ID  DONOR NAME  \tDONOR AGE  MOBILE NUMBER  EMAIL ID \t\tBLOOD GROUP  ");
	printf("\n----------------------------------------------------------------------------------------\n");
	while(fread(&d1,sizeof(donor),1,fp))
	{
		
		if(strcmp(d1.d_bg,bg)==0)
		{
			found=1;
			printf("\n%-10d%-15s%-10d%-15s%-21s%-5s",d1.d_id,d1.d_name,d1.d_age,d1.d_phno,d1.d_mail,d1.d_bg);
		}
	}
	if(!found)
		printf("\n********************     RECORD NOT FOUND     ********************\n");
	printf("\n----------------------------------------------------------------------------------------\n");
	fclose(fp);
}

void blood_info()
{
	FILE *fp;
	char details[200];
	fp=fopen("Blood Type.txt","r");
	while(fgets(details,200,fp)!=NULL)
	{
		printf("\n%s",details);
	}
	fclose(fp);
}

void display_donor()
{
	donor d1;
	FILE *fp;
	fp=fopen("donors.txt","r");
	printf("\t\t\tALL DONORS LIST");
	printf("\n\n----------------------------------------------------------------------------------------\n");
	printf("\nDONOR ID  DONOR NAME  \tDONOR AGE  MOBILE NUMBER  EMAIL ID \t\tBLOOD GROUP  ");
	printf("\n----------------------------------------------------------------------------------------\n");
	while(fread(&d1,sizeof(donor),1,fp))
	{
	
		printf("\n%-10d%-15s%-10d%-15s%-21s%-5s",d1.d_id,d1.d_name,d1.d_age,d1.d_phno,d1.d_mail,d1.d_bg);
	}
	printf("\n\n----------------------------------------------------------------------------------------\n");
	
	fclose(fp);
}

void main()
{
	int ch;
	printf("\n**********   WELCOME TO BLOOD BANK MANAGEMENT SYSTEM  **********\n");
	do
	{
		printf("\n\t\tMENU\n");
		printf("\n\t1.ADD DONOR");
		printf("\n\t2.DELETE DONOR");
		printf("\n\t3.UPDATE DONOR");
		printf("\n\t4.SEARCH DONOR");
		printf("\n\t5.SEARCH BLOOD GROUP");
		printf("\n\t6.INFORMATION ABOUT BLOOD");
		printf("\n\t7.DISPLAY DONORS LIST");
		printf("\n\t0.EXIT\n");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				add_donor();
				break;
			case 2:
				delete_donor();
				break;
			case 3:
				update_donor();
				break;
			case 4:
				search_donor();
				break;
			case 5:
				search_blood_group();
				break;
			case 6:
				blood_info();
				break;
			case 7:
				display_donor();
				break;
		}
	}while(ch!=0);	
}

