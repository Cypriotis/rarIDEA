#include<stdio.h>
#include<stdlib.h>


void editfile(FILE *fp,FILE *ft) //edit mechanism
{
    printf("The content of the file is : \n");
    char c;
    int delete=1;
    c=fgetc(fp);
    while(c!=EOF) 
        {
            printf("%c",c);
            c=fgetc(fp);
        }

        printf("\n");
        fseek(fp, 0, SEEK_SET);
    char kind;
    int amount,contition=0;
    printf("\nDo you want to put anything at the start of the above statements? 1/0:");
    scanf("%d",&contition);
     if(contition==1)
                {
                    printf("Give me the amount of the characters: ");
                    scanf("%d",&amount);
                    fprintf(ft,"%d",amount);
                    printf("Give me the kind of the character: ");
                    scanf("%s",&kind);
                    fprintf(ft,"%c",kind);
                    
                }
        c=fgetc(fp);
    while(c!=EOF){
        while(c>=48 && c<=57){
        printf("%c",c);
        delete++;
        fprintf(ft,"%c",c);
        c=fgetc(fp);

        
        if(c<48 || c>57){
        printf("%c",c);
        delete++;
        fprintf(ft,"%c",c);
        }
        }
        
        printf("\nIf you want to add anything to the above statement press 1 \n");
        printf("If you want to delete the above statement press 2 \n");
        printf("If you want edit the last statement press 3\n");
        scanf("%d",&contition);

                switch(contition){ //3 ways of editting
                    case 1:
                            printf("Give me the amount of the characters: ");
                            scanf("%d",&amount);
                            fprintf(ft,"%d",amount);
                            printf("Give me the kind of the character: ");
                            scanf("%s",&kind);
                            fprintf(ft,"%c",kind);  
                        break;
                    case 2:
                            delete--;
                            fseek(ft,-delete,SEEK_CUR);
                        break;
                    case 3:
                            delete--;
                            fseek(ft,-delete,SEEK_CUR);
                            printf("Give me the amount of the characters: ");
                            scanf("%d",&amount);
                            fprintf(ft,"%d",amount);
                            printf("Give me the kind of the character: ");
                            scanf("%s",&kind);
                            fprintf(ft,"%c",kind); 
                        break;

                    
                    
                    
         }c=fgetc(fp);
         delete=1;

    }
}

int main()
{
    FILE *fp,*fg,*ft;

    char filename1[25]={0},filename2[25],filehelper[]="filehelp.txt";
    int size,size2;

    printf("Enter the name of the file you want to uncompress(if you want to go into edit mode put -e in the end of the file name WITHOUT spaces): ");
    scanf("%s",filename1);

    int filenamesize=0;
    for(int i=0;i<sizeof(filename1);i++)
        if(filename1[i]!=0)
            filenamesize++;
    int edit=0;

        if(filename1[filenamesize-1]=='e' &&filename1[filenamesize-2]=='-'){    //edit or no
            printf("Edit mode on!");
            edit=1;
        }
//
    int c;
    char item;      

     if(edit==0)
        {   
            fg=fopen("uncompressedV2.txt","w");
            fp=fopen(filename1,"a+");
            fseek(fp, 0, SEEK_SET);
            fseek(fg, 0, SEEK_SET);
        }
        
        //no edit mode actions
        if(edit==0)
        {
             fscanf(fp,"%d",&c);
             item=fgetc(fp);
             while(item!=EOF)
                    {
            for(int i=0;i<c;i++)
                fprintf(fg,"%c",item);

                fscanf(fp,"%d",&c);
                item=fgetc(fp);

                
            

            
        }
         fseek(fp, 0, SEEK_END);
         size= ftell(fp);
         fseek(fg, 0, SEEK_END);
         size2=ftell(fg);


        printf("Action finished successfully!\n");

        printf("The size of the original file is : %d\n",size);
        printf("The size of the compressed file is : %d",size2);
        return 0;
        }

//
        if(edit==1){                            //deleting the flag -e from the file name
            filename1[filenamesize-1]='\0';
            filename1[filenamesize-2]='\0';
            ft=fopen(filehelper,"w+");
        }

        
        fp=fopen(filename1,"a+");

        if(edit==1)
            {
                    editfile(fp,ft);
            }
        


    fg=fopen("uncompressedV2.txt","w");  
    fclose(fg); 
    fg=fopen("uncompressedV2.txt","a+");

               if (ft == NULL){
               printf("Error Reading Filee\n");
               exit (0);
         }
               if (fg == NULL){
               printf("Error Reading File\n");
               exit (0);
         }
         

        
         fseek(ft, 0, SEEK_END);
         size= ftell(ft);
         fseek(ft, 0, SEEK_SET);
         
    
    

    fscanf(ft,"%d",&c);
    item=fgetc(ft);
    while(item!=EOF)
        {
            for(int i=0;i<c;i++)
                fprintf(fg,"%c",item);

                fscanf(ft,"%d",&c);
                item=fgetc(ft);
        }

         fseek(fg, 0, SEEK_END);
         size2= ftell(fg);
         fseek(fg, 0, SEEK_SET);

        //
        fclose(fp);

        fp=fopen(filename1,"w+"); //clears the file

        char copy;
        fseek(ft, 0, SEEK_SET);
        while((copy = fgetc(ft)) != EOF)
            fputc(copy, fp);

        fseek(ft, 0, SEEK_SET);
        fclose(ft);
        remove("filehelp.txt");

        //
       
//
        printf("Action finished successfully!\n");

        printf("The size of the original file is : %d\n",size);
        printf("The size of the compressed file is : %d",size2);
        int ren,del;
        fclose(fg);
        del=remove("uncompressed.txt");
        ren= rename("filehelp.txt","uncompressed.txt");
    fclose(ft);
    fclose(fp);
    
    return 0 ;
}