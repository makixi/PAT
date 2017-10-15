import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int limit1=in.nextInt(),limit2=in.nextInt();
		int n=in.nextInt(),cnt1=0,cnt2=0;
		for(int i=0;i<n;++i) {
			int a=in.nextInt(),b=in.nextInt(),c=in.nextInt(),d=in.nextInt();
			if((b==a+c)&&(d==a+c))continue;
			if((b!=a+c)&&(d!=a+c))continue;
			if(b==a+c)cnt1++;
			if(d==a+c)cnt2++;
			if(cnt2>limit2)break;
			if(cnt1>limit1)break;
		}
		if(cnt1>limit1)System.out.printf("A\n%d",cnt2);
		else System.out.printf("B\n%d",cnt1);
	}	
	
}
