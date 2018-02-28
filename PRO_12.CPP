#include <dos.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <fstream.h>
#include <graphics.h>

void main(void);
int checkwin(void);
void board(void);
int CPU(void);

struct Player
{
   char name[100];
   char yob[5];
   char acc[4];
   char pass[50];
   unsigned long money;
}pla;

int t=0;

void intro()
{
   setbkcolor(14);

   setcolor(3);
   settextstyle(4,0,4);
   outtextxy(200,5,"GAMES");

   setcolor(12);
   settextstyle(3,0,2);
   outtextxy(220,40,"- Rishav Agarwal");

   setcolor(13);
   settextstyle(2,0,7);
   outtextxy(200,130,"Welcome!");
   outtextxy(200,150,"GAMES");
   outtextxy(200,170,"By-");
   outtextxy(200,190,"Rishav Agarwal");
   outtextxy(200,210,"Birla High School.");

   setcolor(9);
   line(190,2,410,2);
   line(190,235,410,235);
   line(190,2,190,235);
   line(410,2,410,235);

   settextstyle(5,0,2);
   setcolor(4);
   outtextxy(5,280,"Loading...");

   int c=0;
   for(int i=0;i<getmaxx();++i)
   {
      setfillstyle(11,5);
      bar(0,320,i,340);
      delay(2);
      if(kbhit())
	 c=getch();
      if(c==27)
	 exit(0);
   }
}

void pass()
{
   char pass[10],p;
   pass[0]='\0';
   int i;

   do
   {
      cleardevice();

      i=0;

      setcolor(14);
      setbkcolor(4);
      settextstyle(3,0,1);
      outtextxy(100,200,"Enter Password :");

      setcolor(11);

      while(1)
      {
	 p=getch();

	 if(p==13)
	 {
	    pass[i]='\0';
	    break;
	 }

	 else if(p==27)
	    exit(0);

	 else if(p==8)
	 {
	    if(i>0)
	    {
	       setcolor(4);
	       outtextxy(250+i*10,205,"*");
	       pass[--i]='\0';
	       setcolor(11);
	    }
	 }

	 else
	 {
	    pass[i++]=p;
	    pass[i]='\0';
	    outtextxy(250+i*10,205,"*");
	 }
      }
   }
   while(strcmp("GamesRish",pass));

   setbkcolor(14);
}

int login()
{
   cleardevice();
   setcolor(4);
   int ch;
   settextstyle(1,0,2);
   outtextxy(150,100,"Enter your choice :");
   outtextxy(150,140,"1. Create new player account.");
   outtextxy(150,170,"2. Login.");
   outtextxy(150,200,"3. Exit.");
   ch=getch()-48;
   if(ch==27)
      exit(0);
   if(ch<1 || ch>3)
      ch=login();
   return ch;
}

