#include <stdio.h>

/*There are four numbers: 1, 2, 3, and 4. 
  How many different three-digit numbers can be formed without repeating any digit?
  And what are they?*/
int main(){
	int a=1,b=1,c=1,number=1;

	while(a<=4){
		while(b<=4){
			while(c<=4){
				if(a!=b&&a!=c&&b!=c){
					printf("%d%d%d\n",a,b,c);
					number++;
					}
				c++;
			}
			c=1;
			b++;
		}
		c=1,b=1;
		a++;
	}
  
	printf("There are a total of %d.\n",number);
}
