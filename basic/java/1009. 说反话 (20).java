import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		String[] res=in.nextLine().split(" ");
		for(int i=res.length-1;i>=0;--i) {
			System.out.print(res[i]);
			if(i!=0)System.out.print(" ");
		}
		in.close();
	}
}
