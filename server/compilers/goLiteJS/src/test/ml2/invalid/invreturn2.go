package main
//Error: Not a return on the nested else if expression

func main() bool{
    var a bool = true;
    if a {
        return true
    }else if a {
        
    }else if a {
        return true
    }else {
        return false
    }
}
