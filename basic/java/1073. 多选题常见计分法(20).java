import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt();
		Ques v[]=new Ques[m+1];
		int wt[][]=new int [m][5];
		List<Option> res=new ArrayList<>();
		for(int i=0;i<m;++i) {
			v[i]=new Ques(in.nextInt());
			in.nextInt();
			int k=in.nextInt();
			for(int j=0;j<k;++j) 
				v[i].list.add(new Character(in.next().charAt(0)));
		}
		for(int i=0;i<n;++i) {
			double score=0;
			for(int j=0;j<m;++j) {
				String ss=in.next();	
				int len=ss.charAt(ss.length()-1)-'0';
				List<Character> tmp=new ArrayList<>();
				int mark[]=new int [5];
				for(int k=0;k<len;++k) {
					char c=in.next().charAt(0);
					tmp.add(new Character(c));
					mark[c-'a']=1;
				}
				if(tmp.equals(v[j].list)) {
					score+=v[j].fullMark;
					continue;
				}
				boolean flag1=false,flag2=true;
				for(int k=0;k<v[j].list.size();++k) {
					if(mark[v[j].list.get(k)-'a']==1) {
						mark[v[j].list.get(k)-'a']=2;
						flag1=true;
					}
					else 
						mark[v[j].list.get(k)-'a']=-1;
				}
				for(int k=0;k<5;++k)
					if(mark[k]==-1||mark[k]==1) {
						wt[j][k]++;
						if(mark[k]==1) 
							flag2=false;
					}
				if(flag1&&flag2)score+=v[j].fullMark*1.0/2;
			}
			System.out.printf("%.1f\n", score);
		}
		int maxwt=0;
		for(int i=0;i<m;++i)
			for(int j=0;j<5;++j)
				if(wt[i][j]!=0) {
					res.add(new Option(i,j,wt[i][j]));
					maxwt=Math.max(maxwt, wt[i][j]);
				}
		if(maxwt==0)System.out.print("Too simple");
		else {
			Collections.sort(res);
			for(int i=0;i<res.size()&&res.get(i).wrongTime==maxwt;++i)
				System.out.println(res.get(i).wrongTime+" "+(res.get(i).qnum+1)+"-"+(char)(res.get(i).onum+'a'));
		}
	}
}

class Option implements Comparable<Option>{
	int qnum;
	int wrongTime;
	int onum;
	
	public Option(int qq,int nn,int ww) {
		this.qnum=qq;
		this.wrongTime=ww;
		this.onum=nn;
	}
	
	@Override
	public int compareTo(Option a) {
		if(a.wrongTime!=this.wrongTime) {
			if(this.wrongTime>a.wrongTime)return -1;
			else return 1;
		}else if(a.qnum!=this.qnum) {
			if(this.qnum<a.qnum)return -1;
			else return 1;
		}else {
			if(this.onum<a.onum)return -1;
			else if(this.onum>a.onum)return 1;
			else return 0;
		}
	}
}

class Ques{
	int fullMark;
	List<Character> list;
	
	public Ques(int ff) {
		this.fullMark=ff;
		list=new ArrayList<>();
	}
}