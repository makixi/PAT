import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int res1=0,res2=0;
		for(int i=0;i<n;++i) {
			int a=in.nextInt(),b=in.nextInt(),c=in.nextInt(),d=in.nextInt();
			if(b==a+c&&d==a+c)continue;
			if(b!=a+c&&d!=a+c)continue;
			if(b==a+c)res2++;
			if(d==a+c)res1++;
		}
		System.out.print(res1+" "+res2);
	}
}