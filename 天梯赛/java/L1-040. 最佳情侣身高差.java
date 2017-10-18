import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		for(int i=0;i<n;++i) {
			String sex=in.next();
			double height=in.nextDouble();
			if(sex.equals("M")) System.out.printf("%.2f\n", height/1.09);
			else System.out.printf("%.2f\n", height*1.09);
		}
		in.close();
	}
}