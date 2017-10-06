import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double []v=new double[n];
		double res=0;
		for(int i=0;i<n;++i) v[i]=in.nextDouble();
		for(int i=0;i<n;++i) res+=v[i]*(n-i)*(i+1);
		System.out.printf("%.2f", res);
	}
}