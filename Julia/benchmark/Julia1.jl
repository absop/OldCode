# Int
sum2 = function (n::Int)
	x = 0
	for i in 1:n
		x += i
	end
	print("sum2:\t")
	x
end

@time println(sum2(10^8))

"""

"""