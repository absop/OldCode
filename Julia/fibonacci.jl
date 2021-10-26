
function fibonacci1(n::Int)
	x, y = big(1), big(0)
	for i = ndigits(n, base=2)-1:-1:1
		xx, yy = x^2, y^2
		xy = (x + y)^2
		if isodd(n>>i)
			x = xy - xx
			y = xy + yy
        else
			y = xy - xx
			x = yy + xx
        end
	end
	xy = (x + y)^2
	if isodd(n)
        xy + y^2
    else
	    xy - x^2
	end
end


function fibonacci2(n::Int)
    if n < 2 return big(n) end

    x, y = big(0), big(1)
    for i = ndigits(n, base=2)-2:-1:1
        m = n >> i
        k = m >> 1
        g = isodd(k) ? -2 : 2

        xx = x^2
        yy = y^2
        xy = xx + yy
        yx = (yy << 2) - xx + g
        if isodd(m)
            x, y = yx - xy, yx
        else
            x, y = xy, yx - xy
        end
    end

    k = n >> 1
    g = isodd(k) ? -2 : 2

    xx = x^2
    yy = y^2
    xy = (yy << 2) - xx + g
    if !isodd(n)
        xy -= xx + yy
    end
    xy
end


function fibonacci3(n::Int)
    if n < 2 return big(n) end

    x, y = big(1), big(1)

    for i = ndigits(n, base=2)-1:-1:1
        if isodd(n>>i)
            x = y - x
        else
            y = y - x
        end

        g = isodd(n>>i) ? -2 : 2

        xx = x^2
        yy = y^2
        x = xx + yy
        y = yy * 4 - xx + g
    end

    if !isodd(n)
        y = y - x
    end
    y
end

# foreach(x->println(x, "\t=>\t", fibonacci1(x)), 0:20)


using BenchmarkTools
using Combinatorics


@time fib0 = fibonaccinum(10000000)
@time fib1 = fibonacci1(10000000)
@time fib2 = fibonacci2(10000000)
@time fib3 = fibonacci3(10000000)
@assert fib0 == fib1
@assert fib0 == fib2
@assert fib0 == fib3

println()
@time fib0 = fibonaccinum(100000000)
@time fib1 = fibonacci1(100000000)
@time fib2 = fibonacci2(100000000)
@time fib3 = fibonacci3(100000000)
@assert fib0 == fib1
@assert fib0 == fib2
@assert fib0 == fib3

println()
@time fib0 = fibonaccinum(100000001)
@time fib1 = fibonacci1(100000001)
@time fib2 = fibonacci2(100000001)
@time fib3 = fibonacci3(100000001)
@assert fib0 == fib1
@assert fib0 == fib2
@assert fib0 == fib3

len = ceil(Int, log10(fib1))
println(len)
