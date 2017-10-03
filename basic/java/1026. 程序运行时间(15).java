import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		in.close();
		int s=(int)((b-a)*1.0/100+0.5);
		System.out.printf("%02d:%02d:%02d", s/3600,s/60%60,s%60);
	}
	
}
