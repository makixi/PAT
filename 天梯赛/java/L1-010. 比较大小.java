import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int a[]=new int [3];
		for(int i=0;i<3;++i)a[i]=in.nextInt();
		in.close();
		Arrays.sort(a);
		for(int i=0;i<3;++i) {
			if(i!=0)System.out.print("->");
			System.out.print(a[i]);
		}
	}	
}
