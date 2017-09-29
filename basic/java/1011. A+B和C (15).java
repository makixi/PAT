import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		for(int i=1;i<=n;++i) {
			long a=in.nextLong();
			long b=in.nextLong();
			long c=in.nextLong();
			if(a+b>c)System.out.println("Case #"+i+": true");
			else System.out.println("Case #"+i+": false");
		}
		in.close();
	}
}
