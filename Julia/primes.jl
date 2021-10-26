
# 埃拉托色尼筛
function myPrimes(maxn::Int)
    primes = [2]
    isprimes = trues(maxn)
    @inbounds for i = 3:2:isqrt(maxn)
        if isprimes[i]
            push!(primes, i)
            @inbounds for j = i^2:2i:maxn
                isprimes[j] = false
            end
        end
    end
    @inbounds for i in primes[end]+2:2:maxn
        if isprimes[i]
            push!(primes, i)
        end
    end; primes
end

# 欧拉筛
function eulerPrimes(maxn::Int64)
    primes = [2]
    isprimes = trues(maxn)
    for i = 3:2:maxn
        isprimes[i] && push!(primes, i)
        for j = 2:length(primes)
            prime = primes[j]
            k = i * prime
            k > maxn && break
            isprimes[k] = false
            i % prime == 0 && break
        end
    end; primes
end


# 埃拉托色尼筛，内存省了一半
function Primes(maxn::Int64)
    half = cld(maxn, 2)
    marks = trues(half)
    for i = 3:2:isqrt(maxn)
        if marks[div(i + 1, 2)]
            for j = div(i^2 + 1, 2):i:half
                marks[j] = false
            end
        end
    end
    primes = (1:half)[marks]
    primes .*= 2
    primes .-= 1
    primes[1] = 2
    return primes
end


##################################################

# using BenchmarkTools


# println(Primes(1000))
# println(myPrimes(100))
# println(eulerPrimes(100))


# @time primes1 = Primes(10^8)
# @time primes2 = myPrimes(10^8)
# @time primes3 = eulerPrimes(10^8)

# if primes1 == primes2 == primes3
#     println("All function is right!")
# else
#     println("Some function is false!")
# end

# @btime Primes(10^8)
# @btime myPrimes(10^8)
# @btime eulerPrimes(10^8)
