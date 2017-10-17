import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int mark[]=new int[1001];
		for(int i=0;i<n;++i) {
			int k=in.nextInt();
			for(int j=0;j<k;++j) {
				mark[in.nextInt()]++;
			}
		}
		int maxcnt=mark[1000],maxnum=1000;
		for(int i=1000;i>=1;--i)
			if(mark[i]>maxcnt) {
				maxcnt=mark[i];
				maxnum=i;
			}
		System.out.print(maxnum+" "+maxcnt);
	}
}