void New()
{
   cleardevice();

   settextstyle(3,0,1);
   outtextxy(100,100,"Enter Name : ");
   outtextxy(100,150,"Enter Year of Birth : ");

   setcolor(9);
   settextstyle(0,0,1);
   int i=0;
   char nm[100],p;
   nm[0]='\0';
   while(1)
   {
      outtextxy(250+i*8,112,"_");

      p=getch();

      if(p==13)
      {
	 setcolor(14);
	 outtextxy(250+i*8,112,"_");
	 setcolor(9);
	 nm[i]='\0';
	 break;
      }

      else if(p==27)
      {
	 t=1;
	 main();
      }

      else if(p==8)
      {
	 if(i>0)
	 {

	       setcolor(14);
	       outtextxy(250+i*8,112,"_");
	       char w[1];
	       w[0]=nm[--i];
	       outtextxy(250+i*8,112,w);
	       nm[i]='\0';
	       setcolor(9);
	 }
      }

      else
      {
	 setcolor(14);
	 outtextxy(250+i*8,112,"_");
	 setcolor(9);
	 nm[i++]=p;
	 nm[i]='\0';
	 outtextxy(250,112,nm);
      }
   }

   strcpy(pla.name,nm);

   setcolor(9);
   i=0;
   char yob[4];
   yob[0]='\0';
   while(1)
   {
      outtextxy(310+i*8,162,"_");

      p=getch();

      if(p==13)
      {
	 setcolor(14);
	 outtextxy(310+i*8,162,"_");
	 setcolor(9);
	 yob[i]='\0';
	 break;
      }

      else if(p==27)
      {
	 t=1;
	 main();
      }

      else if(p==8)
      {
	 if(i>0)
	 {

	       setcolor(14);
	       outtextxy(310+i*8,162,"_");
	       char w[1];
	       w[0]=yob[--i];
	       outtextxy(310+i*8,162,w);
	       yob[i]='\0';
	       setcolor(9);
	 }
      }

      else
      {
	 setcolor(14);
	 outtextxy(310+i*8,162,"_");
	 setcolor(9);
	 yob[i++]=p;
	 yob[i]='\0';
	 outtextxy(310,162,yob);
      }
   }

   strcpy(pla.yob,yob);

   char ac[]="000";
   fstream fs("Acc.txt", ios::in | ios::out | ios::ate);
   if(fs.tellg()==0){}
   else
   {
      fs.seekg(-3, ios::end);
      fs>>ac;
      for(int z=0;z<3;++z)
      {
	 if(ac[z]==57)
	    ac[z]=65;
	 else if(ac[z]==90)
	    ac[z]=97;
	 else if(ac[z]==122)
	 {
	    ac[z]=48;
	    ac[z-1]=0;
	 }
	 else if(z==2)
	    ++ac[z];
      }
   }

   strcpy(pla.acc,ac);

   setcolor(4);
   settextstyle(3,0,1);
   outtextxy(100,200,"Your Account Number : ");
   outtextxy(100,250,"Enter Password : ");

   setcolor(9);
   settextstyle(0,0,1);
   outtextxy(320,212,ac);

   i=0;
   char pass[50];
   pass[0]='\0';
   while(1)
   {
      outtextxy(260+i*10,262,"_");

      p=getch();

      if(p==13)
      {
	 setcolor(14);
	 outtextxy(260+i*8,262,"_");
	 setcolor(9);
	 pass[i]='\0';
	 break;
      }

      else if(p==8)
      {
	 if(i>0)
	 {
	    setcolor(14);
	    outtextxy(260+i*10,262,"_");
	    outtextxy(260+(--i)*10,262,"*");
	    pass[i]='\0';
	    setcolor(9);
	 }
      }

      else
      {
	 setcolor(14);
	 outtextxy(260+i*10,262,"_");
	 setcolor(9);
	 outtextxy(260+i*10,262,"*");
	 pass[i++]=p;
	 pass[i]='\0';
      }
   }

   strcpy(pla.pass,pass);
   pla.money=100000;

   fs<<ac;
   fs.close();

   ofstream ofs("Player.txt", ios::app);
   ofs.write((char *)&pla ,sizeof pla);
   ofs.close();
}

void sign()
{
   cleardevice();

   char acc[4],pass[50];
   outtextxy(100,100,"Enter Account No. : ");
   outtextxy(100,150,"Enter Password : ");

   setcolor(9);
   settextstyle(0,0,1);
   int i=0;
   char p;
   acc[0]='\0';
   while(1)
   {
      outtextxy(320+i*8,112,"_");

      p=getch();

      if(p==13)
      {
	 setcolor(14);
	 outtextxy(320+i*8,112,"_");
	 setcolor(9);
	 acc[i]='\0';
	 break;
      }

      else if(p==27)
      {
	 t=1;
	 main();
      }

      else if(p==8)
      {
	 if(i>0)
	 {
	    setcolor(14);
	    outtextxy(320+i*8,112,"_");
	    char w[1];
	    w[0]=acc[--i];
	    outtextxy(320+i*8,112,w);
	    acc[i]='\0';
	    setcolor(9);
	 }
      }

      else if(i<3)
      {
	 if((p>=48 && p<=57) || (p>=65 && p<=90) || (p>=97 && p<=122) )
	 {
	    setcolor(14);
	    outtextxy(320+i*8,112,"_");
	    setcolor(9);
	    acc[i++]=p;
	    acc[i]='\0';
	    outtextxy(320,112,acc);
	 }
      }

      else{}
   }

   i=0;
   pass[0]='\0';
   while(1)
   {
      outtextxy(280+i*10,162,"_");

      p=getch();

      if(p==13)
      {
	 setcolor(14);
	 outtextxy(280+i*8,162,"_");
	 setcolor(9);
	 pass[i]='\0';
	 break;
      }

      else if(p==27)
      {
	 t=1;
	 main();
      }

      else if(p==8)
      {
	 if(i>0)
	 {
	    setcolor(14);
	    outtextxy(280+i*10,162,"_");
	    outtextxy(280+(--i)*10,162,"*");
	    pass[i]='\0';
	    setcolor(9);
	 }
      }

      else
      {
	 setcolor(14);
	 outtextxy(280+i*10,162,"_");
	 setcolor(9);
	 outtextxy(280+i*10,162,"*");
	 pass[i++]=p;
	 pass[i]='\0';
      }
   }

   ifstream ifs("Player.txt");
   if(!ifs)
   {
      outtextxy(100,200,"No such account exists !!!");
      getch();
      t=1;
      main();
   }
   ifs.seekg(0);

   int flag=0;

   while(1)
   {
      ifs.read((char *)&pla, sizeof pla);
      if(ifs.eof())
	 break;
      if(!strcmp(acc,pla.acc))
      {
	 if(!strcmp(pass,pla.pass))
	 {
	    settextstyle(4,0,1);
	    outtextxy(100,250,"Login Succesful !");
	    settextstyle(0,0,1);
	    flag=1;
	    ifs.close();
	    break;
	 }
	 else
	 {
	    outtextxy(100,200,"Wrong Password !");
	    getch();
	    ifs.close();
	    t=1;
	    main();
	 }
      }
   }
   if(!flag)
   {
      outtextxy(100,200,"No such account exists !");
      getch();
      ifs.close();
      t=1;
      main();
   }
}

