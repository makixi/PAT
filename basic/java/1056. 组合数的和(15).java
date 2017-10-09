import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int res=0;
		int []v=new int[n];
		for(int i=0;i<n;++i)v[i]=in.nextInt();
		in.close();
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j) {
				res+=v[i]*10+v[j];
				res+=v[j]*10+v[i];
			}
		System.out.print(res);
	}

}

