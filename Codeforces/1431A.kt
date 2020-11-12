import java.lang.Long.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        t--;
        var n = readInt();
        val a = readLine()!!.split(' ').map { it.toLong() }.toTypedArray()
        a.sort();
        var sum = 0L;
        var ans = 0L;
        for (x in a) {
            sum += x;
        }
        var idx = 0L;
        for (x in a) {
            ans = max(ans, (n - idx) * x);
            idx++;

        }
        println(ans);
    }
}