int choice()
{
   cleardevice();

   setcolor(9);
   settextstyle(2,0,4);

   moveto(5,5);
   outtext(pla.name);
   outtext(" - ");
   outtext(pla.acc);

   unsigned long num=pla.money;
   char mon[11];
   mon[0]='\0';
   int i=0,t;

   while(num)
   {
      mon[i++]=(num%10)+48;
      mon[i]='\0';
      num/=10;
   }
   for(int j=0;j<i/2;++j)
   {
      t=mon[j];
      mon[j]=mon[i-1-j];
      mon[i-1-j]=t;
   }

   outtextxy(5,15,mon);

   setcolor(4);
   settextstyle(3,0,1);

   outtextxy(200,100,"Enter your choice :");

   settextstyle(0,0,1);

   outtextxy(200,140,"1. Number Racing.");
   outtextxy(200,160,"2. Ball Shooting.");
   outtextxy(200,180,"3. Tic Tac Toe.");
   outtextxy(200,200,"4. Spin for Luck.");
   outtextxy(200,220,"5. Log Out.");
   int ch=getch();

   return (ch-48);
}

void race()
{
ra:
   cleardevice();

   setcolor(4);
   settextstyle(0,0,1);

   char am[20],nm[2];
   int num,n;
   unsigned long amo=0;

   outtextxy(200,150,"Enter amount to bet:");
   setcolor(9);
   int p,i=0;
   while(1)
   {
      p=getch();
      if(!( (p>=48 && p<=57) || p==8 || p==13) )
	 continue;
      if(p==13)
      {
	 am[i]='\0';
	 break;
      }
      else if(p==8)
      {
	 amo/=10;
	 setcolor(14);
	 char w[1];
	 w[0]=am[--i];
	 outtextxy(200+i*8,180,w);
	 setcolor(9);
      }
      else
      {
	 amo=amo*10+p-48;
	 am[i++]=p;
	 am[i]='\0';
	 outtextxy(200,180,am);
      }
   }
   if(amo>pla.money)
   {
      settextstyle(2,0,5);
      outtextxy(200,250,"You dont have enough money");
      getch();
      goto ra;
   }

   setcolor(4);
   outtextxy(200,200,"Enter number to bet on(1-5):");
   do
   {
      num=getch()-48;
   }
   while(num<1 || num>5);
   nm[0]=num+48;
   nm[1]='\0';

   int j;
   cleardevice();
   int pos[]={0,0,0,0,0};
   char pl[5][2];
   for(int k=0;k<5;++k)
   {
      pl[k][0]=k+49;
      pl[k][1]='\0';
   }
   int f=0;
   for(k=0;k<5;++k)
      outtextxy(0,k*50+50,pl[k]);
   setcolor(9);
   line(5,5,5,getmaxy()-5);
   line(getmaxx()-5,5,getmaxx()-5,getmaxy()-5);

   getch();

   randomize();
   while(1)
   {
      delay(25);
      cleardevice();
      moveto(50,300);
      outtext("Number Selected : ");
      setcolor(9);
      outtext(nm);
      line(5,5,5,getmaxy()-5);
      line(getmaxx()-5,5,getmaxx()-5,getmaxy()-5);
      setcolor(4);
      for(j=0;j<5;++j)
      {
	 outtextxy(pos[j]=pos[j]+random(3)+1,j*50+50,pl[j]);
	 if(pos[j]>=getmaxx()-5)
	 {
	    cleardevice();
	    n=j+1;
	    f=1;
	    break;
	 }
      }
      if(f)
	 break;
   }


   char w[1];
   w[0]=n+48;
   w[1]='\0';
   settextstyle(8,0,3);
   setcolor(9);
   moveto(250,120);
   outtext(w);
   outtext(" WINS!");
   moveto(250,150);
   outtext("YOU ");
   if(n==num)
   {
      pla.money = pla.money + amo*5;
      outtext("WIN!");
   }
   else
   {
      pla.money = pla.money - amo;
      outtext("LOSE!");
   }
   getch();
}

