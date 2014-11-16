#include <stdio.h>

int transtr(char* str);
int gettype(char c);
int chack(char* str);
int tonum(char* str);

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
    int sta_table[20]; 
    int i=0,j=0,n;
    int sta=0,sta0;//×ÖÄ¸×´Ì¬0ÎªÊı×Ö 1Îª·ûºÅ 
    int sum=0;    

    if(chack(str))
    return 1;
    	
    while(*str1==' ')
        str1++;
    sta0=gettype(*str1);
    while(*str1!='\0'){
        sta=gettype(*str1);
        if(*str1!=' '){       
        if(sta!=sta0){
                table[i][j]='\0';
                i++;
                j=0;
        }
       
                table[i][j]=*str1;
                sta_table[i]=sta;
                j++;
        }
        str1++;
        sta0=sta;
    }
    table[i][j]='\0';

    //for(n=0;n<=i;n++)                  
    //    printf("%s ",table[n]);
   // printf("%d\n",i+1);
    
    //for(n=0;n<=i;n++)
     //   printf("%d ",sta_table[n]);
   // printf("%d\n",i+1);
    
    if(sta_table[0]==0)
        sum=tonum(table[0]);
        //printf("res=%d\n",sum);
    for(n=0;n<=i;n++){
        if(sta_table[n]!=0)
        switch(*table[n]){
                case '-':
                sum-=tonum(table[n+1]);break;
                default:
                sum+=tonum(table[n+1]);
                
        }
    }
       sprintf(str,"res=%d",sum);
    

	return 0;
}
int tonum(char* str)
{
    int res=0;
    while(*str!='\0'){
        res=res*10+*str-'0';
        str++;
     }
     return res;
}
int gettype(char c)
{
    int sta;
    if(c==' ')
        return 9;
    sta=(c>='0')?0:1;
    return sta;
}

int chack(char* str)

{
    if(*str=='\0')
        return 1;
    while(*str!='\0'){
        if((*str>'9')||(*str<' '))
            return 1; 
       str++; 
    }
    return 0;
}
