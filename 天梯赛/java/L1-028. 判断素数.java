import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		for(int i=0;i<n;++i) {
			if(judge(in.nextInt()))System.out.println("Yes");
			else System.out.println("No");
		}
		in.close();
	}
	public static boolean judge(int n) {
		if(n<=1)return false;
		for(int i=2;i*i<=n;++i)if(n%i==0)return false;
		return true;
	}
}