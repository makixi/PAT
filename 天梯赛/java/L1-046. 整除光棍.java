import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();in.close();
		long res=1;
		int cnt=1;
		while(res<n) {
			++cnt;
			res=res*10+1;
		}
		while(true) {
			if(res%n==0) {
				System.out.print(res/n);
				break;
			}else {
				System.out.print(res/n);
				res%=n;
				res=res*10+1;
				++cnt;
			}
		}
		System.out.println(" "+cnt);
	}
}
