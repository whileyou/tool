//支持+-*/()^混合运算，算式长度小于100，输入数据范围应在long long范围内
//注:^为乘方
//直接输入一行合法的算式即可得结果
#include <stdio.h>
#include <string.h>
#include <math.h>
char x,cha[100],a[10]={'(',')','+','-','*','/','^'},go[100];
long long top1,top2,num[100],know[10][10],f[300],len,shu,jud;
int ope(){
	if(!top2) return 0;
	long long cal;
	if(cha[top2]=='+') cal=num[top1-1]+num[top1];
	else if(cha[top2]=='-') cal=num[top1-1]-num[top1];
	else if(cha[top2]=='*') cal=num[top1-1]*num[top1];
	else if(cha[top2]=='/') cal=num[top1-1]/num[top1];
	else if(cha[top2]=='^') cal=pow(num[top1-1],num[top1]);
	else if(cha[top2]=='('){
		top2--;return 0;
	}
	num[--top1]=cal;
	if(x!=')'&&(top2<=1||know[f[x]][f[cha[top2-1]]])){
		cha[top2]=x;return 0;
	}
	else{
		if(cha[top2]=='('){
			top2--;return 0;
		}
		top2--;
	}
	return 1;
}
int main()
{
	for(int i=0;i<7;i++) f[a[i]]=i;
	for(int i=0;i<7;i++) know[0][i]=know[i][0]=1;
	know[1][0]=0;
	for(int i=2;i<4;i++) know[4][i]=know[5][i]=1;
	for(int i=2;i<7;i++) know[6][i]=1;
	scanf("%s",go);len=strlen(go);
	for(int i=0;i<len;i++){
		x=go[i];
		if(x>='0'&&x<='9'){
			if(!jud) shu=x-'0';
			else shu=(shu)*10+x-'0';
			jud=1;
		}
		else{
			if(jud) num[++top1]=shu;
			jud=0;
			if(!top2){
				cha[++top2]=x;continue;
			}
			if(know[f[x]][f[cha[top2]]]) cha[++top2]=x;
			else if(x==')') while(ope());
			else while(ope());
		}
	}
	if(x!=')') num[++top1]=shu;
	x=')';
	while(ope());
	printf("%lld",num[1]);
	return 0;
}
