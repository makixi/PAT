import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		int rankg[]=new int [n/2];
		int rankb[]=new int [n/2];
		int i,b,g;
		Vector<String> girl=new Vector<>();
		Vector<String> boy=new Vector<>();
		for(i=0,b=0,g=0;i<n;++i) {
			if(in.nextInt()==1) {boy.add(in.next());rankb[b++]=i;}
			else {girl.add(in.next());rankg[g++]=i;}
		}
		in.close();
		for(i=0,g=0,b=0;i<n/2;++i) {
			if(rankg[g]<rankb[b]) 
			{System.out.println(girl.get(g)+" "+boy.get(boy.size()-1-g));++g;}
			else {System.out.println(boy.get(b)+" "+girl.get(girl.size()-1-b));++b;}
		}
	}
}