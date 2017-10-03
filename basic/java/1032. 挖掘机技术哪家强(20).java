import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int ress=0,resg=0;
		int v[]=new int[100000];
		for(int i=0;i<n;++i) {
			int a,b;
			a=in.nextInt();b=in.nextInt();
			v[a]+=b;
			if(v[a]>resg) {
				resg=v[a];
				ress=a;
			}
		}
		System.out.print(ress+" "+resg);
	}
	
}