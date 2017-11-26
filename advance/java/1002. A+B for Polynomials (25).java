import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;

public class Main{
	public static final int maxn=1001;
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		double c[]=new double [maxn];
		double num;
		int cnt=0;
		int k=in.nextInt();
		for(int i=1;i<=k;++i) {
			int tmp=in.nextInt();
			num=in.nextDouble();
			c[tmp]+=num;
		}
		int j=in.nextInt();
		for(int i=1;i<=j;++i) {
			int tmp=in.nextInt();
			num=in.nextDouble();
			c[tmp]+=num;
		}
		for(int i=0;i<maxn;++i)if(c[i]!=0)++cnt;
		System.out.print(cnt);
		if(cnt>0)System.out.print(" ");
		for(int i=maxn-1;i>=0;--i)
			if(c[i]!=0) {
				System.out.printf("%d %.1f",i,c[i]);
				--cnt;
				if(cnt>=1)System.out.print(" ");
			}
	}
	
	
}

