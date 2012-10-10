// hachilabs.cpp
// Compiler: Dev-C++ 4.9.9.2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define false 0
# define true 1
struct peopleinfo
{
       int id;
       char name[25];
       int age;
       char education[25];
       char sex[7];
       char worksat[30];
       char publication[50];
       char honours[50];
       int connectedto[5];
       int noc;//number of connections
//       int iflag[7]={4,3,3,2,2,1,1};
}person[8];


int pathfind(int uid,int sid)
{
    int stack[8],pop,top=0;
    stack[top]=uid;
    int visited[8],i;
    for(i=0;i<8;i++)
    visited[i]=0;
    while(top>=0)
    {
                 pop=stack[top];
                 top--;
                 if(visited[pop]==0)
                 visited[pop]=1;
                 for(i=0;i<person[pop].noc;i++)
                 {
                                               if(visited[person[pop].connectedto[i]]==0)
                                               {
                                                  top++;
                                                  stack[top]=person[pop].connectedto[i];
                                                  if(sid==person[pop].connectedto[i])
                                                  return 1;
                                               }
                 }
    }
    return 0;
}
                 



int main()
{
    int cflag=0;
    int flag=0;
    person[0].id=0;
    strcpy(person[0].name,"Manuj.Khullar");
    person[0].age=21;
    strcpy(person[0].education,"B.Tech-CSE");
    strcpy(person[0].sex,"Male");
    strcpy(person[0].worksat,"HACHI LABS");
    strcpy(person[0].publication,"IEEE Dominance Rough Sets");
    strcpy(person[0].honours,"Gold Medalist-CSE-2013");
    person[0].connectedto[0]=1;
    person[0].connectedto[1]=7;
    person[0].noc=2;
    person[1].id=1;
    strcpy(person[1].name,"Mayank.Shisodia");
    person[1].age=21;
    strcpy(person[1].education,"B.Tech-CSE");
    strcpy(person[1].sex,"Male");
    strcpy(person[1].worksat,"AKAMAI Technologies");
    strcpy(person[1].publication,"IEEE Fuzzy Logic Techniques");
    strcpy(person[1].honours,"Silver Medalist-CSE-2013");
    person[1].connectedto[0]=0;
    person[1].connectedto[1]=2;
    person[1].noc=2;
    person[7].id=7;
    strcpy(person[7].name,"Bob.Sharma");
    person[7].age=22;
    strcpy(person[7].education,"B.Com-SRCC");
    strcpy(person[7].sex,"Male");
    strcpy(person[7].worksat,"Deloitte-HYD");
    strcpy(person[7].publication,"Nil");
    strcpy(person[7].honours,"Natonal Badminton Gold Medalist");
    person[7].connectedto[0]=0;
    person[7].connectedto[1]=2;
    person[7].noc=2;
    person[2].id=2;
    strcpy(person[2].name,"Sahil.Garg");
    person[2].age=21;
    strcpy(person[2].education,"B.Tech-CSE");
    strcpy(person[2].sex,"Male");
    strcpy(person[2].worksat,"Accenture");
    strcpy(person[2].publication,"Nil");
    strcpy(person[2].honours,"Runners Up-Source Code challenge 2013");
    person[2].connectedto[0]=1;
    person[2].connectedto[1]=6;
    person[2].connectedto[2]=7;
    person[2].noc=3;
    person[6].id=6;
    strcpy(person[6].name,"Mr.Kumar");
    person[6].age=25;
    strcpy(person[6].education,"B.Tech-CSE-2005");
    strcpy(person[6].sex,"Male");
    strcpy(person[6].worksat,"Accenture");
    strcpy(person[6].publication,"Nil");
    strcpy(person[6].honours,"Brainvita Winner 2000");
    person[6].connectedto[0]=2;
    person[6].noc=1;
    person[3].id=3;
    strcpy(person[3].name,"Gautam.Kumar");
    person[3].age=22;
    strcpy(person[3].education,"B.Tech-CSE");
    strcpy(person[3].sex,"Male");
    strcpy(person[3].worksat,"Schneider Electric");
    strcpy(person[3].publication,"IEEE Scalable Networks");
    strcpy(person[3].honours,"Source Code Challenge 2013 First Prize");
    person[3].connectedto[0]=4;
    person[3].connectedto[1]=5;
    person[3].noc=2;
    person[4].id=4;
    strcpy(person[4].name,"Arjun.Sehgal");
    person[4].age=22;
    strcpy(person[4].education,"B.E.-CSE");
    strcpy(person[4].sex,"Male");
    strcpy(person[4].worksat,"Infosys");
    strcpy(person[4].publication,"Nil");
    strcpy(person[4].honours,"Natonal Tennis Gold Medalist");
    person[4].connectedto[0]=3;
    person[4].connectedto[1]=5;
    person[4].noc=2;
    person[5].id=5;
    strcpy(person[5].name,"Japneet");
    person[5].age=21;
    strcpy(person[5].education,"Post Graduation-PR");
    strcpy(person[5].sex,"Female");
    strcpy(person[5].worksat,"St.Xaviers,Mumbai");
    strcpy(person[5].publication,"Public Relations and Corporate Comm.");
    strcpy(person[5].honours,"Creative Lead Winner 2011");
    person[5].connectedto[0]=3;
    person[5].connectedto[1]=4;
    person[5].noc=2;
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
    printf("****************** Welcome to CRUZERS NETWORK *****************************\n\n\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~ LOGIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Please Enter The Username: ");
    char username[25];
    int uid;
    scanf("%s",&username);
    int i,f,searchflag;
    //printf("%s",person[0].name);
    for(i=0;i<8;i++)
    {
                     f=strcmpi(username,person[i].name);
                     if(f==0){uid=person[i].id; break;}
    }
    if(!f)
    {
            char searchname[25];
            printf("Successful Login !!!!!!!\n\n");
           label: printf("Enter name of the person you wanna search  ??  0 to exit\n");
            scanf("%s",&searchname);
            if(!strcmp(searchname,"0"))
            goto x;
            int sid=-1,k,j,m,myfriend=0,count=0,ma[7]={0};
            for(i=0;i<8;i++)
            {
                    searchflag=strcmpi(searchname,person[i].name);
                    if(searchflag==0){sid=person[i].id; break;}
            }
            if(uid==sid)
            {
                        printf("HEY YOU ENTERED YOUR NAME ONLY !!!\n\n");
                        goto x;
            }
            /*if(sid==-1)
            {
                       printf("No such User on the Network !!!\n\n");
            }*/
            if(!searchflag)
            {
                           cflag=4;
                           //printf("hi from searchflag");
                           //printf("%d",sid);
                           for(i=0;i<person[uid].noc;i++)
                           {
                                          if(person[uid].connectedto[i]==sid)
                                          {cflag=1; break;}//direct friend
                                          
                           }
                           if(cflag!=1)
                           {
                                       for(i=0;i<person[uid].noc;i++)
                                       {
                                                                     k=person[uid].connectedto[i];
                                                                     for(j=0;j<person[k].noc;j++)
                                                                     {
                                                                            m=person[k].connectedto[j];
                                                                            if(m==sid) {cflag=2;ma[myfriend]=k;myfriend++;break;}
                                                                     }
                                       //if(cflag==2)break;
                                       }                    
                           }
                           if(cflag!=2 && cflag!=1)
                           {
                                      int find=pathfind(uid,sid);
                                      if(find==1) cflag=3;                 
                           } 
                                       
                        
                                          
           switch(cflag)
            {
                         case 4:
                              printf("\nName: %s\n",person[sid].name);
                              printf("\nYou both are not connected in MY NETWORK !!\n\n");
                              break;
                         case 3:
                              printf("\nName : %s",person[sid].name);
                              printf("\nAge : %d",person[sid].age);
                              printf("\nSex : %s",person[sid].sex);
                              printf("\nYou don't have any mutual friends with %s\n\n",person[sid].name);
                              break;
                         case 2:
                              printf("\nYou have mutual friend with %s\n\n",person[sid].name);
                              printf("\nName : %s",person[sid].name);
                              printf("\nAge : %d",person[sid].age);
                              printf("\nSex : %s",person[sid].sex);
                              printf("\nEducation : %s",person[sid].education);
                              printf("\nWorks @ : %s\n\n",person[sid].worksat);
                              break;
                         case 1:
                              printf("\nYou are friends !!!\n\n");
                              printf("\nName : %s",person[sid].name);
                              printf("\nAge : %d",person[sid].age);
                              printf("\nSex : %s",person[sid].sex);
                              printf("\nEducation : %s",person[sid].education);
                              printf("\nWorks @ : %s",person[sid].worksat);
                              printf("\nPublication : %s",person[sid].publication);
                              printf("\nHonours : %s\n\n",person[sid].honours);
                              break;
                                  
            }
            if(myfriend!=0)
            {
            printf("\n\nYOU HAVE %d MUTUAL FRIENDS\n",myfriend);
            printf("\nMUTUAL FRIENDS INFO\n");
             for(i=0;i<myfriend;i++)
             {
                
                printf("\n\n\nName : %s",person[ma[i]].name);
                printf("\nAge : %d",person[ma[i]].age);
                printf("\nWorks @ : %s\n\n",person[ma[i]].worksat);
             }                     
            }                
            }
            else
            {
                printf("\n\nNo such registered person on MY Network\n\n");
            }
    
    }
    else
    {
        printf("\n\nOOPS !!! You are still not a registered user !!");
    }
    goto label;
 x: 
system("pause");
return 0;
}
