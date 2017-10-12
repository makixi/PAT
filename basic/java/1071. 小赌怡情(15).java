import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int t=in.nextInt(),k=in.nextInt();
		for(int i=0;i<k;++i) {
			int n1=in.nextInt(),b=in.nextInt(),tt=in.nextInt(),n2=in.nextInt();
			if(t<tt)System.out.print("Not enough tokens.");
			else {
				if((n2>n1&&b!=0)||(n2<n1&&b==0)) {
					System.out.print("Win "+tt+"!");
					t+=tt;
				}else if(t>=tt) {
					System.out.print("Lose "+tt+".");
					t-=tt;
				}
			}
			System.out.println("  Total = "+t+".");
			if(t<=0) {
				System.out.print("Game Over.");
				break;
			}
		}
		in.close();
	}
	
}
