

function eulerζ(s, maxn::Int64)
    half = cld(maxn, 2)
    primes = trues(half)
    for i = 3:2:isqrt(maxn)
        if primes[div(i + 1, 2)]
            for j = div(i^2 + 1, 2):i:half
                primes[j] = false
            end
        end
    end
    primes = (1:half)[primes]
    primes .*= 2
    primes .-= 1
    primes[1] = 2
    primes .^= s

    ps = Vector{Float64}(undef, length(primes))
    ps .= primes ./ (primes .- 1)
    return prod(ps)
end


function ζ(s, maxn::Int64)
    sumer = 0
    for i in 1:maxn
        sumer += 1.0 / i^s
    end
    return sumer
end


const maxn = 10^8
@time y = eulerζ(2, maxn)
println(y)

@time y = ζ(2, maxn)
println(y)
