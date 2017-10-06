import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int N=in.nextInt();
		int n=getn(N),m=N/n;
		int a[]=new int[N];
		for(int i=0;i<N;++i)a[i]=in.nextInt();
		Arrays.sort(a);
		in.close();
		int maze[][]=new int[m][n];
		int t=N-1;
		for(int i=0;i<(m*1.0+0.5)/2&&t>=0;++i) {
			for(int j=i;j<n-i&&t>=0;++j)maze[i][j]=a[t--];
			for(int j=i+1;j<m-i&&t>=0;++j)maze[j][n-i-1]=a[t--];
			for(int j=n-i-2;j>=i&&t>=0;--j)maze[m-i-1][j]=a[t--];
			for(int j=m-i-2;j>i&&t>=0;--j)maze[j][i]=a[t--];
		}
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				if(j!=0)System.out.print(" ");
				System.out.print(maze[i][j]);
			}
			System.out.println();
		}
	}
	public static int getn(int N) {
		int i=(int)Math.sqrt(N*1.0);
		while(i>1&&N%i!=0) --i;
		return i;
	}
}