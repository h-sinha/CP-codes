private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
fun main() {
    var t = readInt();
    while (t > 0) {
        t--;
        var s = readLn();
        var co = 0;
        for(x in s){
            if(x == 'w')co++;
        }
        var co1 = 0;
        var c = 0;
        var n = s.length;
        var i = 0;
        while(i<n){
            c = 0;
            if(s[i] == 'v'){
                for(j in i until n){
                    if(s[j] == 'v') {
                        i = j;
                        c++
                    };
                    else break;
                }
            }
            co1 += (c/2);
            i++;
        }
        println(co + co1);
    }
}