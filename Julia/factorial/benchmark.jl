
function accuracy_test(maxn::Int64)
    for i in 1:maxn
        if !(vectorMul(1:i) == prod(1:big(i)) == factorial(i))
            println("error in $i")
        end
    end
end


accuracy_test(1000)
# foreach(x->println("$x:\t=>\t$(factorial(x))"), 1:81)


using BenchmarkTools


@time fac = factorial(10^7)
println(ceil(Int, log10(fac)))

# @btime s = factorial(10^7)
