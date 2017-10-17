import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		char c=in.next().charAt(0);
		in.nextLine();
		String str=in.nextLine();
		in.close();
		while(str.length()<=n) str=c+str;
		while(str.length()>n) str=str.substring(1);
		System.out.println(str);
	}
}