import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		for(int i=0;i<n;++i) {
			Map<Integer,Character> m=new HashMap<>();
			Map<Integer,Integer> t=new HashMap<>();
			int cnt=0,sum=0;
			while(true) {
				int index=in.nextInt();
				char flag=in.next().charAt(0);
				String tmp[]=in.next().split(":");
				int times=Integer.parseInt(tmp[0])*60+Integer.parseInt(tmp[1]);
				if(index==0)break;
				if(flag=='S') {
					m.put(index, flag);
					t.put(index, times);
				}else {
					if(m.get(index)==null||m.get(index)!='S')continue;
					else {
						cnt++;
						sum+=times-t.get(index);
						m.remove(index);
						t.remove(index);
					}
				}
			}
			if(cnt==0)System.out.println(0+" "+0);
			else System.out.println(cnt+" "+(int)Math.round(sum*1.0/cnt));
		}
		in.close();
	}
}
