import java.math.BigInteger;
import java.util.Scanner;

class Main
{

    public BigInteger fact[] = new BigInteger[1010];

    public static void main(String args[])
    {
        Main prog = new Main();
        prog.pregen();
        prog.takeinput();
    }

    void pregen()
    {
        fact[0] = BigInteger.valueOf(1);
        fact[1] = BigInteger.valueOf(1);
        for (int i = 2; i <= 1000; i++)
        {
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
        }
    }

    /*
    void takeinput()
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String str;
        try
        {
            while (!(str = br.readLine()).isEmpty())
            {
                int n = Integer.parseInt(str);
                System.out.println(n + "!");
                System.out.println(fact[n]);
            }
        }
        catch (IOException | NumberFormatException ex)
        {
        }
    }
    */

    void takeinput()
    {
        Scanner sr = new Scanner(System.in);

        try
        {
            while (sr.hasNext())
            {
                int n = sr.nextInt();
                System.out.println(n + "!");
                System.out.println(fact[n]);
            }
        }
        catch (Exception ex) { }
    }
}
