import java.io.*;
import java.util.*;

public class R364qA {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);

        int n = in.nextInt();
        int l = in.nextInt();
        int v1 = in.nextInt();
        int v2 = in.nextInt();
        int k = in.nextInt();

        double ans = l * 1.0 / v1;
        int trips = n / k;
        if (n % k != 0)
            trips++;

        double s = 0, e = l + 1;
        for (int i = 0; i < 70 && s <= e; i++) {
            double m = (s + e) / 2;
            boolean f = true;
            double time = 0;
            double busPos = 0;
            for (int j = 0; j < trips; j++) {
                double pos = time * v1;
                if (pos <= busPos) {
                    double timeToMeet = (busPos - pos) / (v1 + v2);
                    double meetPos = pos + timeToMeet * v1;
                    if (meetPos + m > l) {
                        f = false;
                        break;
                    }
                    busPos = meetPos + m;
                    time += timeToMeet + m / v2;
                } else {
                    double timeToMeet = (pos - busPos) / (v2 - v1);
                    double meetPos = pos + timeToMeet * v1;
                    if (meetPos + m > l) {
                        f = false;
                        break;
                    }
                    busPos = meetPos + m;
                    time += timeToMeet + m / v2;
                }
            }
            if (f) {
                ans = m / v2 + (l - m) / v1;
                s = m;
            } else
                e = m;
        }

        w.println(ans);
        w.close();
    }

    static class InputReader {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int snext() {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars) {
                curChar = 0;
                try {
                    snumChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public String readString() {
            int c = snext();
            while (isSpaceChar(c)) {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
}