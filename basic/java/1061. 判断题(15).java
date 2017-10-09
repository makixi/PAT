import java.util.HashSet;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt();
		int fullMark[]=new int [m];
		int right[]=new int[m];
		for(int i=0;i<m;++i)fullMark[i]=in.nextInt();
		for(int i=0;i<m;++i)right[i]=in.nextInt();
		for(int i=0;i<n;++i) {
			int s=0;
			for(int j=0;j<m;++j) {
				int tmp=in.nextInt();
				if(tmp==right[j])s+=fullMark[j];
			}
			System.out.println(s);
		}
		in.close();
	}

}
