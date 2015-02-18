import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Solver
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {

        System.out.println("\n ======= Polynomial Equation Solver ======= ");
        System.out.println();

        try
        {

            double[] var = GetInput();
            double x = Solve(var);

            System.out.format("RESULT:\n    X = %.6f",  x);
            System.out.println();

        }
        catch (Exception ex)
        {
            System.out.println();
            System.out.println("Error: " + ex.getMessage());
            System.out.println();
        }
    }

    public static double[] GetInput()
    {

        Scanner inp = new Scanner(System.in);

        //get maximum exponent of x
        System.out.print("Maximum exponent of X: ");
        int n = inp.nextInt();
        System.out.println(n);

        //show whole equation
        System.out.print("Equation: ");
        for (int i = 1, j = n; j > 1; --j, ++i)
        {
            System.out.print("(a" + i + ")x^" + j + " + ");
        }
        System.out.println("(a" + n + ")x + (a" + (n + 1) + ") = 0");
        System.out.println("Here : ");

        double val[] = new double[n + 1];
        for (int i = 0; i <= n; ++i)
        {
            System.out.print("    a[" + (i + 1) + "] = ");
            val[i] = inp.nextDouble();
            System.out.println(val[i]);
        }
        System.out.println();

        return val;

    }


    public static double Abs(double val)
    {
        if (val < 0)
        {
            return -val;
        }
        return val;
    }

    public static double GetVal(double x, double val[])
    {
        double res = 0;
        double pwx = 1;
        for (int i = val.length - 1; i >= 0; --i)
        {
            res += val[i] * pwx;
            pwx *= x;
        }
        return res;
    }

    public static double Solve(double... val) throws Exception
    {

        final double EXP = 1E-8;
        final double STEP = 1E-12;
        final double MAXD = 1E11;

        double low, high, mid;
        low = -MAXD;
        high = MAXD;

        do {

            mid = (low + high) / 2.0;

            double res = GetVal(mid, val);
            if (Abs(res) < EXP)
            {
                return mid;
            }

            if (res < 0)
            {
                low = mid + STEP;
            }
            else {
                high = mid - STEP;
            }

            //System.out.println("[" + mid + "]");

        }
        while (low < high);

        throw new Exception("Can't Solve.");
    }
}