int sh_ch()
{
   cleardevice();

   setcolor(4);

   int ch;

   outtextxy(200,100,"How do you want to play?");
   outtextxy(200,130,"1. Limited Time.");
   outtextxy(200,150,"2. Limited Shots.");
   outtextxy(200,170,"3. Limited Misses.");
   outtextxy(200,190,"4. Free Play.");
   ch=getch()-48;
   if(ch<1 || ch>4)
      ch=sh_ch();

   return ch;
}

void report(char sc[],char at[],char ti[])
{
   settextstyle(7,0,1);
   moveto(200,150);
   setcolor(4);
   outtext("SCORE : ");
   setcolor(9);
   outtext(sc);
   moveto(200,200);
   setcolor(4);
   outtext("ATTEMPTS : ");
   setcolor(9);
   outtext(at);
   moveto(200,250);
   setcolor(4);
   outtext("TIME TAKEN : ");
   setcolor(9);
   outtext(ti);
   setcolor(4);
   settextstyle(0,0,1);
}

void shoot()
{
   int ch=sh_ch();
st:
   int choice,cc[9];

   cleardevice();

   if(ch==1)
   {
      outtextxy(200,100,"Select time :");
      outtextxy(200,130,"1.  30 seconds.");
      outtextxy(200,150,"2.  60 seconds.");
      outtextxy(200,170,"3.  90 seconds.");
      outtextxy(200,190,"4. 120 seconds.");
      outtextxy(200,210,"5. 150 seconds.");
      outtextxy(200,230,"6. 180 seconds.");
      outtextxy(200,250,"7. 300 seconds.");
      choice=getch()-48;
      if(choice<1 ||choice>7)
	 goto st;
      cc[1]=30;
      cc[2]=60;
      cc[3]=90;
      cc[4]=120;
      cc[5]=150;
      cc[6]=180;
      cc[7]=300;
   }
   else if(ch==2)
   {
      outtextxy(200,100,"Select shots :");
      outtextxy(200,130,"1.  10 shots.");
      outtextxy(200,150,"2.  20 shots.");
      outtextxy(200,170,"3.  30 shots.");
      outtextxy(200,190,"4.  50 shots.");
      outtextxy(200,210,"5.  75 shots.");
      outtextxy(200,230,"6. 100 shots.");
      outtextxy(200,250,"7. 150 shots.");
      outtextxy(200,270,"8. 200 shots.");
      choice=getch()-48;
      if(choice<1 || choice>8)
	 goto st;
      cc[1]=10;
      cc[2]=20;
      cc[3]=30;
      cc[4]=50;
      cc[5]=75;
      cc[6]=100;
      cc[7]=150;
      cc[8]=200;
   }
   else if(ch==3)
   {
      outtextxy(200,100,"Select misses :");
      outtextxy(200,130,"1. 5 misses.");
      outtextxy(200,150,"2. 10 misses.");
      outtextxy(200,170,"3. 20 misses.");
      outtextxy(200,190,"4. 25 misses.");
      outtextxy(200,210,"5. 30 misses.");
      outtextxy(200,230,"6. 50 misses.");
      choice=getch()-48;
      if(choice<1 || choice>6)
	 goto st;
      cc[1]=5;
      cc[2]=10;
      cc[3]=20;
      cc[4]=25;
      cc[5]=30;
      cc[6]=50;
   }

   cleardevice();
   setfillstyle(1,12);

   int b,l=20,l1=20,h=50,h1=50,f=0,score=0,att=0,shot=0,five=0,two=0,one=0,miss=0,time=0;
   char sc[5],at[5],sh[5],fi[5],tw[5],on[5],mi[5],ti[4];
   sc[0]='0'; at[0]='0'; sh[0]='0'; fi[0]='0'; tw[0]='0'; on[0]='0'; mi[0]='0'; ti[0]='0';
   sc[1]='\0'; at[1]='\0'; sh[1]='\0'; fi[1]='\0'; tw[1]='\0'; on[1]='\0'; mi[1]='\0'; ti[1]='\0';
   int level=1;
   char lev[2];
   lev[0]='1'; lev[1]='\0';
   int k=getmaxy();

   clock_t st;
   st=clock();

   for(int i=getmaxy();;--i)
   {
      cleardevice();

      line(0,40,getmaxx(),40);
      line(l1,h1,l1+30,h1);
      setcolor(4);

      circle(getmaxx()-15,k,10);
      floodfill(getmaxx()-15,k,4);

      moveto(15,5);
      outtext("Score : ");
      setcolor(9);
      outtext(sc);
      setcolor(4);
      if(ch==2)
      {
	 outtext(" | Attempts : ");
	 setcolor(9);
	 outtext(at);
	 outtextxy(300,5,"LIMITED SHOTS");
      }
      else if(ch==3)
      {
	 outtext(" | Misses : ");
	 setcolor(9);
	 outtext(mi);
	 outtextxy(300,5,"LIMITED MISSES");
      }
      else if(ch==1)
      {
	 outtext(" | Time : ");
	 setcolor(9);
	 outtext(ti);
	 outtextxy(300,5,"LIMITED TIME");
	 setcolor(4);
	 outtext(" seconds");
      }
      else
      {
	 setcolor(9);
	 outtextxy(300,5,"FREE PLAY");
	 outtextxy(100,getmaxy()-50,"Press '+' to level up and '-' to level down.");
      }
      setcolor(4);
      moveto(15,20);
      outtext("Five : ");
      setcolor(9);
      outtext(fi);
      setcolor(4);
      outtext(" | Two : ");
      setcolor(9);
      outtext(tw);
      setcolor(4);
      outtext(" | One : ");
      setcolor(9);
      outtext(on);
      setcolor(4);
      moveto(200,getmaxy()-15);
      outtext("LEVEL : ");
      setcolor(9);
      outtext(lev);

      int flag=0;

      if(ch==1 && time>=cc[choice])
      {
	 flag=1;
	 outtextxy(200,100,"TIME UP !");
      }
      if(ch==2 && att==cc[choice]*level && !f)
      {
	 flag=1;
	 outtextxy(200,100,"SHOTS FINISHED !");
      }
      if(ch==3 && miss==cc[choice])
      {
	 flag=1;
	 outtextxy(200,100,"MISSES LIMIT REACHED !");
      }

      int l1=level,temp=0;
      while(l1)
      {
	 lev[temp++]=(l1%10)+48;
	 lev[temp]='\0';
	 l1/=10;
      }

      for(int j=0;j<strlen(lev)/2;++j)
      {
	 temp=lev[j];
	 lev[j]=lev[strlen(lev)-j-1];
	 lev[strlen(lev)-j-1]=temp;
      }

      if(flag)
      {
	 getch();
	 report(sc,at,ti);
	 getch();
	 if(level==5)
	 {
	    pla.money+=(score-miss)*10;
	    break;
	 }
	 else
	 {
	    setcolor(9);
	    if(score>=att)
	    {
	       outtextxy(200,300,"Level Passed !");
	       ++level;
	       if(ch==1)
		  st=clock();
	       if(ch==3)
		  miss=0;
	       getch();
	    }
	    else
	    {
	       outtextxy(200,300,"Level Failed !");
	       getch();
	       break;
	    }

	    setcolor(4);
	 }
      }

      if(f)
      {
	 line(l,h,l+30,h);
	 l=l+5;
	 if(l>=getmaxx()-25)
	 {
	    --f;
	    l=20;

	    ++miss;
	    int temp=0,m=miss;
	    while(m)
	    {
	       mi[temp++]=(m%10)+48;
	       mi[temp]='\0';
	       m/=10;
	    }

	    for(int j=0;j<strlen(mi)/2;++j)
	    {
	       temp=mi[j];
	       mi[j]=mi[strlen(mi)-j-1];
	       mi[strlen(mi)-j-1]=temp;
	    }
	 }
      }

      time=(clock()-st)/CLK_TCK;
      int t1=time;
      temp=0;
      while(t1)
      {
	 ti[temp++]=(t1%10)+48;
	 ti[temp]='\0';
	 t1/=10;
      }

      for(j=0;j<strlen(ti)/2;++j)
      {
	 temp=ti[j];
	 ti[j]=ti[strlen(ti)-j-1];
	 ti[strlen(ti)-j-1]=temp;
      }

      k-=level;
      if(k<=50)
	 k=getmaxy();
      if(h1<=40)
	 h1=getmaxy()-1;
      if(h1>=getmaxy())
	 h1=41;
      if(kbhit())
      {
	 b=getch();
	 if(b==32)
	 {
	    h=h1;
	    if(!f)
	    {
	       ++f;
	       ++att;

	       int temp=0,a=att;
	       while(a)
	       {
		  at[temp++]=(a%10)+48;
		  at[temp]='\0';
		  a/=10;
	       }

	       for(int j=0;j<strlen(at)/2;++j)
	       {
		  temp=at[j];
		  at[j]=at[strlen(at)-j-1];
		  at[strlen(at)-j-1]=temp;
	       }
	    }
	 }
	 else if(b==115)
	 {
	    h1=h1+5;
	 }
	 else if(b==119)
	 {
	    h1=h1-5;
	 }
	 else if(b==13)
	 {
	    pla.money+=(score-miss)*10;
	    getch();
	    report(sc,at,ti);
	    getch();
	    break;
	 }
	 if(ch==4)
	 {
	    if(b==43 && level!=5)
	       ++level;
	    else if(b==45 && level !=1)
	       --level;
	 }
      }
      if(l>=getmaxx()-55 && l<=getmaxx()-5  && h>=k-10 && h<=k+10)
      {
	 --f;
	 l=20;
	 if(h>=k-(level-1)/2 && h<=k+(level-1)/2)
	 {
	    score+=5;
	    ++five;
	 }
	 else if(h>=k-3-(level-1)/2 && h<=k+3-(level-1)/2)
	 {
	    score+=2;
	    ++two;
	 }
	 else
	 {
	    ++score;
	    ++one;
	 }

	 ++shot;

	 k=getmaxy();
      }

	 temp=0;
	 int s=score,sho=shot,f1=five,o1=one;
	 t1=two;

	 while(s)
	 {
	    sc[temp++]=(s%10)+48;
	    sc[temp]='\0';
	    s/=10;
	 }

	 temp=0;
	 while(sho)
	 {
	    sh[temp++]=(sho%10)+48;
	    sh[temp]='\0';
	    sho/=10;
	 }

	 temp=0;
	 while(f1)
	 {
	    fi[temp++]=(f1%10)+48;
	    fi[temp]='\0';
	    f1/=10;
	 }

	 temp=0;
	 while(t1)
	 {
	    tw[temp++]=(t1%10)+48;
	    tw[temp]='\0';
	    t1/=10;
	 }

	 temp=0;
	 while(o1)
	 {
	    on[temp++]=(o1%10)+48;
	    on[temp]='\0';
	    o1/=10;
	 }

	 for(j=0;j<strlen(sc)/2;++j)
	 {
	    temp=sc[j];
	    sc[j]=sc[strlen(sc)-j-1];
	    sc[strlen(sc)-j-1]=temp;
	 }

	 for(j=0;j<strlen(sh)/2;++j)
	 {
	    temp=sh[j];
	    sh[j]=sh[strlen(sh)-j-1];
	    sh[strlen(sh)-j-1]=temp;
	 }

	 for(j=0;j<strlen(fi)/2;++j)
	 {
	    temp=fi[j];
	    fi[j]=fi[strlen(fi)-j-1];
	    fi[strlen(fi)-j-1]=temp;
	 }

	 for(j=0;j<strlen(tw)/2;++j)
	 {
	    temp=tw[j];
	    tw[j]=tw[strlen(tw)-j-1];
	    tw[strlen(tw)-j-1]=temp;
	 }

	 for(j=0;j<strlen(on)/2;++j)
	 {
	    temp=on[j];
	    on[j]=on[strlen(on)-j-1];
	    on[strlen(on)-j-1]=temp;
	 }

      delay(10);


   }
}

