//ハミング距離導出プログラム

#include<stdio.h>
#define LENG_HAMMING 7
void bit_input(int x[16]){  //符号語の入力
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
  
}

int count_bits(unsigned x){  //2進数表記時の1の数をカウントする関数
  int count =0;
  while(x){
    if(x & 1U) count++;
    x >>= 1;
  }
  return (count);
}

void print_bits(unsigned x){  //2進数表示する関数
  int i;
  for(i = LENG_HAMMING -1; i >= 0; i--)
    putchar(((x >> i) & 1U) ? '1' : '0');
  putchar('\n');
}

/*---------------------------------------------------------------------------*/
int main(void){
  int x[16];
  int char_x[16][7];
  FILE *hamming_matrix; //ハミング距離の結果を出力するtexファイルのファイルポインタ
  int j=0, k;
  unsigned i;
  int bit_count, patern_count;
  
  if((hamming_matrix = fopen("hamming_matrix.tex", "w")) == NULL){
    printf("can not open file\n");
    return 0;
  }
  
  bit_input(x);
  
  fprintf(hamming_matrix, "\\begin{tabular}{| r | r | r | r | r | r | r | r | r | r | r | r | r | r | r | r | r |} \\hline"); 
  fprintf(hamming_matrix, " & $x_{0}$ & $x_{1}$ & $x_{2}$ & $x_{3}$ & $x_{4}$ & $x_{5}$ & $x_{6}$ & $x_{7}$ & $x_{8}$ & $x_{9}$ & $x_{10}$ & $x_{11}$ & $x_{12}$ & $x_{13}$ & $x_{14}$ & $x_{15}$\\\\ \\hline");

  for(j=0; j<16; j++){  //ハミング距離の導出
    fprintf(hamming_matrix, " $x_{%d}$ ", j);
    for(k=0; k<16; k++){
      if(k>j){
	i=x[j]^x[k];
	bit_count = count_bits(i);     
	if(bit_count == 3){
	  patern_count++;
	  printf("x_{%d}, x_{%d} \n", j+1,k+1);  //ハミング距離が3のペアを出力
	}
	fprintf(hamming_matrix, "& %d ", bit_count);
      }
      else{
	fprintf(hamming_matrix, "& \\diagbox{　}{　}");
      } 
    }
    fprintf(hamming_matrix, "\\\\ \\hline \n");
  }
  fprintf(hamming_matrix, "\\end{tabular}");
  printf("%d\n", patern_count);  //ハミング距離が3のペアの合計数を出力
  
  fclose(hamming_matrix);
	 
  return 0;
}
