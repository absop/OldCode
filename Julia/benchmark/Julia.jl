# Int
sum1 = function (n::Int)
	x = 0
	for i in 1:n
		x += i % n
	end
	print("sum1:\t")
	x
end
sum2 = function (n::Int)
	x = 0
	for i in 1:n
		x += i % 1000000000
	end
	print("sum2:\t")
	x
end
sum3 = function (n::Int)
	x = 0
	for i in 1:1000000000
		x += i % 1000000000
	end
	print("sum3:\t")
	x
end

# Float64
sum4 = function (n::Float64)
	x = 0
	for i in 1:n
		x += i % n
	end
	print("sum4:\t")
	x
end
sum5 = function (n::Float64)
	x = 0
	for i in 1:n
		x += i % 1000000000.0
	end
	print("sum5:\t")
	x
end
sum6 = function (n::Float64)
	x = 0
	for i in 1:1000000000.0
		x += i % 1000000000.0
	end
	print("sum6:\t")
	x
end

@time println(sum1(10^9))
@time println(sum2(10^9))
@time println(sum3(10^9))
@time println(sum4(1E9))
@time println(sum5(1E9))
@time println(sum6(1E9))

"""
sum1:   499999999500000000
  3.867677 seconds (55.81 k allocations: 2.900 MiB)

sum2:   499999999500000000
  1.626697 seconds (13.74 k allocations: 732.442 KiB)

sum3:   499999999500000000
  0.167452 seconds (13.08 k allocations: 716.390 KiB)

sum4:   4.99999999067109e17
  8.933762 seconds (574.15 k allocations: 29.158 MiB)

sum5:   4.99999999067109e17
  8.559360 seconds (27.20 k allocations: 1.374 MiB)

sum6:   4.99999999067109e17
  8.606460 seconds (164.29 k allocations: 8.995 MiB, 0.07% gc time)

"""