#include<graphics.h> //graphics.h header file include for used all graphics function
#include<string.h> //string.h header file include for strcmp() function
#include<stdio.h> //stdio.h header file include for printf(), scanf() & cprintf() function
#include<conio.h> //conio.h header file include for used clrscr() & getch() function
#include<process.h> //process.h header file include for exit() function
#include<dos.h> //dos.h header file include for delay() function
//-----------------------------------------------------------------------------------------------------------------------------------
int mainmenu();  //mainmenu function declaration
void cui(); //cui function declaration
void gui(); //gui function declaration
void help(); //help function declaration
void about();//about function declaration
//-----------------------------------------------------------------------------------------------------------------------------------
void guiscreen()
{
 printf("Welcome to GUI Screen\n");
 printf("Press any key to exit from GUI Screen.");
union REGS i,o;
i.x.ax=1;
int86(0x33,&i,&o);
getch();
}
//-----------------------------------------------------------------------------------------------------------------------------------
int start()
{
 int i;
 char data[10],input[10],pwd[10]="krishna";
 clrscr();
 {
  gotoxy(37,10);
  cprintf("Loading...");
 }
 for(i=29;i<=55;i++)
 {
  gotoxy(i,12);
  delay(100);
  cprintf("%c",219);
 }
 clrscr();
 gotoxy(34,10);
 {
  printf("Enter User Name\n");
  gotoxy(34,11);
  printf("----------------");
  gotoxy(34,13);
  printf("----------------");
  gotoxy(34,12);
  gets(input);
  if(strcmp(input,"krishna")==0)
   {
    clrscr();
    gotoxy(34,10);
    {
     printf("Enter Password:\n");
     gotoxy(34,11);
     printf("----------------");
     gotoxy(34,13);
     printf("----------------");
    }
    gotoxy(34,12);
    {
     for(i=0;i<9;i++)
     {
      data[i]=getch();
      if(data[i]==13)
       break;
      else
      {
       printf("*");
      }
     }
    }
  data[i]='\0';
  if(strcmp(data,pwd)==0)
  {
   clrscr();
   gotoxy(38,12);
   printf("Welcome");
   delay(1000);
   clrscr();
   mainmenu();//call mainmenu() function
  }
  else
  {
   printf("\n\n\t\t\t\t\Incorrect Password");
   getch();
   exit(1);
  }
 }
 else
  {
   gotoxy(34,14);
   printf("Wrong User Name");
   getch();
   exit(1);
  }
 }
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int mainmenu()
{
 int i=1;
 char input[50];
 clrscr();
  textbackground(RED);
  textcolor(WHITE);
   gotoxy(1,1);
   cprintf("---------------------------------------------------------------------------------\n");
   gotoxy(1,2);
   cprintf(" Welcome to MY Operating System.                                                 \n");
   gotoxy(1,3);
   cprintf(" Devlop by: Krishna Prasad Regmi                                                 \n");
   gotoxy(1,4);
   cprintf(" Operating System verson 1.1.3 CUI and GUI base Operating System                 \n");
   gotoxy(1,5);
   cprintf(" Date of creation 16/06/2017 Last update 28/07/2018                              \n");
   gotoxy(1,6);
   cprintf(" Type help to show help about Operating System                                   \n");
   gotoxy(1,7);
   cprintf(" Notes: All command's write in small lattor                                      \n");
   gotoxy(1,8);
   cprintf("---------------------------------------------------------------------------------\n");
   textbackground(BLUE);
   gotoxy(1,9);
   cprintf(" 1. CUI(Command User Interface)                                                   ");
   gotoxy(1,10);
   cprintf(" 2. GUI(Graphic User Interface)                                                   ");
   gotoxy(1,11);
   cprintf(" 3. Exit                                                                        ");
   gotoxy(1,12);
   cprintf("________________________________________________________________________________");
    back:
    {
     if(i>0)
     {
      gotoxy(1,13);
      printf("                                                                                ");
      gotoxy(1,14);
      printf("                                                                                ");
     }
    gotoxy(1,13);
    textcolor(WHITE);
    textbackground(BLACK);
    cprintf(">> ");
    gets(input);
    if(strcmp(input,"exit")==0)
     {
      gotoxy(1,14);
      cprintf("Thank you for using my OS Press any key to exit.");
      getch();
      exit(1);
     }
    else
     if(strcmp(input,"1")==0)
      {
       cui(); //Call cui function
      }
    else
     if(strcmp(input,"cui")==0)
     {
      cui(); //Call cui function
     }
    else
     if(strcmp(input,"2")==0)
     {
      gui(); //Call gui function
     }
    else
     if(strcmp(input,"gui")==0)
      {
       gui(); //Call gui function
      }
    else
     if(strcmp(input,"3")==0)
      {
       gotoxy(1,14);
       cprintf("Thank you for using my OS Press any key to exit.");
       getch();
       exit(1);
      }
    else
     if(strcmp(input,"help")==0)
      {
       help();
       clrscr();
       mainmenu();//call main menu function
      }
   else
     {
       gotoxy(1,14);
       textcolor(RED);
       cprintf("Command's not found press any key...");
       getch();
       goto back;
     }
   }
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void cui()
{
  char input[50];
  clrscr();
  printf("Welcome to My OS\n");
  printf("System version 1.0.1\n");
  printf("Typer command to do anything.");
  back:
  printf("\n>> ");
  gets(input);
  if(strcmp(input,"exit")==0)
   {
    textcolor(WHITE);
    cprintf("Thank you for using my OS Press any key to exit.");
    getch();
    exit(0);
   }
  else
  if(strcmp(input,"clrscr")==0)
   {
    clrscr();
    goto back;
   }
  else
  if(strcmp(input,"help")==0)
   {
    help();
    clrscr();
    printf("Welcome to My OS\n");
    printf("System version 1.0.1\n");
    printf("Typer command to do anything.");
    goto back;
   }
  else
  if(strcmp(input,"gui")==0)
   {
    gui();
   }
  else
  if(strcmp(input,"about")==0)
  {
   about();
   goto back;
  }
  else
  if(strcmp(input,"menu")==0)
  {
   mainmenu();
  }
  else
  {
   textcolor(RED);
   cprintf("Command's not found...");
   goto back;
  }
  getch();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void help()
{
 clrscr();
 textcolor(WHITE);
 gotoxy(32,1);
 cprintf("--------------------");
 gotoxy(34,2);
 cprintf("About help panel\n");
 gotoxy(32,3);
 cprintf("--------------------");
 gotoxy(1,4);
 cprintf("--------------------------------------------------------------------------------");
 gotoxy(1,5);
 cprintf("Hello user Welcome to the help panel this panel provide help for you.");
 gotoxy(1,6);
 cprintf("My operating system porovide GUI and CUI mode for user. Switch any any mode to");
 gotoxy(1,7);
 cprintf("another mode with the help of My Operating system. My Operating provide more");
 gotoxy(1,8);
 cprintf("sequare OS for user data.");
 getch();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void gui()
{
 clrscr();
 int gd=DETECT,gm,x,x1,y,y1;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 for(x=1,x1=640,y=192,y1=288;x<=424;x++)
 { //write pixel on the screen
  putpixel(x,y,WHITE);
  putpixel(x1,y1,WHITE);
  putpixel(x,y+1,WHITE);
  putpixel(x1,y1+1,WHITE);
  putpixel(x,y-1,WHITE);
  putpixel(x1,y1-1,WHITE);
  delay(15);
  x1--;
 }
 for(x=1,x1=640;x<218;x++)
 {
  putpixel(x,192-1,BLACK);
  putpixel(x1,288-1,BLACK);
  putpixel(x,192,BLACK);
  putpixel(x1,288,BLACK);
  putpixel(x,192+1,BLACK);
  putpixel(x1+1,288+1,BLACK);
  delay(15);
  x1--;
 }
 for(x=218,x1=423,y=191,y1=289;y<288;y++)
 {
  putpixel(x-1,y,WHITE);
  putpixel(x1-1,y1,WHITE);
  putpixel(x,y,WHITE);
  putpixel(x1,y1,WHITE);
  putpixel(x+1,y,WHITE);
  putpixel(x1+1,y1,WHITE);
  delay(15);
  y1--;
 }
 settextstyle(1,0,3);
 outtextxy(275,225,"Welcome");
 delay(2000);
 closegraph();
 guiscreen();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void about()
{
 printf("About System\nSystem version 1.1.3\nLast updation 28/07/2018\nUser: root");
}
//-----------------------------------------------------------------------------------------------------------------------------------
int main()
{
 clrscr();
 start(); //Call start() function
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------