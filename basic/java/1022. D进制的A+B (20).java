import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		long a=in.nextLong();
		long b=in.nextLong();
		int d=in.nextInt();
		in.close();
		long c=a+b;
		String res="";
		while(c>0) {
			res+=c%d;
			c/=d;
		}
		for(int i=res.length()-1;i>=0;--i)
			System.out.print(res.charAt(i));
	}
	
}
