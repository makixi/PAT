import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cnt=0;
		String a="",b="";
		while(true) {
			String str=in.nextLine();
			if(str.equals("."))break;
			++cnt;
			if(cnt==2)a=str;
			else if(cnt==14)b=str;
		}
		if(cnt<2)System.out.println("Momo... No one is for you ...");
		else if(cnt<14)System.out.println(a+" is the only one for you...");
		else System.out.println(a+" and "+b+" are inviting you to dinner...");
	}
}