import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int a=in.nextInt(),b=in.nextInt();in.close();
		int sum=0;
		for(int i=a;i<=b;++i) {
			sum+=i;
			System.out.printf("%5d", i);
			if((i-a+1)%5==0&&i!=b)System.out.println();
		}
		System.out.print("\nSum = "+sum);
	}	
}