// TIC TAC TOE

char square[10],n[2][100];
void tic_tac_toe()
{
   for(int z=1;z<=9;++z)
   {
      square[z]=z+48;
   }
   cleardevice();

   strcpy(n[1],pla.name);
   strcpy(n[2],"CPU");

   int player=1,ch;
   int i=-1;

   board();
   outtextxy(200,350,"Press any key to continue.");
   getch();
   do
   {
      board();
      if(player==1)
      {
	 outtextxy(200,350,"Enter a number.");
	 ch=getch()-48;
	 if(ch<1 || ch>9 || square[ch]=='X' || square[ch]=='0')
	    continue;
	 square[ch]='X';
	 board();
	 player=2;
      }
      else if(player==2)
      {
	 board();
	 moveto(200,380);
	 outtext("CPU enters at :");
	 char pos[2];
	 pos[0]=CPU()+48;
	 pos[1]='\0';
	 outtext(pos);
	 square[pos[0]-48]='0';
	 player=1;
	 getch();
      }
      i=checkwin();
   }
   while(i==-1);

   board();

   if(i==0)
   {
      outtextxy(200,350,"Press any key to continue.");
      getch();
      cleardevice();
      outtextxy(200,100,"GAME DRAW!");
   }
   else
   {
      int n[3];
      n[0]=i/100;
      n[1]=(i/10)%10;
      n[2]=i%10;
      line(210+((n[0]-1)%3)*60,190+((n[0]-1)/3)*60,210+((n[1]-1)%3)*60,190+((n[1]-1)/3)*60);
      line(210+((n[1]-1)%3)*60,190+((n[1]-1)/3)*60,210+((n[2]-1)%3)*60,190+((n[2]-1)/3)*60);
      getch();
      cleardevice();

      if(player==2 && i!=0)
      {
	 pla.money+=1000;
	 outtextxy(200,200,"CONGRATULATIONS! YOU WIN!");
      }
      else if(player==1 && i!=0)
      {
	 pla.money-=500;
	 outtextxy(200,200,"BAD LUCK! CPU WINS!");
      }
   }

   getch();
}

