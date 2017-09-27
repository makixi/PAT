import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		String maxName=null,maxId=null,minName=null,minId=null;
		int maxS=0,minS=100;
		for(int i=0;i<n;++i) {
			String name,id;
			int score;
			name=in.next();id=in.next();score=in.nextInt();
			if(score>maxS) {
				maxS=score;
				maxName=name;maxId=id;
			}
			if(score<minS) {
				minS=score;
				minName=name;minId=id;
			}
		}
		System.out.println(maxName+" "+maxId);
		System.out.println(minName+" "+minId);
	}
}
