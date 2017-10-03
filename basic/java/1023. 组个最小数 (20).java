import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int []v=new int[10];
		for(int i=0;i<10;++i)v[i]=in.nextInt();
		for(int i=1;i<10;++i) {
			if(v[i]!=0) {
				--v[i];
				System.out.print(i);
				break;
			}
		}
		for(int i=0;i<10;++i) {
			while(v[i]!=0) {
				--v[i];
				System.out.print(i);
			}
		}
	}
	
}
