import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int row=in.nextInt();in.nextLine();
		String str=in.nextLine();
		in.close();
		int col=(int)Math.ceil(str.length()*1.0/row);
		char maze[][]=new char[row][col];
		for(int i=col-1,index=0;i>=0;--i) 
			for(int j=0;j<row;++j) 
				if(index>=str.length())maze[j][i]=' ';
				else maze[j][i]=str.charAt(index++);
		for(int i=0;i<row;++i) {
			for(int j=0;j<col;++j)System.out.print(maze[i][j]);
			System.out.println();
		}
	}
}