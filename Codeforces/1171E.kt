//kotlinc file.kt -include-runtime -d file.jar
//java -jar file.jar

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
//fun f(x: Int): Int {
//    var cur = x + 1
//    while (cur % 10 == 0) cur /= 10
//    return cur
//}
//val a: Int? = 1 
// type of var var.javaClass.name
fun main(){
	var n = readInt()
	var s = readLn()
	var co = Array(26, {0})
	for (i in 0..n-1) {
		co[s[i] - 'a']++
	}
	var ones:Int = 0;
	for (i in 0..25){
		if(co[i] > 1){
			ones++
		}
	}
	if(ones == 0 && n > 1){
		println("No")
	}
	else{
		println("Yes")
	}
}