import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int h=in.nextInt();
		System.out.printf("%.1f", (h-100)*1.0*0.9*2);
	}
}