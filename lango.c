#include <stdio.h>

int transtr(char* str);

int main()
{
	char str[20];
	int ret;
	
	while(1){
		printf("lango>");
		gets(str);

		if(strcmp(str,"quit")==0)
			return 0;

		if(transtr(str)){
		    printf("error\n");
		    continue;
		}
		printf("%s\n",str);
	}
	return 0;
}

int transtr(char* str){
    char* str1=str;
    char table[20][8];
    int i=0,j=0,n;
    int sta=0,sta0=0;

    //while(*str1!='\0'){
       // if((*str1>'9')||(*str1<'('))
         //   return 1; 
      // str1++; 
    //} 

    //str1=str;
    while(*str1!='\0'){
        sta=(*str1>='0')?0:1;

        if(sta!=sta0){
                
                table[i][j]='\0';
                i++;
                j=0;
        }
        if(*str1!=' ')
        table[i][j]=*str1;
        j++;
        str1++;

        sta0=sta;
    }
    table[i][j]='\0';


    for(n=0;n<=i;n++)
        printf("%s ",table[n]);
        printf("%d\n",i+1);
	return 0;
}

