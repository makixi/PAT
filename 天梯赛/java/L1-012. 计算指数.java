import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		System.out.printf("2^%d = %d", n,(1<<n));
	}	
}
