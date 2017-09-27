import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		int sum=0;
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		in.nextLine();
		String[] s=new String[n];
		for(int i=0;i<n;++i) {
			boolean isOther=false;
			s[i]=new String(in.nextLine());
			for(int j=0;j<s[i].length();++j)
				if(s[i].charAt(j)!='P'&&s[i].charAt(j)!='A'&&s[i].charAt(j)!='T') {
					System.out.println("NO");
					isOther=true;
					break;
				}
			if(!isOther) {
				if(judge(s[i]))System.out.println("YES");
				else System.out.println("NO");
			}
		}
		in.close();
		
	}
	public static boolean judge(String s) {
		int p=s.indexOf('P'),t=s.indexOf('T');
		if(p>t)return false;
		String a=null,b=null,c=null;
		if(p!=-1)a=s.substring(0, p);
		else return false;
		if(t!=-1)c=s.substring(t+1,s.length());
		else return false;
		b=s.substring(p+1,t);
		if (a.contains("P") || a.contains("T") || b.contains("T") || b.contains("P") || c.contains("P")
				|| c.contains("T")) 
			return false;
		if(c.length()<a.length())return false;
		if(b.length()==0)return false;
		if(a.equals(c)&&a.equals(""))return true;
		int cnt=0;
		for(int i=0;i<=c.length()-a.length();i+=a.length())
			if(a.equals(c.substring(i,i+a.length())))cnt++;
		if(cnt==b.length())return true;
		else return false;
	}
}
