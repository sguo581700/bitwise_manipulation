#include<iostream>
#include<math.h>
#include<assert.h>
const int SIZE = 32;
int* bit_converter( int& input)
{
  int exp = log2(input);
  int bit_digits = exp+1;
  int*ptr = new int[SIZE];
  for(int i=0; i<SIZE;i++)
  {
    ptr[i]=0;
  }  
  for(int i=SIZE-bit_digits; i<SIZE-1;i++)
  {    
    ((input/(pow(2,exp)))>=1)?(ptr[i]=1, input=input-pow(2,exp)):(ptr[i]=0);
    exp--;
    bit_digits--;
  } 
	ptr[SIZE-1]=(input%2==0)?0:1;
	return ptr;
}
void print_bin(int*ptr)
{
	int counter =0;
	for(int i=0; i<SIZE;i++)
	{
		printf("%d", ptr[i]);
		counter++;
		(counter==4)?printf(" "), counter=0 : NULL;
	}
}
int digit_converter(int*bin_arr)
{
	int digit=0;
	int exp=SIZE-1;
	for(int i=0;i<SIZE;i++)
	{
		digit+= (bin_arr[i]==0) ? 0 : pow(2,exp);
		exp=exp-1;
	}
	return digit;
}
int main()
{
	int input = 999;
	int max_input=INT_MAX;
	assert(input<=max_input);
	printf("Input is %d", input);	
	int*ptr=bit_converter(input);
	printf("\nafter the conversion to binary : \n");
	print_bin(ptr);
	printf("\nAfter converting back to digits: %d\n",digit_converter(ptr));
}

