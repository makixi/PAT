import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),k=in.nextInt();
		Map<String,Set<Integer>> ma=new HashMap<String,Set<Integer>>(); 
		for(int i=0;i<k;++i) {
			int index=in.nextInt();
			int num=in.nextInt();
			for(int j=0;j<num;++j) {
				String stu=in.next();
				Set<Integer> s=new HashSet<>();
				if(ma.get(stu)!=null)s=ma.get(stu);
				s.add(index);
				ma.put(stu, s);
			}
		}
		for(int i=0;i<n;++i) {
			String stu=in.next();
			System.out.print(stu+" ");
			if(ma.get(stu)!=null) {
				System.out.print(ma.get(stu).size());
				for(Integer str:ma.get(stu))System.out.print(" "+str);
			}else System.out.print("0");
			System.out.println();
		}
	}

}