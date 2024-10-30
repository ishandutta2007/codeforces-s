import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //InputStream inputStream = new FileInputStream("bluetube.in");//System.in;
        //OutputStream outputStream = new FileOutputStream("bluetube.out");//.out;
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;


        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }
}



class Solver {

    int res (String a, String b) {
        if (a.equals(b))
            return 0;
        if (a.equals("[]")) {
            if (b.equals("()")) {
                return 1;
            } else {
                return -1;
            }
        }
        if (a.equals("()")) {
            if (b.equals("[]"))
                return -1;
            else
                return 1;

        }
        return -res(b, a);
    }

    public void solve(InputReader in, PrintWriter out) {
        String a = in.next();
        String b = in.next();

        int cnt = 0;

        for (int i = 0; i < a.length() / 2; ++i) {
            cnt += res(a.substring(2 * i, 2 * i + 2), b.substring(2 * i, 2 * i + 2));
        }
        if (cnt < 0) {
            out.println("TEAM 2 WINS");
        } else if (cnt == 0) {
            out.println("TIE");
        } else {
            out.println("TEAM 1 WINS");
        }

    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}