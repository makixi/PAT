import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int c=0;
		String res="";
		String n=in.next(),a=in.next(),b=in.next();
		a=reverse(a);b=reverse(b);n=reverse(n);
		for(int i=0;i<n.length();++i) {
			int m=n.charAt(i)-'0';
			int tmp=0;
			if(i<a.length())tmp+=a.charAt(i)-'0';
			if(i<b.length())tmp+=b.charAt(i)-'0';
			tmp+=c;
			if(m==0)m=10;
			c=tmp/m;
			tmp%=m;
			res+=(char)(tmp+'0');
		}
		while(c>0) {
			int tmp=c%10;
			c/=10;
			res+=(char)(tmp+'0');
		}
		res=reverse(res);
		int i=0;
		while(i<res.length()&&res.charAt(i)=='0')++i;
		if(i>=res.length())System.out.print("0");
		else System.out.print(res.substring(i, res.length()));
	}
	
	public static String reverse(String a) {
		String res="";
		for(int i=a.length()-1;i>=0;--i)
			res+=a.charAt(i);
		return res;
	}
}
