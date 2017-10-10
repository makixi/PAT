import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double a[]=new double[n];
		for(int i=0;i<n;++i)a[i]=in.nextDouble();
		in.close();
		Arrays.sort(a);
		double tmp=0;
		if(n>=2)tmp=(a[0]+a[1])/2;
		for(int i=2;i<n;++i)tmp=(tmp+a[i])/2;
		System.out.print((int)Math.floor(tmp));
	}
	
}
