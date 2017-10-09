import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int b[]=new int[n];
		for(int i=0;i<n;++i) {
			b[i]=sum(in.nextInt());
		}
		in.close();
		Arrays.sort(b);
		int cnt=0;
		if(n>=1)++cnt;
		for(int i=1;i<n;++i)if(b[i]!=b[i-1])++cnt;
		System.out.println(cnt);
		if(n>=1)System.out.print(b[0]);
		for(int i=1;i<n;++i)if(b[i]!=b[i-1])System.out.print(" "+b[i]);
	}
	
	public static int sum(int n) {
		int res=0;
		while(n>0) {
			res+=n%10;
			n/=10;
		}
		return res;
	}
}
