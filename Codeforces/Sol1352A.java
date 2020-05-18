import java.util.Scanner; 
import java.util.ArrayList;

public class Sol1352A{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int n, val = 1, cur;
		while(t>0){
			ArrayList<Integer> ans = new ArrayList();
			n = sc.nextInt();
			val = 1;
			System.out.println("n = "+ n);
			while(n > 0)
			{
				cur = n%10;
				n/=10;
				if(cur>0){
					ans.add(cur*val);
				}
				val *= 10;
			}
			t--;
			System.out.println(ans.size());
			for(int x:ans){
				System.out.print(x);
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}