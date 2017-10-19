import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int cnt=0;
		while(in.hasNextInt()) {
			++cnt;
			if(in.nextInt()==250)break;
		}
		in.close();
		System.out.print(cnt);
	}
}