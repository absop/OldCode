include("vector.jl")


function factorial(maxn::Int64)
    # 记录maxn之内素数p作为最基本的素因子出现的次数
    # 若maxn为10，则ptimes(2)得8，ptimes(3)得4
    function ptimes(prime::Int64)
        cnt = temp = fld(maxn, prime)
        while temp >= prime
            cnt += temp = fld(temp, prime)
        end
        return cnt
    end

    isprimes = trues(maxn)
    primes, exps = BigInt[], Int64[]
    half, sqr = maxn >> 1, isqrt(maxn)

    @inbounds for i = 3:2:sqr
        if isprimes[i]
            push!(primes, i)
            push!(exps,  ptimes(i))
            @inbounds for j = i^2:2i:maxn
                isprimes[j] = false
            end
        end
    end
    @inbounds for i in sqr+2-iseven(sqr):2:half
        if isprimes[i]
            push!(primes, i)
            push!(exps, fld(maxn, i))
        end
    end
    @inbounds for i in half+2-iseven(half):2:maxn
        if isprimes[i]
            push!(primes, i)
            push!(exps, 1)
        end
    end
    # println(primes)
    # println(exps)
    # @time result = vectorPowMul(primes, exps)
    result = vectorPowMul(primes, exps)
    result <<= ptimes(2)
    return result
end


include("benchmark.jl")

#=
  6.060979 seconds (4.88 M allocations: 921.815 MiB, 7.52% gc time)
65657060
[Finished in 10.0s]
=#
