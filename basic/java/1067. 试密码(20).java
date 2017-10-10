import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String correct=in.next();
		int n=in.nextInt();
		int cnt=0;
		in.nextLine();
		while(in.hasNext()) {
			String input=in.nextLine();
			if(input.equals("#"))break;
			if(input.equals(correct)) {
				System.out.println("Welcome in");
				break;
			}
			++cnt;
			System.out.println("Wrong password: "+input);
			if(cnt==n) {
				System.out.println("Account locked");
				break;
			}
		}
		in.close();
	}
	
}
