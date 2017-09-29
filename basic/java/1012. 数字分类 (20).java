import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int v[]=new int[n];
		int a[]=new int[6];
		double a4=0;
		boolean a2=true;
		for(int i=0;i<n;++i) {
			v[i]=in.nextInt();
			switch(v[i]%5) {
			case 0:if(v[i]%2==0)a[1]+=v[i];break;
			case 1:if(a2) {
				a[2]+=v[i];a2=false;
			}else {
				a[2]-=v[i];a2=true;
			}
			break;
			case 2:a[3]+=1;break;
			case 3:a[4]+=1;a4+=v[i];break;
			case 4:a[5]=Math.max(a[5],v[i]);break;
			}
		}
		in.close();
		for(int i=1;i<=5;++i) {
			if(i!=1)System.out.print(" ");
			if(a[i]==0) 
				System.out.print("N");
			else {
				if(i==4) 
					System.out.format("%.1f", a4/a[4]);
				else
					System.out.print(a[i]);
			}
		}
	}
}