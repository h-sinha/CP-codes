import java.util.Scanner; 
import java.util.ArrayList;

public class Sol1352D{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t > 0){
			t--;
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i=0;i<n;++i){
				a[i] = sc.nextInt();
			}
			int aa = a[0], b = 0, co = 1;
			int l = 1, r = n-1, prv = aa, f = 0, cur;
			while(l<=r)
			{
				co++;
				cur = 0;
				while(f == 1 && l<=r && cur<=prv){
					cur += a[l];
					l++;
					aa += a[l];
				}
				while(f == 0 && l<=r && cur<=prv){
					cur += a[r];
					b += a[r];
					r--;
				}
				System.out.println("cur " + cur);
				prv = cur;
				f = 1-f;
			}
			System.out.println(co + " " + aa + " " + b);
		}
	}
}
