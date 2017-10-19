import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		n++;
		int cnt=0;
		while(true) {
			String out=in.next();
			if(out.equals("End"))break;
			cnt=(cnt+1)%n;
			if(cnt==0) {
				System.out.println(out);
				continue;
			}
			switch(out.charAt(0)) {
			case 'C':System.out.println("Bu");break;
			case 'J':System.out.println("ChuiZi");break;
			case 'B':System.out.println("JianDao");
			}
		}
		in.close();
	}
}