import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		Map<Integer,Integer> couple=new HashMap<>();
		for(int i=0;i<n;++i) {
			int a=in.nextInt(),b=in.nextInt();
			couple.put(a, b);
			couple.put(b,a);
		}
		int m=in.nextInt();
		List<Integer> res=new ArrayList<>();
		boolean mark[]=new boolean[100000];
		int attend[]=new int[m];
		for(int i=0;i<m;++i) {
			attend[i]=in.nextInt();
			mark[attend[i]]=true;
		}
		in.close();
		for(int i=0;i<m;++i) 
			if((couple.get(attend[i])==null)||(!mark[couple.get(attend[i])])) 
				res.add(attend[i]);
		System.out.println(res.size());
		int ans[]=new int[res.size()];
		for(int i=0;i<res.size();++i) ans[i]=res.get(i);
		Arrays.sort(ans);
		for(int i=0;i<res.size();++i) {
			if(i!=0)System.out.print(" ");
			System.out.printf("%05d",ans[i]);
		}
	}
	
}
