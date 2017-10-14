import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int res=0,sum=1;
		for(int i=1;i<=n;++i) {
			sum*=i;
			res+=sum;
		}
		System.out.print(res);
	}	
}
