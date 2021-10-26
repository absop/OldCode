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
    small, middle = BigInt[], BigInt[]
    tsmall , tmiddle = Int64[], Int64[]
    large = BigInt[]
    half, sqr = maxn >> 1, isqrt(maxn)

    @inbounds for i = 3:2:sqr
        if isprimes[i]
            push!(small, i)
            push!(tsmall,  ptimes(i))
            @inbounds for j = i^2:2i:maxn
                isprimes[j] = false
            end
        end
    end
    @inbounds for i in sqr+2-iseven(sqr):2:half
        if isprimes[i]
            push!(middle, i)
            push!(tmiddle, fld(maxn, i))
        end
    end
    @inbounds for i in half+2-iseven(half):2:maxn
        if isprimes[i]
            push!(large, i)
        end
    end
    # println(small, tsmall)
    # println(middle, tmiddle)
    # println(large)
    result = vectorPowMul(small, tsmall)
    # @time result = vectorPowMul(small, tsmall)
    result *= vectorPowMul(middle, tmiddle)
    result *= vectorMul(large)
    result <<= ptimes(2)
    return result
end


include("benchmark.jl")

#=
  7.476875 seconds (4.89 M allocations: 1.137 GiB, 7.60% gc time)
65657060
[Finished in 11.6s]
=#
