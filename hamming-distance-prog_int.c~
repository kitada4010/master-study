//ハミング距離導出プログラム

#include<stdio.h>
int count_bits(unsigned x){
  int count =0;
  while(x){
    if(x & 1U) count++;
    x >>= 1;
  }
  return (count);
}


int int_bits(void){
  return (count_bits(~0U));
}

void print_bits(unsigned x){
  int i;
  for(i = int_bits() - 1; i >= 0; i--)
    putchar(((x >> i) & 1U) ? '1' : '0');
}

int main(void){
  //  char x1=1100, x2=0011;
  //  char i;
  unsigned x1=0000, x2=0011, i;
  i=x1^x2;
  
  //    printf("%u\n",i);
  print_bits(i);
  
  return 0;
}
