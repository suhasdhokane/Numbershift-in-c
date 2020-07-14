#include<process.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
int redKey();
void setMatrix(int A[][4]);
void showMatrix(int A[][4]);
int checkWin(int A[][4]);
int shiftRight(int A[][4]);
int shiftLeft(int A[][4]);
int shiftUp(int A[][4]);
int shiftDown(int A[][4]);
void load();
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
main()
{
    int A[4][4],move,e,i,a=3,j,h=9;
    int easy=1000,medium=500,hard=250,s;
   l1: setMatrix(A);
    printf("\n***** Welcome ******");
    printf("\nNumber shifting Game ");
    move=New(easy,medium,hard);
    s=move;
    clrscr();
    load();
    clrscr();
    while(move){
	printf("\n Move Remaining: %d",move);
	showMatrix(A);
	if(checkWin(A)){
	    printf("\n*********Congratulation you win in %d moves",s-move);
	    printf("\nPress any key to exit----");
	     for(j=1;j<=4;j++){
	      for(i=0;i<=10;i++){
	      sound(i*100);
	      delay(100);        }
	      nosound();
			}
	      nosound();
	    getch();
	    exit(0);
	}
	printf("Back to press ESC ");
	switch(readKey())
	{
	case ESC: sound(9*100);
		  delay(100);
		  nosound();
	    e=back(easy,medium,hard);
	     sound(a*100);
	     delay(100);
	     nosound();
	    if(e==1)
	       {
		  setMatrix(A);
    printf("\n***** Welcome ******");
    printf("\nNumber shifting Game ");
    move=level(easy,medium,hard);
    s=move;
    load();
	       }

	case UP:
	    if(!shiftUP(A))
		move++;
		 sound(a*100);
		 delay(100);
		 nosound();
		break;
	case DOWN:
	    if(!shiftDown(A))
		move++;
		 sound(a*100);
		 delay(100);
		 nosound();
		break;
	case LEFT:
	    if(!shiftLeft(A))
		move++;
		 sound(a*100);
		 delay(100);
		 nosound();
		break;
	case RIGHT:
	    if(!shiftRight(A))
		move++;
		 sound(a*100);
		 delay(100);
		 nosound();
		break;
	default:
	    move++;

	}
	system("cls");
	move--;
    }
     for(i=0;i<=10;i++){
     sound(i*100);
     delay(100);        }
     nosound();
    printf("\n     You Loss ...");
    printf("\nBetter Luck Next Time");
    getch();
}
int shiftRight(int A[][4]){
    int i,j,temp,zerofound=0,a=6;
     for(i=0;i<=3;i++){
	 for(j=0;j<=3;j++){
	    if(A[i][j]==0){
		zerofound=1;
		break;
	    }
	 }
	 if(zerofound)
	    break;
     }
     if(j==0)
	return(0);
     else{
	temp=A[i][j];
	A[i][j]=A[i][j-1];
	A[i][j-1]=temp;
	return(1);
     }

}
int shiftLeft(int A[][4]){
    int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++){
	 for(j=0;j<=3;j++){
	    if(A[i][j]==0){
		zerofound=1;
		break;
	    }
	 }
	 if(zerofound)
	    break;
     }
     if(j==3)
	return(0);
     else{
	temp=A[i][j];
	A[i][j]=A[i][j+1];
	A[i][j+1]=temp;
	return(1);
     }


}
int shiftUP(int A[][4]){
 int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++){
	 for(j=0;j<=3;j++){
	    if(A[i][j]==0){
		zerofound=1;
		break;
	    }
	 }
	 if(zerofound)
	    break;
     }
     if(i==3)
	return(0);
     else{
	temp=A[i][j];
	A[i][j]=A[i+1][j];
	A[i+1][j]=temp;
	return(1);
     }


}
int shiftDown(int A[][4]){
  int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++){
	 for(j=0;j<=3;j++){
	    if(A[i][j]==0){
		zerofound=1;
		break;
	    }
	 }
	 if(zerofound)
	    break;
     }
     if(i==0)
	return(0);
     else{
	temp=A[i][j];
	A[i][j]=A[i-1][j];
	A[i-1][j]=temp;
	return(1);
     }

}
int readKey(){
    int ch;
    ch=getch();
    if(ch==224)
	ch=getch();
    switch(ch){
    case 27:
	return(ESC);
    case 72:
	return(UP);
    case 80:
	return(DOWN);
    case 75:
	return(LEFT);
    case 77:
	return(RIGHT);
    default:
	return(5);
    }
}
int checkWin(int A[][4]){
    int i,j,k=0;
    for(i=0;i<=3;i++){
	for(j=0;j<=3;j++){
	    k<15?k++:(k=0);
	    if(A[i][j]!=k)
		return(0);
	}
    }
    return(1);
}

