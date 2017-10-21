import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		for(int i=0;i<n;++i) {
			String name=in.next();
			int a=in.nextInt(),b=in.nextInt();
			if(a<15||a>20||b<50||b>70)System.out.println(name);
		}
		in.close();
	}
}
