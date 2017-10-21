import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int m=in.nextInt(),n=in.nextInt();
		int a[][]=new int [m][n];
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)a[i][j]=in.nextInt();
		int x=in.nextInt(),y=in.nextInt();
		int b[][]=new int [x][y];
		for(int i=0;i<x;++i)
			for(int j=0;j<y;++j)b[i][j]=in.nextInt();
		if(n!=x)System.out.printf("Error: %d != %d\n",n,x);
		else {
			System.out.println(m+" "+y);
			for(int i=0;i<m;++i)
				for(int j=0;j<y;++j) {
					int sum=0;
					for(int k=0;k<n;++k)sum+=a[i][k]*b[k][j];
					if(j<y-1)System.out.print(sum+" ");
					else System.out.println(sum);
				}
		}
	}
}
