/*
Circular doubly linked list is used for implementing playlist structure and its operations.
Array is used for storing outputs of these operations and printing all outputs to the output file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Myplaylist{
        char songname[100];
        struct Myplaylist *next;
        struct Myplaylist *prev;
};
static struct Myplaylist*head=NULL;
static struct Myplaylist*tail=NULL;
static struct Myplaylist*currentsong=NULL;

static char Writings[200][200];
static int counter=0;
char yildiz[20]="*****";
void WritingFile();
void InsertSong(char headortail[1],char insertsongname[50]);
void MoveSong(char beforeorafter[1],char movingsong[50],char referanssong[50]);
void RemoveSong(char removingsongname[50]);
void PlaySong(char calmayonu[1],int playcounter);
void ReversePlaylist();
void PrintPlaylist(char frontorrear[1]);








void InsertSong(char headortail[1],char insertsongname[50])
{       struct Myplaylist*newnode;
        newnode=(struct Myplaylist*)malloc(sizeof(struct Myplaylist));
        newnode->prev=NULL;
        newnode->next=NULL;

    strcpy(newnode->songname,insertsongname);




 if(head==NULL)
            {

                head=tail=newnode;
                newnode->next=head;
                newnode->prev=tail;


            }
else{


        if(strcmp(headortail,"H")==0)
            {

            newnode->next=head;
            head->prev=newnode;
            newnode->prev=tail;
            tail->next=newnode;
            head=newnode;




            }

        else if(strcmp(headortail,"T")==0)
        {




        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
        }












}

}





void MoveSong(char beforeorafter[1],char movingsong[50],char referanssong[50])
{

struct Myplaylist *temp=head;
struct Myplaylist *temp2=head;

do
{
    if(strcmp(temp->songname,movingsong)==0)
    {

        break;

    }
temp=temp->next;
}while(temp!=head);

do{
    if(strcmp(temp2->songname,referanssong)==0)
    {
        break;

    }
temp2=temp2->next;
}while(temp2!=head);

if(strcmp(beforeorafter,"B")==0)
{
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp2->prev->next=temp;
    temp->next=temp2;
    temp2->prev=temp;

}
else if(strcmp(beforeorafter,"A")==0)
{
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=temp2->next;
    temp2->next=temp;
    temp->prev=temp2;


}








}
void RemoveSong(char removingsongname[50])
    {
    printf("%s  %s",currentsong->songname,removingsongname);

    struct Myplaylist *temp;
    temp=head;

        do{

            if(strcmp(temp->songname,removingsongname)==0){
                break;
            }
            temp=temp->next;


        }while(temp!=head);
    if(strcmp(currentsong->songname,removingsongname)==0)
    {
        strcpy(Writings[counter++],"Cannot Remove The Playing Song");

    }
    else
    {
        if(temp==head&&head->next!=head){

            head=head->next;
            head->prev=tail;
            tail->next=head;
            free(temp);
        }
        else if(temp==tail&&head->next!=head){
            tail=tail->prev;
            tail->next=head;
            head->prev=tail;
            free(temp);




        }
        else if(head->next==head)
        {
            head=tail=NULL;
            free(temp);

        }
        else
        {
           temp->prev->next=temp->next;
           temp->next->prev=temp->prev;
           if(temp->next==head)
           {

               tail=temp->prev;
               free(temp);
           }
           free(temp);


        }

    }




}
void PlaySong(char calmayonu[1],int playcounter)
{
    char playing [100]="Playing\t";

    if(playcounter==1)
    {
        if(head==NULL){
    strcpy(Writings[counter++],"No Song To Play");


    }
        if(strcmp(calmayonu,"N")==0){
        currentsong=head;
        strcat(playing,currentsong->songname);
        strcpy(Writings[counter++],playing);
        }
        if(strcmp(calmayonu,"P")==0)
        {
            currentsong=tail;
            strcat(playing,currentsong->songname);
            strcpy(Writings[counter++],playing);
        }
    }
    else{
    if(head==NULL){
    strcpy(Writings[counter++],"No Song To Play");


    }
    else{
            if(strcmp(calmayonu,"N")==0)
            {
                    currentsong=currentsong->next;
                    strcat(playing,currentsong->songname);
                    strcpy(Writings[counter++],playing);






                    }

            else if(strcmp(calmayonu,"B")==0)
            {
                    currentsong=currentsong->prev;
                    strcat(playing,currentsong->songname);
                    strcpy(Writings[counter++],playing);

            }

    }

}



}
void ReversePlaylist()
{
    if(head==NULL){
        return;
    }
    else{

        struct Myplaylist*current;
        struct Myplaylist*nextnode;
         current=head;
        do{

        nextnode=current->next;
        current->next= current->prev;
        current->prev=nextnode;
        current=nextnode;
        }while(current!=head);
        current=head;
        head=tail;
        tail=current;



    }





}
void PrintPlaylist(char frontorrear[1])
{


    struct Myplaylist * currentlist;


    if(head==NULL)
    {

       strcpy(Writings[counter++],"No Songs To Print");


    }
    else{
        if(strcmp(frontorrear,"F")==0){
        currentlist=head;

        do
        {
           strcpy(Writings[counter++],currentlist->songname);
            currentlist=currentlist->next;

        }while(currentlist!=head);



        }
        else if(strcmp(frontorrear,"R")==0)

        {
            currentlist=tail;

         do{
           strcpy(Writings[counter++],currentlist->songname);
            currentlist=currentlist->prev;

        }while(currentlist!=tail);


        }



    }

}





void ReadingFile()
{
    FILE* filep;
    filep=fopen("input.txt","r");
    char teksatir[200];
    int playcounter=1;

    while(fgets(teksatir,200,filep))
    {
        char*commandtype;
        commandtype=strtok(teksatir,"\t");





         if(strstr(commandtype,"InsertSong"))
        {

            char*headortail=strtok(NULL,"\t");
            char*insertsongname=strtok(NULL,"\t");
            InsertSong(headortail,insertsongname);



        }
         if(strstr(commandtype,"MoveSong"))
        {

            char*beforeorafter=strtok(NULL,"\t");
            char*movingsong=strtok(NULL,"\t");
            char*referanssong=strtok(NULL,"\t");
           MoveSong(beforeorafter,movingsong,referanssong);


        }
       if(strstr(commandtype,"RemoveSong"))
        {

            char*removingsong=strtok(NULL,"\t");


           strcpy(Writings[counter++],yildiz);


        }
         if(strstr(commandtype,"PlaySong"))
        {


            char*calmayonu=strtok(NULL,"\t");

            PlaySong(calmayonu,playcounter);
            playcounter++;
            strcpy(Writings[counter++],yildiz);

        }
        if(strstr(commandtype,"ReversePlaylist")){


                        ReversePlaylist();

        }
         if(strstr(commandtype,"PrintPlaylist"))
        {


        char*frontorrear=strtok(NULL,"\t");
        PrintPlaylist(frontorrear);
        strcpy(Writings[counter++],yildiz);


        }




}




fclose(filep);
}

void WritingFile()
{
FILE *filep2;
int i;
filep2=fopen("output.txt","w");



for(i=0;i<=counter;i++){

fprintf(filep2,"%s\n",Writings[i]);
}

fclose(filep2);

}

int main(void)
{
ReadingFile();
WritingFile();



return 0;

}
