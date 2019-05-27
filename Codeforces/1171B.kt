private fun readLn() = readLine()!! // line
private fun readInt() = readLn().toInt() //int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
//fun f(x: Int): Int {
//    var cur = x + 1
//    while (cur % 10 == 0) cur /= 10
//    return cur
//}
//val a: Int? = 1
fun main(){
	var (y,b,r) = readInts()
	b -= 1;
	r -= 2;
	println(minOf(y, b, r)*3+3)
}