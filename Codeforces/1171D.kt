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
	var (x,y,z) = readInts() 	
	var (a,b,c) = readInts() 	
	a -= x
	var f:Int = 0
	if(a < 0){
		f = 1
	}
	var sum:Int = a + b
	sum -= y
	if( sum < 0){
		f = 1
	}
	sum += c
	sum -= z
	if(sum < 0){
		f = 1
	}
	if(f == 0){
		println("YES")
	}
	else{
		println("NO")
	}
}