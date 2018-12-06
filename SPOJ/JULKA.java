import java.math.*;
import java.util.Scanner;

public class JULKA
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<10;++i)
        {
            BigInteger num = sc.nextBigInteger();
            BigInteger ans=num.subtract(BigInteger.valueOf(2));
            ans=ans.divide(BigInteger.valueOf(2));
            System.out.println(ans);
        }

    }
}
