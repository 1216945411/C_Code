#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp=NULL;
	FILE *fp_out=NULL;
	char ch;
	char buff_DMR_file_out[512];
	char buff_DMR_file_in[256];
	const char *filename="./DMR.txt";
	fp=fopen(filename,"a+t");
	if(fp==NULL)
	{
		exit(1);
	}
	const char *filename_out="./DMR_out.txt";
	fp_out=fopen(filename_out,"a+t");
	while(fgets(buff_DMR_file_in,256,fp))
	{
		int j =0;
		for(int i=0;i<256;i++)
		{ 
			if( (buff_DMR_file_in[i] >= '0' && buff_DMR_file_in[i] <= '9') || (buff_DMR_file_in[i] >= 'a' && buff_DMR_file_in[i] <= 'f'))
			{
				if((buff_DMR_file_in[i+1] >= '0' && buff_DMR_file_in[i+1] <= '9') || (buff_DMR_file_in[i+1] >= 'a' && buff_DMR_file_in[i+1] <= 'f')){
					buff_DMR_file_out[j] = '0';
					buff_DMR_file_out[j+1] = 'x';
					buff_DMR_file_out[j+2] = buff_DMR_file_in[i];
					buff_DMR_file_out[j+3] = buff_DMR_file_in[i+1];
					buff_DMR_file_out[j+4] = ',';
					j += 5;
				}
			}else{

				if((buff_DMR_file_in[i]=='\n') || (buff_DMR_file_in[i]==32)){
					if(buff_DMR_file_in[i+1]!=32){
						buff_DMR_file_out[j] = buff_DMR_file_in[i];
						j++;
					}
				}
			}		
			if((buff_DMR_file_in[i]=='\r')){
				buff_DMR_file_out[j] = '\r';
				buff_DMR_file_out[j+1] = '\n';
				fflush(fp_out);
				fwrite(buff_DMR_file_out,j+2,1,fp_out);
				break;
			}
		}

	}
	fclose(fp);
	fclose(fp_out);
	return 0;
}
