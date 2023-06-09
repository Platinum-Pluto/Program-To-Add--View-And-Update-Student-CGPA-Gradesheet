#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char name[50];
    int  id;
    float cgpa[50],gpa[50];
    int semester;
};

void main()
{
    FILE *fp;
    struct student data[100];
    char text[100],y[]="Yes",grades[100],a[]="A+",aa[]="A",aaa[]="A-",b[]="B+",bb[]="B",bbb[]="B-",cccc[]="C+",cc[]="C",ccc[]="C-",d[]="D+",dd[]="D",f[]="F";
    int i,j,k,l,n,subjects,pw=333,password,c=0,access;
    float total_grades,total_gpa,gpa_var,cgpa_var,courses;
    back:
    printf("Are you student or Admin? Answer Yes or No\n>>>");
    scanf("%s",&text);
    if(strcmp(text,y)==0)
     {
        printf("\nEnter Password: (Password is 333)\n>>>");
        scanf("%d",&password);
      if(password==pw)
       {
           printf("\nAccess granted\n");
           printf("\n");
           fp=fopen("Database.txt","w");
           if(fp==NULL)
           {
               printf("\nCould not open file\n");
               exit(EXIT_FAILURE);
           }
       printf("Enter the number of students\n>>>");
       scanf("%d",&n);  //get the total number of students.
       for(i=0;i<n;i++)
       {
        printf("\nEnter student name: (For example Abcd_Xyz)\n>>>");
        scanf("%s",&data[i].name);  //to store the name of each student.
        printf("\nEnter ID of the student  (For example 0123456789)\n>>>");
        scanf("%d",&data[i].id);    //to store the ID of each student.
        total_gpa=0;
        printf("\nEnter number of semester of this student\n>>>");
        scanf("%d",&data[i].semester);
        for(j=0;j<data[i].semester;j++)
        {
            k=j+1;  //k=each semester count so that we can use it to get cgpa of each semester.
            printf("\nEnter the number of courses in semester no: %d \n>>>",k);
            scanf("%f",&courses);
            subjects=(int)courses;  //type casting.turning float courses to int courses/subjects.
            total_grades=0;
            for(l=0;l<subjects;l++)   //ADDED IF ELSE STATEMENT AND ADD THE A,B,C,D,E,F GRADING SYSTEM
            {
                printf("\nEnter grades of course no %d \n>>>",l+1);
                scanf("%s",&grades);
                if(strcmp(grades,a)==0)
                {
                    total_grades=total_grades+4.00;
                }
                else if(strcmp(grades,aa)==0)
                {
                    total_grades=total_grades+4.00;
                }
                else if(strcmp(grades,aaa)==0)
                {
                    total_grades=total_grades+3.70;
                }
                else if(strcmp(grades,b)==0)
                {
                    total_grades=total_grades+3.30;
                }
                else if(strcmp(grades,bb)==0)
                {
                    total_grades=total_grades+3.00;
                }
                else if(strcmp(grades,bbb)==0)
                {
                    total_grades=total_grades+2.70;
                }
                else if(strcmp(grades,cccc)==0)
                {
                    total_grades=total_grades+2.30;
                }
                else if(strcmp(grades,cc)==0)
                {
                    total_grades=total_grades+2.00;
                }
                else if(strcmp(grades,ccc)==0)
                {
                    total_grades=total_grades+1.70;
                }
                else if(strcmp(grades,d)==0)
                {
                    total_grades=total_grades+1.30;
                }
                else if(strcmp(grades,dd)==0)
                {
                    total_grades=total_grades+1.00;
                }
                else if(strcmp(grades,f)==0)
                {
                    total_grades=total_grades+0.00;
                }
            }
            gpa_var=total_grades/courses; //storing the gpa in a variable.
            data[i].gpa[j]=gpa_var; //calculating the gpa of each semester and storing the data in structure.
            total_gpa=total_gpa+gpa_var;
            cgpa_var=total_gpa/k;  //storing the cgpa of each semester in a variable.
            data[i].cgpa[j]=cgpa_var; //storing the cgpa in structure.
        }

     }
     fwrite(data,sizeof(struct student),100,fp);
     printf("\nData was saved successfully\n");
     printf("\n\nPress enter to close the program\n");
     fclose(fp);
     printf("\n\n\n");
       }
     else{
        printf("\nWrong Password\n");
         goto back;
     }
  }
  else{
    fp=fopen("Database.txt","r");
    fread(data,sizeof(struct student),100,fp);
     if(fp==NULL)
           {
               printf("\nCould not access data\n");
               exit(EXIT_FAILURE);
           }
    printf("\n");
    printf("Enter the student ID you want to search \n>>>");
    scanf("%d",&access);
    for(i=0;i<100;i++)
    {
        if(access==data[i].id)
        {
            c=1;
           printf("\n");
        printf("\nName: %s ",data[i].name);
        printf("\nID: %d",data[i].id);
        printf("\n");
        for(j=0;j<data[i].semester;j++)
        {
            printf("\nSemester number %d",j+1);
            printf("\nCGPA: %.2f",data[i].cgpa[j]);  //printing cgpa.
            printf("\nGPA: %.2f",data[i].gpa[j]);    //printing gpa.
            printf("\n");
        }
        }

    }
    fclose(fp);
    printf("\n\nPress enter to exit the program\n");
    printf("\n\n\n");
    if(c==0)
    {
        printf("\nStudent ID not found\n");
    }
  }





}
