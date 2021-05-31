#include<stdio.h>
#include<stdlib.h>

typedef struct{
char c;
int count;
}run;


int main(){
    
    FILE *fp,*fg;
    char filename1[25],filename2[25];

    printf("Enter the name of the file you want to compress: ");
    scanf("%s",filename1);
    printf("Enter the name of the file you want to compress to: ");
    scanf("%s",filename2);
    
    fp=fopen(filename1, "r");
    fg=fopen(filename2,"w");

            if (fp == NULL){ //check for valid file names
            printf("Error Reading File\n");
            exit (0);
        }
            if (fg == NULL){
            printf("Error Reading File\n");
            exit (0);
        }

         int size,size2;

         fseek(fp, 0, SEEK_END);
         size= ftell(fp);
         fseek(fp, 0, SEEK_SET);

    run movers;
    movers.count=0;

    

    char tempstore,b,array[size+1];

    for(int i=0;i<size;i++)//file content to a simple array
    {
        movers.c=fgetc(fp);
        array[i]=movers.c;
    }
    fseek(fp, 0, SEEK_SET);

    int temp=1,counter=0,counter2=1,flag=0,numb[size];
    char tempchar,array2[size];

    for(int i=0;i<size;i++)//one array for the number of the kind of each character and one array for the kind of characters
    {
        counter++;
        tempchar=array[i];
        while(array[i]==array[i+1]){
            temp++;
            i++;
        }
        array2[counter]=tempchar;
        numb[counter2]=temp;
        counter2++;
        temp=1;
        flag=flag+2;

        
    }


    char help;
    int help2;
    for(int i=1;i<(flag/2)+1;i++)
    {
        help2=numb[i];//converting the array possition to a single variable so it can be stored to the file
        fprintf(fg,"%d",help2);//stored to the file
        help=array2[i];//converting the array possition to a single variable so it can be stored to the file
        fprintf(fg,"%c",help);//stored to the file
    }

         fseek(fp, 0, SEEK_END);
         size= ftell(fp);
         fseek(fp, 0, SEEK_SET);
         fseek(fg, 0, SEEK_END);
         size2= ftell(fg);
         fseek(fg, 0, SEEK_SET);

         

        

        printf("The size of the original file is : %d\n",size);
        printf("The size of the compressed file is : %d",size2);
        
    fclose(fp);
    fclose(fg);

    return 0;

}