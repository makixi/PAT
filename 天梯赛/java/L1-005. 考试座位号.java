import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		Map<Integer,String> id=new HashMap<>();
		Map<Integer,Integer> seat=new HashMap<>();
		for(int i=0;i<n;++i) {
			String str=in.next();
			int tryseat=in.nextInt();
			int testseat=in.nextInt();
			id.put(tryseat, str);
			seat.put(tryseat, testseat);
		}
		int m=in.nextInt();
		for(int i=0;i<m;++i) {
			int q=in.nextInt();
			System.out.println(id.get(q)+" "+seat.get(q));
		}
	}	
}
