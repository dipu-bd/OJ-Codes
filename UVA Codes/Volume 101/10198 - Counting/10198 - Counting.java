
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

    final int max = 1005;
    BigInteger count[] = new BigInteger[max + 10];

    public static void main(String args[])
    {
        Main prog = new Main();
        prog.precalc();
        prog.input();
    }

    void precalc()
    {
        count[0] = BigInteger.ZERO;
        count[1] = BigInteger.valueOf(2);
        count[2] = BigInteger.valueOf(5);
        count[3] = BigInteger.valueOf(13);
        for (int i = 4; i < max; ++i)
        {
            count[i] = count[i - 1];
            count[i] = count[i].add(count[i - 1]);
            count[i] = count[i].add(count[i - 2]);
            count[i] = count[i].add(count[i - 3]);
        }
    }

    void input()
    {
        Scanner sr = new Scanner(System.in);

        while (true)
        {
            try
            {
                int n = sr.nextInt();
                System.out.println(count[n]);
            }
            catch (Exception ex)
            {
                return;
            }
        }
    }
}
