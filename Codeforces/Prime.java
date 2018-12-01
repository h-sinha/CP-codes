import java.math.*;
import java.util.Scanner;

public class Prime
{
    public static void main(String args[]) throws Exception
    {
            Scanner sc = new Scanner(System.in);
            Integer n = sc.nextInt();
            BigInteger x = sc.nextBigInteger();
            BigInteger a[] = new BigInteger[n];
            BigInteger sumis= new BigInteger("0");
            BigInteger cumsum= new BigInteger("0");
            BigInteger result,exponent,base;
            for(int i = 0; i < n; i++)
            {
                a[i] = sc.nextBigInteger();
                cumsum=cumsum.add(a[i]);
                exponent = a[i];
                base=x;
                result=BigInteger.ONE;
                while (exponent.signum() > 0) 
                {
                    if (exponent.testBit(0)) result = result.multiply(base);
                     base = base.multiply(base);
                    exponent = exponent.shiftRight(1);
                }
                a[i]=result;
            }
            result =BigInteger.ONE;
            exponent=cumsum;
            base=x;
            while (exponent.signum() > 0) 
            {
                if (exponent.testBit(0)) result = result.multiply(base);
                base = base.multiply(base);
                exponent = exponent.shiftRight(1);
            }
            cumsum=result;
            for(int i = 0; i < n; i++)
            {
                a[i]=cumsum.divide(a[i]);
                sumis=sumis.add(a[i]);
            }
            cumsum = cumsum.gcd(sumis);
            BigInteger MOD= new BigInteger("1000000007");
            System.out.println(cumsum.mod(MOD));

    }
}