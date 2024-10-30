import java.lang.*
import java.lang.Integer.*

fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

    val A = 150013
    var cnt = IntArray(A)
    var res = IntArray(A)

    for(x in a)
        cnt[x]++

    for(i in 1 until A) {
        if(cnt[i] > 0) {
            if(i > 1 && res[i - 1] == 0) {
                cnt[i]--
                res[i - 1]++
            }

            if(cnt[i] > 0 && res[i] == 0) {
                cnt[i]--
                res[i]++
            }

            if(cnt[i] > 0) {
                res[i + 1]++
            }
        }
    }

    var ans = 0
    for(i in 1 until A)
        if(res[i] > 0)
            ans++

    println(ans)
}

/*fun main(args : Array<String>) {
    var (n, k) = readLine()!!.split(" ").map { it.toInt() }

    if(k > n) {
        println("NO")
        return
    }

//    var res = mutableListOf<Int>()
//    var res = MutableList<Int>(31, Int(0))
    var cnt = IntArray(31)
    var cur = 0
    for(i in 0..30) {
        if(((1 shl i) and n) > 0) {
            cnt[i] = 1
            cur++
        }
    }

    if(cur > k) {
        println("NO")
        return
    }

    for(i in 30 downTo 1) {
        var d = min(k - cur, cnt[i])
        cnt[i] -= d
        cnt[i - 1] += d * 2
        cur += d
    }

    println("YES")
    for(i in 0..30) {
        for(j in 0 until cnt[i])
            print("${1 shl i} ")
    }
}*/

/*fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

    a.sort()

    var inc = mutableListOf<Int>()
    var dec = mutableListOf<Int>()
    for(i in 0 until n) {
        if(i > 0 && a[i] == a[i - 1]) {
            if(i > 1 && a[i] == a[i - 2]) {
                println("NO");
                return
            }
            dec.add(a[i])
        } else {
            inc.add(a[i])
        }
    }

    println("YES")
    println(inc.size)
    for(x in inc)
        print("$x ")
    println()

    println(dec.size)
    for(i in dec.size - 1 downTo 0)
        print("${dec[i]} ")
    println()
}*/

/*fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

    a.sort()

    var i = 0
    var ans = 0
    while(i < n) {
        ans += a[i + 1] - a[i]
        i += 2
    }

    println(ans)
}*/

/*fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var s = readLine()!!

    var i = 0
    var step = 1
    while(i < n) {
        print(s[i])
        i += step
        step++
    }
}*/

/*fun main(args : Array<String>) {
    var _t = readLine()!!.toInt()
    for(test in 0 until _t) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map{it.toInt()}.toMutableList()

        for(i in 1 until n) {
            if(a[i] != a[0]) {
                if((i != 1) or (a[1] != a[2])) {
                    println(i + 1)
                } else {
                    println(1);
                }
                break;
            }
        }
    }
}*/