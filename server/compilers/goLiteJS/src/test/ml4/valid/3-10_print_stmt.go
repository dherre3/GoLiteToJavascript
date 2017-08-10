package main

type salary float64

type employee struct {
	id int
	name string
	sex rune
	wage salary
}

func main() {
	println(3,"hello", 'c', true)
	//Printing new line in Raw string
	println(`\t\n
	`,"\n\t",'\n')
	println("	 \b \f \n\r\t\v\\")
	print("`",'`',``)
	var e employee
	println(e.id, e.name, e.sex)
	print(e.id, e.name, e.sex)
}
