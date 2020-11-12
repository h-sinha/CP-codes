import java.lang.Long.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts(): List<Int> = readStrings().map { it.toInt() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        t--;
        var (n, k) = readInts();
        val a = readLine()!!.split(' ').map { it.toLong() }.toTypedArray()
        a.sort();
        var ans = 0L;
        var sum = 0L;
        for (i in 1 until n+1) {
            if (i / k == 0) {
                continue;
            }
            sum = 0;
            var x = i / k;
            for (i in n - i until n - i + x) {
                sum += a[i];
            }
            ans = max(ans, sum);
        }
        println(ans);
    }
}
