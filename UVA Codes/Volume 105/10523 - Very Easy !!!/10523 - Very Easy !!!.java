
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

    public static void main(String args[])
    {
        Scanner sr = new Scanner(System.in);

        while (true)
        {
            try
            {
                int n = sr.nextInt();
                BigInteger A = new BigInteger(sr.next());

                BigInteger sum = BigInteger.ZERO;
                BigInteger pow = A;
                for (int i = 1; i <= n; ++i)
                {
                    sum = sum.add(pow.multiply(BigInteger.valueOf(i)));
                    pow = pow.multiply(A);
                }

                System.out.println(sum);
            }
            catch (Exception ex)
            {
                return;
            }
        }
    }
}
