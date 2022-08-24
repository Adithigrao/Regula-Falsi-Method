/* Header Files */
#include<stdio.h>
#include<conio.h>
#include<math.h>
/* Defining equation to be solved.*/

#define   f(x)   pow(x,3)-2*x-5

int main()
{
	
	 float x0, x1, x2, f0, f1, f2, err;
	 int iteration = 1;
	 clrscr();
	 /* Inputs */
	 in:
	 printf("\nEnter two initial values:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &err);
	 /* Calculating Functional Values */
	 f0 = f(x0);
	 f1 = f(x1);
	 /* Checking whether given values brackets the root or not. */
	 if( f0*f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto in;
	 }
	 /* Implementing Regula Falsi or False Position Method */
	 printf("\niteration\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
	 do
	 {
		  x2 = x0 - (x0-x1) * f0/(f0-f1);
		  f2 = f(x2);
		  printf("%d\t\t%f\t%f\t%f\t%f\n",iteration, x0, x1, x2, f2);
		
		  if(f0*f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  iteration = iteration + 1;
	
	 }while(fabs(f2)>err);

	 printf("\nRoot is: %f", x2);
	 getch();
	 return 0;
}
