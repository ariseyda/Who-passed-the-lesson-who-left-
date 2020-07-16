#include<stdio.h>

//You are working in the IT department of X University and you are asked which students in computer engineering should repeat this period. 
//At X university, students whose average is below the average of the department have to repeat that semester. 
//All students' names, surnames, and the grades they receive in the lessons reach you in a text file called “student.txt”. 
//In that period, only 3 courses were opened in computer engineering and all students take these 3 courses. 
//Identify the structure named struct student whose members are first name (string / string), last name (string / string), notes (3-element float array) and average (float). 
//Transfer the records in the file "student.txt" into a string of up to 100 elements of the type struct student. 
//After calculating the averages, you have to write the names and grade averages of the repeating students into the file called “repeat.txt”. 
//Write a full C program that performs the above process. 
//NOTE: The maximum student capacity of the university is 100. You can assume that names and surnames have a maximum of 20 characters each.

struct student{
	
	char name[20];
	char last_name[20];
	float note[3];
	float avrg;
	
};
int main(){
	
	struct student s[100];
	
	FILE *f=fopen("student.txt","w+");
	
	int n,i,j;
	printf("How many students will you enter?:");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
		printf("\nEnter name and last name of student %d:\n",i+1);
		scanf("%s%s",&s[i].name,&s[i].last_name);
		for(j=0;j<3;j++){
		printf("\nEnter %d.th note of %.th student:\n",j+1,i+1);
		scanf("%f",&s[i].note[j]);
    	}
	}
	for(i=0;i<n;i++){
	
		fprintf(f,"%s %s ",s[i].name,s[i].last_name);
		for(j=0;j<3;j++){
		
		fprintf(f,"%.1f ",s[i].note[j]);
		
    	}
    	fprintf(f,"\n");
	}
	
	f=fopen("student.txt","r");
	for(i=0;i<n;i++){
	
		fscanf(f,"%s%s",&s[i].name,&s[i].last_name);
		for(j=0;j<3;j++){
		
		fscanf(f,"%f",&s[i].note[j]);
		
    	}
    	
	}
	for(i=0;i<n;i++){
	
		printf("%s %s ",s[i].name,s[i].last_name);
		for(j=0;j<3;j++){
		
		printf("%.1f ",s[i].note[j]);
		
    	}
    	printf("\n");
	}
	
	float average[n];
	float section_avrg;
	float sum=0.0;
	float sum2=0.0;
	
	int k,l;
	for(k=0;k<n;k++){
		for(l=0;l<3;l++){
			sum+=s[k].note[l];
		}
		average[k]=sum/3.0;
		sum=0;
	}
	for(k=0;k<n;k++){
		sum2+=average[k];
	}
	
	section_avrg=(sum2/n*1.0);
	
	FILE *ff=fopen("repeat.txt","w");
	
	

	int m;
	for(m=0;m<n;m++){
		
		if(m==0){
		    fprintf(ff,"Section average:%.3f\n",section_avrg*1.0);
		    fprintf(ff,"Students who need to take the lesson again:\n");
		}
		
		if(average[m]*1.0<section_avrg*1.0){
			fprintf(ff,"%s %s %.3f\n",s[m].name,s[m].last_name,average[m]*1.0);
		}
	}
	
	fclose(f);
	fclose(ff);
	
	return 0;
}
