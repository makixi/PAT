import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int i,week=0,hour;
		String a=in.nextLine();
		String b=in.nextLine();
		String c=in.nextLine();
		String d=in.nextLine();
		boolean flag1=false;
		for(i=0;i<(a.length()<=b.length()?a.length():b.length());++i)
			if(a.charAt(i)==b.charAt(i)&&('A'<=a.charAt(i)&&a.charAt(i)<='G')&&!flag1){flag1=true;week=i;}
			else if(a.charAt(i)==b.charAt(i)&&flag1&&(('A'<=a.charAt(i)&&a.charAt(i)<='N')||Character.isDigit(a.charAt(i))))break;
		week=a.charAt(week)-'A'+1;
		if(Character.isUpperCase(a.charAt(i)))
			hour=a.charAt(i)-'A'+10;
		else
			hour=a.charAt(i)-'0';
		for(i=0;i<(c.length()<=d.length()?c.length():d.length());++i)
			if(c.charAt(i)==d.charAt(i)&&Character.isAlphabetic(c.charAt(i)))break;
		switch(week){
			case 1:System.out.print("MON");break;
			case 2:System.out.print("TUE");break;
			case 3:System.out.print("WED");break;
			case 4:System.out.print("THU");break;
			case 5:System.out.print("FRI");break;
			case 6:System.out.print("SAT");break;
			case 7:System.out.print("SUN");break;
		}
		System.out.printf(" %02d:%02d",hour,i);
	}
}

