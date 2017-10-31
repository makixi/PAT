import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double sum=0;
		Map<String,Boolean> m=new HashMap<>();
		Map<String,Integer> zan=new HashMap<>();
		List<String> v=new LinkedList<>();
		for(int i=0;i<n;++i) {
			String str=in.next();m.put(str, true);
		}
		n=in.nextInt();
		for(int i=0;i<n;++i) {
			String str=in.next();
			int tmp=in.nextInt();
			zan.put(str, tmp);
			sum+=tmp;
		}
		sum/=n;
		for(Map.Entry<String, Integer> entry:zan.entrySet()) {
			if(m.get(entry.getKey())!=null)continue;
			if(entry.getValue()>sum)v.add(entry.getKey());
		}
		if(v.size()==0)System.out.println("Bing Mei You");
		Collections.sort(v);
		for(int i=0;i<v.size();++i)
			System.out.println(v.get(i));
	}

}