void setMatrix(int A[][4]){
    int pool[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxIndex=14,index,i,j;
    srand(time(NULL));
    for(i=0;i<=3;i++){
	for(j=0;j<=3;j++){
	    if(maxIndex>=0){
		index=rand()%(maxIndex+1);
		A[i][j]=pool[index];
		pool[index]=pool[maxIndex];
		maxIndex--;
	    }
	    else
		A[i][j]=0;
	}
    }


}
void showMatrix(int A[][4]){
    int i,j;
    printf("\n-------------------------\n|");
    for(i=0;i<=3;i++){
	for(j=0;j<=3;j++){
	    if(A[i][j]!=0)
		printf(" %-2d | ",A[i][j]);
	    else
		printf("    | ");
	}
	printf("\n-------------------------\n|");
	if(i!=3)
	    printf("|");
    }

}
int level(int a,int b,int c){
     int s=9;
    while(1){
	    system("cls");
	switch(menu())
    {
    case 1:
	   sound(s*100);
	   delay(100);
	   nosound();
	return(a);break;
    case 2:
	   sound(s*100);
	   delay(100);
	   nosound();
	return(b);break;
    case 3:
	   sound(s*100);
	   delay(100);
	   nosound();
	return(c);break;
    case 4:
	    sound(s*100);
	    delay(100);
	    nosound();
	New();break;
    default:
	  sound(7*100);
	  delay(100);
	  nosound();
	  printf("\nInvalid choice");break;
    }
    getch();
  }
}
int menu()
{
    int ch;
    printf("\n    1.Easy");
    printf("\n    2.Medium");
    printf("\n    3.Hard");
    printf("\n    4.Back");
    printf("\n    Enter your choice: ");
    scanf("%d",&ch);
    return(ch);
}
int New(int a,int b,int c){
    int d,s=9;
   while(1){
	    system("cls");
    printf("\n***** Welcome ******");
    printf("\nNumber shifting Game ");
    switch(Menu())
    {
    case 1:
	  sound(s*100);
	  delay(100);
	  nosound();
	d=level(a,b,c);
	return(d);
    case 2:
	  sound(s*100);
	  delay(100);
	  nosound();
	d=level( a,b,c);
	return(d);
    case 3:
	    sound(s*100);
	    delay(100);
	    nosound();
	exit(0);break;
    default:
	   sound(7*100);
	   delay(100);
	   nosound();
	printf("\nInvalid choice");break;
    }
    getch();
  }
    }
 int Menu()
{
    int ch;
    printf("\n    1.New Game");
    printf("\n    2.Options");
    printf("\n    3.Exit");
    printf("\n    Enter your choice: ");
    scanf("%d",&ch);
    return(ch);
}
 int back(int a,int b,int c){
    int d,s=9;
   while(1){
	    system("cls");
    printf("\n***** Welcome ******");
    printf("\nNumber shifting Game ");
    switch(MENU())
    {
    case 1:
	return(0);
    case 2:
	return(1);
    case 3:
	return(1);
    case 4: sound(s*100);
	    delay(100);
	    nosound();
	exit(0);break;
    default:
	printf("\nInvalid choice");break;
    }
    getch();
  }
}
int MENU()
{
    int ch;
    printf("\n    1.Continue");
    printf("\n    2.New Game");
    printf("\n    3.Options");
    printf("\n    4.Exit");
    printf("\n    Enter your choice: ");
    scanf("%d",&ch);
    return(ch);
}

void load(){
    int i,x=0;
    textcolor(YELLOW);
    clrscr();
    gotoxy(30,12);
    printf("LOADING....");
    for(i=1;i<=10;i++)
    {
     gotoxy(30+x,13);
     delay(500);
     cprintf("***");
     x=x+2;
     gotoxy(52,13);
     printf("%d0%",i);
     }
     gotoxy(35,14);
     printf("COMPLETE");
     delay(200);
     printf("!");
     delay(200);
     printf("!");
     delay(300);
     gotoxy(55,21);
 //   printf("press any key to be Continue");
     clrscr();

}