int CPU()
{
   int c=1,ch=c,flag=0,i,j,k,l;
   int p[8]={321,654,987,741,852,963,951,753};
   int a[3]={3,2,1};

   for(i=0;i<8;++i)
   {
      if(flag==1)
	 break;

      a[0]=p[i]/100;
      a[1]=(p[i]%100)/10;
      a[2]=p[i]%10;

      for(j=0;j<3;++j)
      {
	 if(flag==1)
	    break;

	 for(k=j+1;k<3;++k)
	 {
	    for(l=0;l<3;++l)
	       if(l!=k && l!=j)
		  c=a[l];

	    if(square[a[j]]==square[a[k]] && square[a[j]]=='X'  && square[c]!='0' && square[c]!='X')
	    {
	       flag=1;
	       ch=c;
	       break;
	    }
	 }
      }
   }

   for(i=0;i<8;++i)
   {
      if(flag==2)
	 break;

      a[0]=p[i]/100;
      a[1]=(p[i]%100)/10;
      a[2]=p[i]%10;

      for(j=0;j<3;++j)
      {
	 if(flag==2)
	    break;

	 for(k=j+1;k<3;++k)
	 {
	    for(l=0;l<3;++l)
	       if(l!=k && l!=j)
		  c=a[l];

	    if(square[a[j]]==square[a[k]] && square[a[j]]=='0' && square[c]!='X' && square[c]!='0')
	    {
	       flag=2;
	       ch=c;
	       break;
	    }
	 }
      }
   }

   if(!flag)
   {
      randomize();
      do
      {
	 ch = (rand()%9)+1;
      }
      while(square[ch]=='X' || square[ch]=='0');
   }

   return ch;
}

