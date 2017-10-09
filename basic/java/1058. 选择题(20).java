import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt();
		Question q[]=new Question[m];
		for(int i=0;i<m;++i) {
			q[i]=new Question(in.nextInt(),0);
			in.nextInt();int num=in.nextInt();
			for(int j=0;j<num;++j) {
				char ch=in.next().charAt(0);
				q[i].trueChoose.add(ch);
			}
		}
		for(int i=0;i<n;++i) {
			int score=0;
			in.nextLine();		//	\n
			for(int j=0;j<m;++j) {
				Set<Character> set=new HashSet<>();
				int k=0;
				String ss=null;
				while(true) {
					ss=in.next();
					if(Character.isDigit(ss.charAt(ss.length()-1))) {
						k=ss.charAt(ss.length()-1)-'0';
						break;
					}
				}
				for(int l=0;l<k;++l) {
					set.add(in.next().charAt(0));
				}
				if(set.equals(q[j].trueChoose))score+=q[j].fullScore;
				else q[j].wrongTime++;
			}
			System.out.println(score);
		}
		int cnt=0;
		for(int i=0;i<m;++i)
			if(q[i].wrongTime>cnt)cnt=q[i].wrongTime;
		if(cnt==0)System.out.print("Too simple");
		else {
			System.out.print(cnt);
			for(int i=0;i<m;++i)
				if(q[i].wrongTime==cnt)
					System.out.print(" "+(i+1));
		}
	}

}

class Question{
	int fullScore;
	int wrongTime;
	Set<Character> trueChoose;
	
	public Question(int ff,int ww) {
		this.fullScore=ff;
		this.wrongTime=0;
		this.trueChoose=new HashSet<>();
	}
}