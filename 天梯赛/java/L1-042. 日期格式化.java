import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String[]res=in.next().split("-");
		System.out.print(res[2]+"-"+res[0]+"-"+res[1]);
	}
}