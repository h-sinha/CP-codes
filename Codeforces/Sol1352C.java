import java.util.Scanner; 

public class Sol1352C{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
			t--;
			int n = sc.nextInt();
			int k = sc.nextInt();
			int x = (k-1)/(n-1);
			System.out.println(k + x);
		}
	}
}
