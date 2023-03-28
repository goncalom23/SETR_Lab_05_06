//write a C code to implement cyclic  codes.
#include<stdio.h>
#include<conio.h>

void main()
{
int n,k,g[10],C[10],M[10],I,T[10];
int i,j,r;
clrscr();

printf("\n\n Enter The Value Of n and k\t:\n");
scanf("%d%d",&n,&k);
printf("\n Enter The Generator Polynomial Of Dergee %d",(n-k));
printf(" of the form 1+x+xý+x³+...\n");

for(i=0;i<n-k;i++)
scanf("%d",&g[i]);
printf("\nEnterMsg\n");

for(i=0;i<k;i++)
scanf("%d",&M[i]);
printf("\n\n");

for(i=0;i<n-k;i++)
{
T[i]=0;
}

for(i=0;i<k;i++)
{
I = (M[i] + T[n-k-1])%2;
C[0] = I;


for(j=1;j<n-k;j++)
{
if(g[j]==1)
C[j]=(I + T[j-1])%2;
else
C[j]=T[j-1];

}

for(r=0;r<n-k;r++)
{
T[r]=C[r];
}
}

printf("\n³\tGenerated Cyclic code is\t: ");
for(i=0;i<k;i++)
printf("%d",M[i]);
printf(" ");
for(i=0;i<n-k;i++)
printf("%d",C[i]);
getch();
}
 