import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.NoSuchElementException;

import javax.print.attribute.HashAttributeSet;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	private static Node[] V;
	private static ArrayDeque<Set> que = new ArrayDeque<>();
	private static long bipfalse = 0;
	private static long biptrue = 0;
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		V = new Node[n];
		for(int i=0; i<n; i++) {
			V[i] = new Node();
		}
		for(int i=0; i<n-1; i++) {
			int l = sc.nextInt()-1;
			int r = sc.nextInt()-1;
			V[l].nbr.add(r);
			V[r].nbr.add(l);
		}
		
		que.add(new Set(0, true));
		while(!que.isEmpty()) {
			Set set = que.poll();
			V[set.id].dfs(set.bip);
		}
		
		
		System.out.println(bipfalse * biptrue - (n - 1));
	}
	
	static class Node {
		HashSet<Integer> nbr = new HashSet<>();
		boolean visited = false;
		boolean bip = false;
		
		void dfs(boolean befbip) {
			visited = true;
			bip = !(befbip);
			if(bip) {
				biptrue++;
			} else {
				bipfalse++;
			}
			
			for(int x : nbr) {
				if(!V[x].visited) {
					que.add(new Set(x, bip));
				}
			}
		}
	}
	
	static class Set {
		int id;
		boolean bip;
		Set(int id, boolean bip) {
			this.id = id;
			this.bip = bip;
		}
	}
	
	static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}