import java.util.Scanner;

public class Main {
	public static final int inf=0x3f3f3f3f;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int val[]=new int[n+1];
		int up[]=new int[n+1];
		int down[]=new int[n+1];
		for(int i=1;i<=n;++i)val[i]=in.nextInt();
		in.close();
		for(int i=2;i<=n;++i)
			for(int j=i-1;j>=1;--j)
				if(val[j]<val[i])up[i]=Math.max(up[i], up[j]+1);
		for(int i=n-1;i>=1;--i)
			for(int j=i+1;j<=n;++j)
				if(val[i]>val[j])down[i]=Math.max(down[i], down[j]+1);
		int maxlen=0,index=0,value=0,diff=inf;
		for(int i=2;i<n;++i)
			if(up[i]!=0&&down[i]!=0)
				if(up[i]+down[i]+1>maxlen) {
					maxlen=up[i]+down[i]+1;
					value=val[i];
					index=i;
					diff=Math.abs(up[i]-down[i]);
				}else if(up[i]+down[i]+1==maxlen&&diff>Math.abs(up[i]-down[i])) {
					diff=Math.abs(up[i]-down[i]);
					index=i;
					value=val[i];
				}
		if(maxlen>0)System.out.print(maxlen+" "+index+" "+value);
		else System.out.print("No peak shape");
	}

}

