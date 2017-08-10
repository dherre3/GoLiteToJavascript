package main


func main()	{
	var c = 0;
	var g = 0;
	for i:=0;i<5;c = 5 {
		i++
		if i == 4 {
			continue;
		}
		
		println(i,c)
		for j:=0;j<5;j++ {

			if j == 4 {
				
				continue;
			}
			println(j,i)
			
			for l:=0;l<5;l++ {

				if l == 4 {
					continue;
				}
				println(j,i,l)
				break;
				for k:=0;k<5;g=0 {
					k++
					if k == 4 {
						continue;
					}
					
					println(j,i,l,g,k)
					break;

				}

			}

		}
		

	}

}
