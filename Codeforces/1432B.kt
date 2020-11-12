private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        var n = readInt();
        if (n < 3) {
            println(0);
            t--;
            continue;
        }
        var x = n / 2;
        if (n % 2 == 1) {
            println(x);
        } else {
            println(x - 1);
        }
        t--;
    }
}