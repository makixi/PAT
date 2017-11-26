import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		node v[]=new node[n];
		int cnt=0;
		for(int i=0;i<n;++i) {
			v[i]=new node(in.next(),in.next());
			String tmp="";
			for(int j=0;j<v[i].password.length();++j) {
				if(v[i].password.charAt(j)=='1')tmp+='@';
				else if(v[i].password.charAt(j)=='0')tmp+='%';
				else if(v[i].password.charAt(j)=='l')tmp+='L';
				else if(v[i].password.charAt(j)=='O')tmp+='o';
				else tmp+=v[i].password.charAt(j);
			}
			if(!tmp.equals(v[i].password)) {
				v[i].output=true;
				v[i].newpass=tmp;
				++cnt;
			}
		}
		if(cnt==0) {
			if(n==1) System.out.print("There is 1 account and no account is modified");
			else System.out.print("There are "+n+" accounts and no account is modified");
		}else {
			System.out.println(cnt);
			for(int i=0;i<n;++i) 
				if(v[i].output)System.out.println(v[i].name+" "+v[i].newpass);
		}
	}
}

class node{
	String name;
	String password;
	String newpass;
	boolean output;
	node(String name,String password){
		this.name=name;
		this.password=password;
		this.output=false;
	}
}