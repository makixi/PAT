import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int cnt=0;
		double ave=0;
		for(int i=0;i<n;++i) {
			String s=null;
			double num=0;
			try {
				s=in.next();
				num=Double.parseDouble(s);
				double tmp=Double.parseDouble(String.format("%.2f", num));
				if(num>1000||num<-1000||Math.abs(tmp-num)>=0.001)
					throw new NumberFormatException();
				++cnt;
				ave+=num;
			}catch(NumberFormatException e) {
				System.out.println("ERROR: "+s+" is not a legal number");
			}
		}
		in.close();
		if (cnt == 0) System.out.println("The average of 0 numbers is Undefined");
		else if (cnt == 1) System.out.printf("The average of 1 number is %.2f", ave);
		else System.out.printf("The average of %d numbers is %.2f", cnt, ave / cnt);
	}

}