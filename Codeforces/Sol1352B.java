import java.util.Scanner; 

public class Sol1352B{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
			t--;
			int n = sc.nextInt();
			int k = sc.nextInt();
			int n1 = n - k + 1;
			if(n1 > 0 && n1%2 == 1){
				System.out.println("YES");
				for (int i=0;i<k-1;i++) {
					System.out.print("1 ");	
				}
				System.out.println(n1);
				continue;
			}
			n1 = n - 2*(k-1);
			if(n1 > 0 && n1%2 == 0){
				System.out.println("YES");
				for (int i=0;i<k-1;i++) {
					System.out.print("2 ");	
				}
				System.out.println(n1);
				continue;
			}
			System.out.println("NO");
		}
	}
}
