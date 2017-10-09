import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		double res=0;
		for(int i=0;i<n;++i) {
			int a=in.nextInt(),b=in.nextInt();
			double tmp=Math.sqrt(a*a+b*b);
			if(tmp>res)res=tmp;
		}
		System.out.printf("%.2f", res);
	}
	
}
