
import java.io.*;
import java.math.*;

class Main
{
    final class Word
    {
        BigInteger number;
        String name;

        Word(BigInteger bi)
        {
            number = bi;
            convertToStr();
        }

        Word(String str)
        {
            name = str;
            convertToNum();
        }

        void convertToStr()
        {
            name = "";
            BigInteger tmp = number;
            while (tmp.compareTo(BigInteger.ZERO) > 0)
            {
                BigInteger drem[] = tmp.divideAndRemainder(
                                        BigInteger.valueOf(26));
                int val = drem[1].intValue() + (int) ('a') - 1;
                name = (char) val + name;
                tmp = drem[0];
            }
        }

        void convertToNum()
        {
            number = BigInteger.ZERO;
            BigInteger tsx = BigInteger.ONE;
            int lf = name.length();
            for (--lf; lf >= 0; --lf)
            {
                char ch = name.charAt(lf);
                int n = (int) ch - (int) ('a') + 1;

                number = number.add(tsx.multiply(BigInteger.valueOf(n)));
                tsx = tsx.multiply(BigInteger.valueOf(26));
            }
        }
    }

    public static void main(String args[]) throws IOException
    {
        Main prog = new Main();
        prog.takeinput(); 
    }

    void takeinput() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true)
        {
            String inp = br.readLine();
            if ("*".equals(inp)) break;

            if (Character.isDigit(inp.charAt(0)))
                printword(new Word(new BigInteger(inp)));
            else
                printword(new Word(inp));
        }
    }

    void printword(Word w)
    {
        System.out.format("%-22s", w.name);
        System.out.format("%,d\n", w.number);
    }
}
