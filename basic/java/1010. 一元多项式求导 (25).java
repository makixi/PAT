import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		boolean first=true;
		while(in.hasNext()) {
			int x=in.nextInt();
			int n=in.nextInt();
			if(x*n!=0) {
				if(!first)System.out.print(" ");
				first=false;
				System.out.print(x*n+" "+(n-1));
			}
		}
		in.close();
		if(first)System.out.print("0 0");
	}
}