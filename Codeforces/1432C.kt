private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts(): List<Long> = readStrings().map { it.toLong() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        var n = readInt();
        var arrayint = List<Long>(n) { 0 }
        arrayint = readInts();
        var sum = 0L;
        for (x in arrayint) {
            sum += x;
        }
        var l = 0;
        var r = 10000000;
        while (l < r - 1) {
            var mid = (l + r) / 2;
            if (mid * n >= sum) r = mid;
            else l = mid;
        }
        if (l * n < sum) l = r;
        println(l);
        t--;
    }
}