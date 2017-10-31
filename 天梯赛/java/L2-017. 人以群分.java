import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),sum=0,halfsum=0;
		int v[]=new int[n];
		for(int i=0;i<n;++i) {
			v[i]=in.nextInt();sum+=v[i];
		}
		Arrays.sort(v);
		int icnt=n/2,ocnt=n-icnt;
		for(int i=0;i<icnt;++i)halfsum+=v[i];
		System.out.printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", ocnt,icnt,sum-2*halfsum);
;	}
	

}
