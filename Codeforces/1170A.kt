//kotlinc file.kt -include-runtime -d file.jar
//java -jar file.jar

private fun readLn() = readLine()!!
private fun readInt() = readLn().toLong()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints
//fun f(x: Int): Int {
//    var cur = x + 1
//    while (cur % 10 == 0) cur /= 10
//    return cur
//}
//val a: Int? = 1 
// type of var var.javaClass.name
fun main(){
	var t = readInt()
	while(t>0){
		var(x,y) = readInts()
		if(x>y){
			print(1)
			print(" ")
			print(x-y+1)
			print(" ")
			print(y-1)
			println()
		}
		else{
			print(1)
			print(" ")
			print(y-x+1)
			print(" ")
			print(x-1)
			println()
		}
		t--
	}	
}