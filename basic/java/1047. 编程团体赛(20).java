import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int maxn=0;
		int team[]=new int[1001];
		int res=0;
		for(int i=0;i<n;++i) {
			String[] s=in.next().split("-");
			int teamId=Integer.parseInt(s[0]);
			int score=in.nextInt();
			team[teamId]+=score;
			if(team[teamId]>maxn) {
				maxn=team[teamId];
				res=teamId;
			}
		}
		System.out.print(res+" "+maxn);
	}
}