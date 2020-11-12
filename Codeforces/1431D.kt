import java.lang.Long.max
import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts(): List<Int> = readStrings().map { it.toInt() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        t--;
        var n = readInt();
        val aa = readLine()!!.split(' ').map { it.toLong() }.toTypedArray()
        var tmp = Vector<Pair<Long, Int>>(n);
        for (i in 0 until n) {
            tmp.addElement(Pair(aa[i], i));
        }
        var a = tmp.sortedBy { it.first };
        var ans = Vector<Int>(n);
        var l = 0;
        var r = n - 1;
        var co = 0;
        var f = 0;
        while (l <= r) {
            if (f == 0) {
                co = 0; f = 1;
            } else co = 1;
            while (l < r && co < a[l].first) {
                ans.add(a[r].second);
                r--;
                co++;
            }
            ans.add(a[l].second);
            l++;
        }
        for (x in ans) {
            print(x + 1)
            print(" ");
        };
        println();
    }
}
