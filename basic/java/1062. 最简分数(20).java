import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String a[]=in.next().split("/");
		int n1=Integer.parseInt(a[0]),m1=Integer.parseInt(a[1]);
		String b[]=in.next().split("/");
		int n2=Integer.parseInt(b[0]),m2=Integer.parseInt(b[1]);
		int k=in.nextInt();
		double tmp1=(1.0*n1*k)/m1,tmp2=(1.0*n2*k)/m2;
		boolean flag=false;
		if(tmp1>tmp2) {
			double t=tmp1;
			tmp1=tmp2;
			tmp2=t;
		}
		for(int i=(int)tmp1+1;i<tmp2;++i)
			if(judge(i,k)) {
				if(!flag)System.out.print(i+"/"+k);
				else  System.out.print(" "+i+"/"+k);
				flag=true;
			}
	}
	
	public static boolean judge(int i,int k) {
		if(i==1||k==1)return true;
		for(int j=2;j<=i;++j)
			if(k%j==0&&i%j==0)return false;
		return true;
	}
}
