#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string num[]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
string level[]={"","","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
vector<string> res;
int main(){
	string str;
	cin>>str;
	if(str[0]=='-'){
		cout<<"Fu ";
		str.erase(0,1);
	}
	int len=str.length();
	if(str=="0"){    //�������Ե����ʱ��
		cout<<"ling"<<endl;
		return 0;
	}
	bool flag1=false,flag2=false;
	for(int i=0;i<len;++i){
		if(str[i]!='0'&&!flag1)
			flag1=true;
		if(!flag1)continue;		//����ǰ׺��0
		if(str[i]=='0'&&!flag2)	//wanλ����0
			flag2=true;
		if(str[i]!='0'&&flag2)
			{flag2=false;res.push_back("ling");}
		if(str[i]=='0'&&(len-i!=5||((len==9)&&str.substr(1,4)=="0000")))		//����wan ��������
			continue;
		if(str[i]!='0')
			res.push_back(num[str[i]-'0']);
		if(len-i>1)
			res.push_back(level[len-i]);
	}
	for(int i=0;i<res.size();++i){
		if(i)
			cout<<" ";
		cout<<res[i];
	}
	return 0;
}
