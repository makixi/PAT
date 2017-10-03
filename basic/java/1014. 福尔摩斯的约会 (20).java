import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String a=in.nextLine();
		String b=in.nextLine();
		String c=in.nextLine();
		String d=in.nextLine();
		in.close();
		boolean week=false;
		boolean hour=false;
		for(int i=0;i<a.length()&&i<b.length();++i) {
			if(hour&&week)break;
			if(a.charAt(i)==b.charAt(i)) {
				if(a.charAt(i)>='A'&&a.charAt(i)<='G'&&!week) {
					week=true;
					switch(a.charAt(i)) {
					case 'A':System.out.print("MON ");break;
					case 'B':System.out.print("TUE ");break;
					case 'C':System.out.print("WED ");break;
					case 'D':System.out.print("THU ");break;
					case 'E':System.out.print("FRI ");break;
					case 'F':System.out.print("SAT ");break;
					case 'G':System.out.print("SUN ");break;
					}
				}
				else if (((a.charAt(i) >= 'A' && a.charAt(i) <= 'N') || Character.isDigit(a.charAt(i))) && !hour && week) {
					hour = true;
					if (a.charAt(i) >= '0' && a.charAt(i) <= '9')
						System.out.print("0" + a.charAt(i));
					else
						System.out.print(a.charAt(i) - 'A' + 10);
				}
			}
		}
		for (int i = 0; i < c.length() && i < d.length(); i++)
			if ((Character.isUpperCase(c.charAt(i)) || Character.isLowerCase(c.charAt(i)))&& c.charAt(i) == d.charAt(i)) {
				System.out.printf(":%02d", i);break;
			}
	}
}