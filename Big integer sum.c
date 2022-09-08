//big integer sum 
#include<stdio.h>
int my_strlen(char *s){
    int cnt=0;
    for(int i=0;*s!='\0';i++){
        *s++;
        cnt++;
    }
    return cnt;
}

int main(){
    char s1[100000000];
    char s2[100000000];
    scanf("%s",s1);
    scanf("%s",s2);
    int l1,l2;
    
    l1=my_strlen(s1);
    l2=my_strlen(s2);
    int k;
    if(l1>l2){
        k=l1;
    }
    else{
        k=l2;
    }
    int c=0,s=0;
    char ret[100000000];
    ret[k]='\0';
    int i,j,p;
    i=l1-1,j=l2-1,p=k-1;
    while(i>=0 && j>=0){
        s=(s1[i]-'0')+(s2[j]-'0')+c;
        ret[p]='0'+(s%10);
        c=s/10;
        i--;
        j--;
        p--;
        }
    if(i>=0){
        while(i>=0){
           s=(s1[i]-'0')+c;
            ret[p]='0'+(s%10);
            c=s/10;
            i--;
            p--; 
        }
    }
    else if(j>=0){
        while(j>=0){
            s=(s2[j]-'0')+c;
            ret[p]='0'+(s%10);
             c=s/10;
             j--;
             p--;
        }
    }
    if(c>0){
        int h=my_strlen(ret);
        for(int i=h;i>=0;i--){
            ret[i+1]=ret[i];
        }
        ret[0]='0'+c;
    }
   printf("%s",ret);
   
    return 0;
}