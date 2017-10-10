import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int m=in.nextInt(),n=in.nextInt(),s=in.nextInt();
		Map<String,Integer> award=new HashMap<>();
		in.nextLine();
		boolean flag=false;
		for(int i=1;i<=m;++i) {
			String tmp=in.nextLine();
			if(award.get(tmp)!=null)++s;
			if(i==s&&award.get(tmp)==null) {
				award.put(tmp, 1);
				System.out.println(tmp);
				flag=true;
				s+=n;
			}
		}
		if(!flag)System.out.print("Keep going...");
	}
	
}
