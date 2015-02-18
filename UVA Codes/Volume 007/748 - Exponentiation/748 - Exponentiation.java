import java.math.BigDecimal;
import java.util.Scanner;

class Main
{

    public static void main(String args[])
    {
        Scanner sr = new Scanner(System.in);

        while (true)
        {
            try
            {
                BigDecimal R = new BigDecimal(sr.next());
                int N = sr.nextInt();
                R = R.pow(N).stripTrailingZeros();
                String res = R.toPlainString();
                if(res.charAt(0) == '0') res = res.substring(1);
                System.out.println(res);
            }
            catch (Exception ex)
            {
                return;
            }
        }
    }
}
