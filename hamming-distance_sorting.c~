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

int number_bits(unsigned x){
  int i=0;
  int bits=0;
  for(i = int_bits() - 1; i >= 0; i--){
    if((x >> i) & 1U)
      bits++;
  }
  return bits;
}

int main(void){
  int x[16];
  int char_x[16][7];
  FILE *bit_input;
  //  char i;
  int j=0, k;
  unsigned i;
  int bit_count, patern_count;
  //unsigned x1=0000, x2=0011, i;
  
  if((bit_input = fopen("filename", "r")) == NULL){
    printf("can not open file\n");
    return 0;
  }
  
  x[0]=0b0000000;
  x[1]=0b0001111;
  x[2]=0b0010011;
  x[3]=0b0011100;
  x[4]=0b0100101;
  x[5]=0b0101010;
  x[6]=0b0110110;
  x[7]=0b0111001;
  x[8]=0b1000110;
  x[9]=0b1001001;
  x[10]=0b1010101;
  x[11]=0b1011010;
  x[12]=0b1100011;
  x[13]=0b1101100;
  x[14]=0b1110000;
  x[15]=0b1111111;
  /*  while((fscanf(bit_input, "%s", &char_x[j])) != EOF){ //符号語の読み込み
    j++;
    printf("%s\n", char_x[j]);
    
    }*/

  for(j=0; j<16; j++){  //比較作業
    for(k=j+1; k<16; k++){
      i=x[j]^x[k];
      bit_count = number_bits(i);     
      //printf("\n%d\n",count);    
      if(bit_count == 3){
	patern_count++;
	printf("x_{%d}, x_{%d} \n", j+1,k+1);
      }
    }
  }
  //printf("%u\n",i);
  //print_bits(i);
 
  printf("%d\n", patern_count);
  
	 
  return 0;
}