/*********************************************
      1 FOR GAME IS OVER WITH RESULT
     -1 FOR GAME IS IN PROGRESS
      O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
   if (square[1] == square[2] && square[2] == square[3])
      return 123;
   else if (square[4] == square[5] && square[5] == square[6])
      return 456;
   else if (square[7] == square[8] && square[8] == square[9])
      return 789;
   else if (square[1] == square[4] && square[4] == square[7])
      return 147;
   else if (square[2] == square[5] && square[5] == square[8])
      return 258;
   else if (square[3] == square[6] && square[6] == square[9])
      return 369;
   else if (square[1] == square[5] && square[5] == square[9])
      return 159;
   else if (square[3] == square[5] && square[5] == square[7])
      return 357;
   else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	    square[4] != '4' && square[5] != '5' && square[6] != '6' &&
	    square[7] != '7' && square[8] != '8' && square[9] != '9')
      return 0;
   else
      return -1;
}

void board()
{
   cleardevice();

   setcolor(4);
   settextstyle(1,0,2);

   line(180,220,360,220);
   line(180,280,360,280);
   line(240,160,240,350);
   line(300,160,300,350);
   outtextxy(100,10,"TIC TAC TOE - by - RISHAV AGARWAL.");
   moveto(180,120);
   outtext(n[1]);
   outtext(" (X)  -  ");
   outtext(n[2]);
   outtext(" (0)");
   char sq[10][2];
   for(int rt=1;rt<10;++rt)
      sq[rt][0]=square[rt];
   for(rt=0;rt<10;++rt)
      sq[rt][1]='\0';
   int cou=1,rt1;
   for(rt=180;rt<=300;rt+=60)
      for(rt1=200;rt1<=320;rt1+=60)
	 outtextxy(rt1,rt,sq[cou++]);
}

void spin()
{
sp:
   cleardevice();

   char am[20];
   int num,n;

   setcolor(4);
   outtextxy(200,150,"Enter amount to bet:");
   setcolor(9);

   int p,i=0;
   unsigned long amo=0;
   while(1)
   {
      p=getch();
      if(!( (p>=48 && p<=57) || p==8 || p==13) )
	 continue;
      if(p==13)
      {
	 am[i]='\0';
	 break;
      }
      else if(p==8)
      {
	 amo/=10;
	 setcolor(14);
	 char w[1];
	 w[0]=am[--i];
	 outtextxy(200+i*8,180,w);
	 setcolor(9);
      }
      else
      {
	 amo=amo*10+p-48;
	 am[i++]=p;
	 am[i]='\0';
	 outtextxy(200,180,am);
      }
   }

   if(amo>pla.money)
   {
      settextstyle(2,0,5);
      outtextxy(200,300,"You dont have enough money");
      getch();
      goto sp;
   }

   setcolor(4);
   outtextxy(200,200,"Enter number to bet on(0-9):");
   do
   {
      num=getch()-48;
   }
   while(num<0 || num>9);

   char a[3][2];
   for(i=0;i<3;++i)
   {
      a[i][0]=i+48;
      a[i][1]='\0';
   }

   cleardevice();

   outtextxy(300,150,"0");
   settextstyle(0,0,2);
   outtextxy(300,170,"1");
   settextstyle(0,0,1);
   outtextxy(300,200,"2");
   setcolor(9);
   line(290,130,320,130);
   line(290,160,320,160);
   line(290,190,320,190);
   line(290,220,320,220);
   line(290,130,290,220);
   line(320,130,320,220);
   getch();
   setcolor(4);
   int h,z;
   clock_t s;
   randomize();
   z=random(10);
   s=clock();
   while(1)
   {
      cleardevice();

      setcolor(9);
      line(290,130,320,130);
      line(290,160,320,160);
      line(290,190,320,190);
      line(290,220,320,220);
      line(290,130,290,220);
      line(320,130,320,220);
      setcolor(4);
      outtextxy(100,150,"Number selected:");
      char w[1];
      w[0]=num+48;
      w[1]='\0';
      setcolor(9);
      outtextxy(100,170,w);
      setcolor(4);
      for(int i=0;i<3;++i)
      {
	 if(i==1)
	    settextstyle(0,0,2);
	 if(i==2)
	    outtextxy(300,200,a[i]);
	 else
	    outtextxy(300,150+i*20,a[i]);
	 a[i][0]+=1;
	 delay(30);
	 if(a[i][0]>57)
	    a[i][0]-=10;
	 settextstyle(0,0,1);
      }

      if(a[1][0]==z+49 && (clock()-s)/CLK_TCK>=10)
	 break;
   }

   settextstyle(3,0,2);
   if(num==z)
   {
      pla.money+=amo*10;
      outtextxy(400,150,"YOU WIN!");
   }
   else
   {
      pla.money-=amo;
      outtextxy(400,150,"YOU LOSE!");
   }

   getch();
}

void main()
{
   if(!t)
   {
      clrscr();

      int gdriver = DETECT, gmode, errorcode;
      initgraph(&gdriver, &gmode, "");
      errorcode = graphresult();
      if (errorcode != grOk)
      {
	 printf("Graphics error: %s\n", grapherrormsg(errorcode));
	 printf("Press any key to halt:");
	 getch();
	 exit(1);
      }

      intro();
      getch();
      pass();
   }

   {
      int ch=login();

      if(ch==1)
	 New();
      else if(ch==2)
	 sign();
      else
      {
	 closegraph();
	 exit(0);
      }
   }


   while(1)
   {
      int ch=choice();
      if(ch==1)
	 race();
      else if(ch==2)
	 shoot();
      else if(ch==3)
	 tic_tac_toe();
      else if(ch==4)
	 spin();
      else if(ch==5)
      {
	 cleardevice();
	 settextstyle(4,0,1);
	 setcolor(9);
	 outtextxy(100,150,"You are Logged Out !");
	 setcolor(4);
	 getch();
	 t=1;
	 main();
      }

      fstream fs("Player.txt", ios::in | ios::out | ios::ate);
      fs.seekg(0);

      Player play;
      int pos=0;

      while(1)
      {
	 pos=fs.tellg();
	 fs.read((char *)&play, sizeof play);
	 if(fs.eof())
	    break;
	 if(!strcmp(play.acc,pla.acc))
	 {
	    fs.seekg(pos);
	    fs.write((char *)&pla, sizeof pla);
	    break;
	 }
      }

      fs.close();
   }
}