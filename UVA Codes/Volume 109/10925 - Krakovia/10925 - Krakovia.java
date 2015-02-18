
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

    public static void main(String args[])
    {
        Scanner sr = new Scanner(System.in);

        int cas = 1;
        while (true)
        {
            try
            {
                int n = sr.nextInt();
                int f = sr.nextInt();
                if (n == 0) return;

                BigInteger A = BigInteger.ZERO;
                for (int i = 0; i < n; ++i)
                {
                    A = A.add(new BigInteger(sr.next()));
                }

                BigInteger res = A.divide(BigInteger.valueOf(f));

                System.out.format("Bill #%d costs %d: each friend should pay %d\n\n",
                                  cas++, A, res);
            }
            catch (Exception ex)
            {
                return;
            }
        }
    }
}
