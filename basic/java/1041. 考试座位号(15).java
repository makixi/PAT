import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String args[])throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(in.readLine());
		Student v[]=new Student[n];
		for(int i=0;i<n;++i) {
			String str[]=in.readLine().split(" ");
			v[i]=new Student(str[0],str[1],str[2]);
		}
		int m=Integer.parseInt(in.readLine());
		String s[]=in.readLine().split(" ");
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(v[j].test.equals(s[i])) {
					System.out.println(v[j].id+" "+v[j].curr);
					break;
				}
		in.close();
	}
}

class Student{
	String id;
	String test;
	String curr;
	public Student(String i,String t,String c) {
		this.id=i;
		this.test=t;
		this.curr=c;
	}
}

