import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		String s=in.next();
		in.close();
		int cntt=0,cntp=0,res=0;
		for(int i=0;i<s.length();++i)
			if(s.charAt(i)=='T')++cntt;
		for(int i=0;i<s.length();++i)
			if(s.charAt(i)=='P')++cntp;
			else if(s.charAt(i)=='A')res=(res+cntt*cntp)%1000000007;
			else if(s.charAt(i)=='T')--cntt;
		System.out.print(res);
	}
}

